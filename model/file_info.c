#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "file_info.h"



file_info_t *file_info_create(
    char *id,
    char *path,
    long size,
    long modified,
    long created,
    char *crc32,
    list_t* extra,
    delivery_hints_t *delivery_hints
    ) {
    file_info_t *file_info_local_var = malloc(sizeof(file_info_t));
    if (!file_info_local_var) {
        return NULL;
    }
    file_info_local_var->id = id;
    file_info_local_var->path = path;
    file_info_local_var->size = size;
    file_info_local_var->modified = modified;
    file_info_local_var->created = created;
    file_info_local_var->crc32 = crc32;
    file_info_local_var->extra = extra;
    file_info_local_var->delivery_hints = delivery_hints;

    return file_info_local_var;
}


void file_info_free(file_info_t *file_info) {
    if(NULL == file_info){
        return ;
    }
    listEntry_t *listEntry;
    if (file_info->id) {
        free(file_info->id);
        file_info->id = NULL;
    }
    if (file_info->path) {
        free(file_info->path);
        file_info->path = NULL;
    }
    if (file_info->crc32) {
        free(file_info->crc32);
        file_info->crc32 = NULL;
    }
    if (file_info->extra) {
        list_ForEach(listEntry, file_info->extra) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(file_info->extra);
        file_info->extra = NULL;
    }
    if (file_info->delivery_hints) {
        delivery_hints_free(file_info->delivery_hints);
        file_info->delivery_hints = NULL;
    }
    free(file_info);
}

cJSON *file_info_convertToJSON(file_info_t *file_info) {
    cJSON *item = cJSON_CreateObject();

    // file_info->id
    if (!file_info->id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "id", file_info->id) == NULL) {
    goto fail; //String
    }


    // file_info->path
    if (!file_info->path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "path", file_info->path) == NULL) {
    goto fail; //String
    }


    // file_info->size
    if (!file_info->size) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "size", file_info->size) == NULL) {
    goto fail; //Numeric
    }


    // file_info->modified
    if (!file_info->modified) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "modified", file_info->modified) == NULL) {
    goto fail; //Numeric
    }


    // file_info->created
    if (!file_info->created) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "created", file_info->created) == NULL) {
    goto fail; //Numeric
    }


    // file_info->crc32
    if (!file_info->crc32) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "crc32", file_info->crc32) == NULL) {
    goto fail; //String
    }


    // file_info->extra
    if(file_info->extra) {
    cJSON *extra = cJSON_AddObjectToObject(item, "extra");
    if(extra == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = extra;
    listEntry_t *extraListEntry;
    if (file_info->extra) {
    list_ForEach(extraListEntry, file_info->extra) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)extraListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // file_info->delivery_hints
    if(file_info->delivery_hints) {
    cJSON *delivery_hints_local_JSON = delivery_hints_convertToJSON(file_info->delivery_hints);
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

file_info_t *file_info_parseFromJSON(cJSON *file_infoJSON){

    file_info_t *file_info_local_var = NULL;

    // define the local map for file_info->extra
    list_t *extraList = NULL;

    // define the local variable for file_info->delivery_hints
    delivery_hints_t *delivery_hints_local_nonprim = NULL;

    // file_info->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(file_infoJSON, "id");
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // file_info->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(file_infoJSON, "path");
    if (!path) {
        goto end;
    }

    
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }

    // file_info->size
    cJSON *size = cJSON_GetObjectItemCaseSensitive(file_infoJSON, "size");
    if (!size) {
        goto end;
    }

    
    if(!cJSON_IsNumber(size))
    {
    goto end; //Numeric
    }

    // file_info->modified
    cJSON *modified = cJSON_GetObjectItemCaseSensitive(file_infoJSON, "modified");
    if (!modified) {
        goto end;
    }

    
    if(!cJSON_IsNumber(modified))
    {
    goto end; //Numeric
    }

    // file_info->created
    cJSON *created = cJSON_GetObjectItemCaseSensitive(file_infoJSON, "created");
    if (!created) {
        goto end;
    }

    
    if(!cJSON_IsNumber(created))
    {
    goto end; //Numeric
    }

    // file_info->crc32
    cJSON *crc32 = cJSON_GetObjectItemCaseSensitive(file_infoJSON, "crc32");
    if (!crc32) {
        goto end;
    }

    
    if(!cJSON_IsString(crc32))
    {
    goto end; //String
    }

    // file_info->extra
    cJSON *extra = cJSON_GetObjectItemCaseSensitive(file_infoJSON, "extra");
    if (extra) { 
    cJSON *extra_local_map = NULL;
    if(!cJSON_IsObject(extra) && !cJSON_IsNull(extra))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(extra))
    {
        extraList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(extra_local_map, extra)
        {
            cJSON *localMapObject = extra_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(extraList , localMapKeyPair);
        }
    }
    }

    // file_info->delivery_hints
    cJSON *delivery_hints = cJSON_GetObjectItemCaseSensitive(file_infoJSON, "delivery_hints");
    if (delivery_hints) { 
    delivery_hints_local_nonprim = delivery_hints_parseFromJSON(delivery_hints); //custom
    }


    file_info_local_var = file_info_create (
        strdup(id->valuestring),
        strdup(path->valuestring),
        size->valuedouble,
        modified->valuedouble,
        created->valuedouble,
        strdup(crc32->valuestring),
        extra ? extraList : NULL,
        delivery_hints ? delivery_hints_local_nonprim : NULL
        );

    return file_info_local_var;
end:
    if (extraList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, extraList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(extraList);
        extraList = NULL;
    }
    if (delivery_hints_local_nonprim) {
        delivery_hints_free(delivery_hints_local_nonprim);
        delivery_hints_local_nonprim = NULL;
    }
    return NULL;

}
