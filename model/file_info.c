#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "file_info.h"



file_info_t *file_info_create(
    char *id,
    char *path,
    int size,
    int modified,
    int created,
    char *crc32,
    list_t* extra
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

    return file_info_local_var;
}


void file_info_free(file_info_t *file_info) {
    if(NULL == file_info){
        return ;
    }
    listEntry_t *listEntry;
    free(file_info->id);
    free(file_info->path);
    free(file_info->crc32);
    list_ForEach(listEntry, file_info->extra) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
        free (localKeyValue->key);
        free (localKeyValue->value);
    }
    list_free(file_info->extra);
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
    cJSON *localMapObject = cJSON_CreateObject(); //Memory free to be implemented in user code
    listEntry_t *extraListEntry;
    if (file_info->extra) {
    list_ForEach(extraListEntry, file_info->extra) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)extraListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
        cJSON_AddItemToObject(extra,"", localMapObject);
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

file_info_t *file_info_parseFromJSON(cJSON *file_infoJSON){

    file_info_t *file_info_local_var = NULL;

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
    list_t *extraList;
    if (extra) { 
    cJSON *extra_local_map;
    if(!cJSON_IsObject(extra)) {
        goto end;//primitive map container
    }
    extraList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(extra_local_map, extra)
    {
        if(!cJSON_IsNumber(extra_local_map))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(extra_local_map->string),&extra_local_map->valuedouble );
        list_addElement(extraList , localMapKeyPair);
    }
    }


    file_info_local_var = file_info_create (
        strdup(id->valuestring),
        strdup(path->valuestring),
        size->valuedouble,
        modified->valuedouble,
        created->valuedouble,
        strdup(crc32->valuestring),
        extra ? extraList : NULL
        );

    return file_info_local_var;
end:
    return NULL;

}
