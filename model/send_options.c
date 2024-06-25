#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_options.h"



send_options_t *send_options_create(
    ttl_params_t *ttl_params,
    int reliable,
    list_t* tags
    ) {
    send_options_t *send_options_local_var = malloc(sizeof(send_options_t));
    if (!send_options_local_var) {
        return NULL;
    }
    send_options_local_var->ttl_params = ttl_params;
    send_options_local_var->reliable = reliable;
    send_options_local_var->tags = tags;

    return send_options_local_var;
}


void send_options_free(send_options_t *send_options) {
    if(NULL == send_options){
        return ;
    }
    listEntry_t *listEntry;
    ttl_params_free(send_options->ttl_params);
    list_ForEach(listEntry, send_options->tags) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
    }
    list_free(send_options->tags);
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
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
    listEntry_t *tagsListEntry;
    if (send_options->tags) {
    list_ForEach(tagsListEntry, send_options->tags) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)tagsListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(tags,"", localMapObject);
    }
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

    // send_options->ttl_params
    cJSON *ttl_params = cJSON_GetObjectItemCaseSensitive(send_optionsJSON, "TTLParams");
    ttl_params_t *ttl_params_local_nonprim = NULL;
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
    list_t *tagsList;
    if (tags) { 
    cJSON *tags_local_map;
    if(!cJSON_IsObject(tags)) {
        goto end;//primitive map container
    }
    tagsList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(tags_local_map, tags)
    {
        if(!cJSON_IsNumber(tags_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(tags_local_map->string),&tags_local_map->valuedouble );
        list_addElement(tagsList , localMapKeyPair);
    }
    }


    send_options_local_var = send_options_create (
        ttl_params ? ttl_params_local_nonprim : NULL,
        reliable ? reliable->valueint : 0,
        tags ? tagsList : NULL
        );

    return send_options_local_var;
end:
    return NULL;

}
