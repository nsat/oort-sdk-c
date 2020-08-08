#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "error_response.h"



error_response_t *error_response_create(
    int status,
    char *message
    ) {
    error_response_t *error_response_local_var = malloc(sizeof(error_response_t));
    if (!error_response_local_var) {
        return NULL;
    }
    error_response_local_var->status = status;
    error_response_local_var->message = message;

    return error_response_local_var;
}


void error_response_free(error_response_t *error_response) {
    listEntry_t *listEntry;
    free(error_response->message);
    free(error_response);
}

cJSON *error_response_convertToJSON(error_response_t *error_response) {
    cJSON *item = cJSON_CreateObject();

    // error_response->status
    if (!error_response->status) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "status", error_response->status) == NULL) {
    goto fail; //Numeric
    }


    // error_response->message
    if (!error_response->message) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "message", error_response->message) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

error_response_t *error_response_parseFromJSON(cJSON *error_responseJSON){

    error_response_t *error_response_local_var = NULL;

    // error_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(error_responseJSON, "status");
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsNumber(status))
    {
    goto end; //Numeric
    }

    // error_response->message
    cJSON *message = cJSON_GetObjectItemCaseSensitive(error_responseJSON, "message");
    if (!message) {
        goto end;
    }

    
    if(!cJSON_IsString(message))
    {
    goto end; //String
    }


    error_response_local_var = error_response_create (
        status->valuedouble,
        strdup(message->valuestring)
        );

    return error_response_local_var;
end:
    return NULL;

}
