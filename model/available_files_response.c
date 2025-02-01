#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "available_files_response.h"



available_files_response_t *available_files_response_create(
    list_t *files,
    int overflow
    ) {
    available_files_response_t *available_files_response_local_var = malloc(sizeof(available_files_response_t));
    if (!available_files_response_local_var) {
        return NULL;
    }
    available_files_response_local_var->files = files;
    available_files_response_local_var->overflow = overflow;

    return available_files_response_local_var;
}


void available_files_response_free(available_files_response_t *available_files_response) {
    if(NULL == available_files_response){
        return ;
    }
    listEntry_t *listEntry;
    if (available_files_response->files) {
        list_ForEach(listEntry, available_files_response->files) {
            file_info_free(listEntry->data);
        }
        list_freeList(available_files_response->files);
        available_files_response->files = NULL;
    }
    free(available_files_response);
}

cJSON *available_files_response_convertToJSON(available_files_response_t *available_files_response) {
    cJSON *item = cJSON_CreateObject();

    // available_files_response->files
    if (!available_files_response->files) {
        goto fail;
    }
    cJSON *files = cJSON_AddArrayToObject(item, "files");
    if(files == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *filesListEntry;
    if (available_files_response->files) {
    list_ForEach(filesListEntry, available_files_response->files) {
    cJSON *itemLocal = file_info_convertToJSON(filesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(files, itemLocal);
    }
    }


    // available_files_response->overflow
    if(available_files_response->overflow) {
    if(cJSON_AddBoolToObject(item, "overflow", available_files_response->overflow) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

available_files_response_t *available_files_response_parseFromJSON(cJSON *available_files_responseJSON){

    available_files_response_t *available_files_response_local_var = NULL;

    // define the local list for available_files_response->files
    list_t *filesList = NULL;

    // available_files_response->files
    cJSON *files = cJSON_GetObjectItemCaseSensitive(available_files_responseJSON, "files");
    if (!files) {
        goto end;
    }

    
    cJSON *files_local_nonprimitive = NULL;
    if(!cJSON_IsArray(files)){
        goto end; //nonprimitive container
    }

    filesList = list_createList();

    cJSON_ArrayForEach(files_local_nonprimitive,files )
    {
        if(!cJSON_IsObject(files_local_nonprimitive)){
            goto end;
        }
        file_info_t *filesItem = file_info_parseFromJSON(files_local_nonprimitive);

        list_addElement(filesList, filesItem);
    }

    // available_files_response->overflow
    cJSON *overflow = cJSON_GetObjectItemCaseSensitive(available_files_responseJSON, "overflow");
    if (overflow) { 
    if(!cJSON_IsBool(overflow))
    {
    goto end; //Bool
    }
    }


    available_files_response_local_var = available_files_response_create (
        filesList,
        overflow ? overflow->valueint : 0
        );

    return available_files_response_local_var;
end:
    if (filesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, filesList) {
            file_info_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(filesList);
        filesList = NULL;
    }
    return NULL;

}
