#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_options.h"



send_options_t *send_options_create(
    ttl_params_t *ttl_params,
    int reliable,
    list_t* tags,
    delivery_hints_t *delivery_hints
    ) {
    send_options_t *send_options_local_var = malloc(sizeof(send_options_t));
    if (!send_options_local_var) {
        return NULL;
    }
    send_options_local_var->ttl_params = ttl_params;
    send_options_local_var->reliable = reliable;
    send_options_local_var->tags = tags;
    send_options_local_var->delivery_hints = delivery_hints;

    return send_options_local_var;
}


void send_options_free(send_options_t *send_options) {
    if(NULL == send_options){
        return ;
    }
    listEntry_t *listEntry;
    if (send_options->ttl_params) {
        ttl_params_free(send_options->ttl_params);
        send_options->ttl_params = NULL;
    }
    if (send_options->tags) {
        list_ForEach(listEntry, send_options->tags) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(send_options->tags);
        send_options->tags = NULL;
    }
    if (send_options->delivery_hints) {
        delivery_hints_free(send_options->delivery_hints);
        send_options->delivery_hints = NULL;
    }
    free(send_options);
}

cJSON *send_options_convertToJSON(send_options_t *send_options) {
    cJSON *item = cJSON_CreateObject();

    // send_options->ttl_params
    if(send_options->ttl_params) {
    cJSON *ttl_params_local_JSON = ttl_params_convertToJSON(send_options->ttl_params);
    if(ttl_params_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "TTLParams", ttl_params_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // send_options->reliable
    if(send_options->reliable) {
    if(cJSON_AddBoolToObject(item, "reliable", send_options->reliable) == NULL) {
    goto fail; //Bool
    }
    }


    // send_options->tags
    if(send_options->tags) {
    cJSON *tags = cJSON_AddObjectToObject(item, "tags");
    if(tags == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = tags;
    listEntry_t *tagsListEntry;
    if (send_options->tags) {
    list_ForEach(tagsListEntry, send_options->tags) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)tagsListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // send_options->delivery_hints
    if(send_options->delivery_hints) {
    cJSON *delivery_hints_local_JSON = delivery_hints_convertToJSON(send_options->delivery_hints);
    if(delivery_hints_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "delivery_hints", delivery_hints_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

send_options_t *send_options_parseFromJSON(cJSON *send_optionsJSON){

    send_options_t *send_options_local_var = NULL;

    // define the local variable for send_options->ttl_params
    ttl_params_t *ttl_params_local_nonprim = NULL;

    // define the local map for send_options->tags
    list_t *tagsList = NULL;

    // define the local variable for send_options->delivery_hints
    delivery_hints_t *delivery_hints_local_nonprim = NULL;

    // send_options->ttl_params
    cJSON *ttl_params = cJSON_GetObjectItemCaseSensitive(send_optionsJSON, "TTLParams");
    if (ttl_params) { 
    ttl_params_local_nonprim = ttl_params_parseFromJSON(ttl_params); //nonprimitive
    }

    // send_options->reliable
    cJSON *reliable = cJSON_GetObjectItemCaseSensitive(send_optionsJSON, "reliable");
    if (reliable) { 
    if(!cJSON_IsBool(reliable))
    {
    goto end; //Bool
    }
    }

    // send_options->tags
    cJSON *tags = cJSON_GetObjectItemCaseSensitive(send_optionsJSON, "tags");
    if (tags) { 
    cJSON *tags_local_map = NULL;
    if(!cJSON_IsObject(tags) && !cJSON_IsNull(tags))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(tags))
    {
        tagsList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(tags_local_map, tags)
        {
            cJSON *localMapObject = tags_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(tagsList , localMapKeyPair);
        }
    }
    }

    // send_options->delivery_hints
    cJSON *delivery_hints = cJSON_GetObjectItemCaseSensitive(send_optionsJSON, "delivery_hints");
    if (delivery_hints) { 
    delivery_hints_local_nonprim = delivery_hints_parseFromJSON(delivery_hints); //custom
    }


    send_options_local_var = send_options_create (
        ttl_params ? ttl_params_local_nonprim : NULL,
        reliable ? reliable->valueint : 0,
        tags ? tagsList : NULL,
        delivery_hints ? delivery_hints_local_nonprim : NULL
        );

    return send_options_local_var;
end:
    if (ttl_params_local_nonprim) {
        ttl_params_free(ttl_params_local_nonprim);
        ttl_params_local_nonprim = NULL;
    }
    if (tagsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, tagsList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(tagsList);
        tagsList = NULL;
    }
    if (delivery_hints_local_nonprim) {
        delivery_hints_free(delivery_hints_local_nonprim);
        delivery_hints_local_nonprim = NULL;
    }
    return NULL;

}
