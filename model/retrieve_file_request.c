#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "retrieve_file_request.h"



retrieve_file_request_t *retrieve_file_request_create(
    char *id,
    char *save_path
    ) {
    retrieve_file_request_t *retrieve_file_request_local_var = malloc(sizeof(retrieve_file_request_t));
    if (!retrieve_file_request_local_var) {
        return NULL;
    }
    retrieve_file_request_local_var->id = id;
    retrieve_file_request_local_var->save_path = save_path;

    return retrieve_file_request_local_var;
}


void retrieve_file_request_free(retrieve_file_request_t *retrieve_file_request) {
    if(NULL == retrieve_file_request){
        return ;
    }
    listEntry_t *listEntry;
    free(retrieve_file_request->id);
    free(retrieve_file_request->save_path);
    free(retrieve_file_request);
}

cJSON *retrieve_file_request_convertToJSON(retrieve_file_request_t *retrieve_file_request) {
    cJSON *item = cJSON_CreateObject();

    // retrieve_file_request->id
    if (!retrieve_file_request->id) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "id", retrieve_file_request->id) == NULL) {
    goto fail; //String
    }


    // retrieve_file_request->save_path
    if (!retrieve_file_request->save_path) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "save_path", retrieve_file_request->save_path) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

retrieve_file_request_t *retrieve_file_request_parseFromJSON(cJSON *retrieve_file_requestJSON){

    retrieve_file_request_t *retrieve_file_request_local_var = NULL;

    // retrieve_file_request->id
    cJSON *id = cJSON_GetObjectItemCaseSensitive(retrieve_file_requestJSON, "id");
    if (!id) {
        goto end;
    }

    
    if(!cJSON_IsString(id))
    {
    goto end; //String
    }

    // retrieve_file_request->save_path
    cJSON *save_path = cJSON_GetObjectItemCaseSensitive(retrieve_file_requestJSON, "save_path");
    if (!save_path) {
        goto end;
    }

    
    if(!cJSON_IsString(save_path))
    {
    goto end; //String
    }


    retrieve_file_request_local_var = retrieve_file_request_create (
        strdup(id->valuestring),
        strdup(save_path->valuestring)
        );

    return retrieve_file_request_local_var;
end:
    return NULL;

}
