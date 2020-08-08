#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_file_response.h"



send_file_response_t *send_file_response_create(
    char *uuid
    ) {
    send_file_response_t *send_file_response_local_var = malloc(sizeof(send_file_response_t));
    if (!send_file_response_local_var) {
        return NULL;
    }
    send_file_response_local_var->uuid = uuid;

    return send_file_response_local_var;
}


void send_file_response_free(send_file_response_t *send_file_response) {
    listEntry_t *listEntry;
    free(send_file_response->uuid);
    free(send_file_response);
}

cJSON *send_file_response_convertToJSON(send_file_response_t *send_file_response) {
    cJSON *item = cJSON_CreateObject();

    // send_file_response->uuid
    if (!send_file_response->uuid) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "UUID", send_file_response->uuid) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

send_file_response_t *send_file_response_parseFromJSON(cJSON *send_file_responseJSON){

    send_file_response_t *send_file_response_local_var = NULL;

    // send_file_response->uuid
    cJSON *uuid = cJSON_GetObjectItemCaseSensitive(send_file_responseJSON, "UUID");
    if (!uuid) {
        goto end;
    }

    
    if(!cJSON_IsString(uuid))
    {
    goto end; //String
    }


    send_file_response_local_var = send_file_response_create (
        strdup(uuid->valuestring)
        );

    return send_file_response_local_var;
end:
    return NULL;

}
