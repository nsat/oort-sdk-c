#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "send_file_request.h"



send_file_request_t *send_file_request_create(
    char *destination,
    char *filepath,
    char *topic,
    send_options_t *options
    ) {
    send_file_request_t *send_file_request_local_var = malloc(sizeof(send_file_request_t));
    if (!send_file_request_local_var) {
        return NULL;
    }
    send_file_request_local_var->destination = destination;
    send_file_request_local_var->filepath = filepath;
    send_file_request_local_var->topic = topic;
    send_file_request_local_var->options = options;

    return send_file_request_local_var;
}


void send_file_request_free(send_file_request_t *send_file_request) {
    if(NULL == send_file_request){
        return ;
    }
    listEntry_t *listEntry;
    free(send_file_request->destination);
    free(send_file_request->filepath);
    free(send_file_request->topic);
    send_options_free(send_file_request->options);
    free(send_file_request);
}

cJSON *send_file_request_convertToJSON(send_file_request_t *send_file_request) {
    cJSON *item = cJSON_CreateObject();

    // send_file_request->destination
    if (!send_file_request->destination) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "destination", send_file_request->destination) == NULL) {
    goto fail; //String
    }


    // send_file_request->filepath
    if (!send_file_request->filepath) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "filepath", send_file_request->filepath) == NULL) {
    goto fail; //String
    }


    // send_file_request->topic
    if (!send_file_request->topic) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "topic", send_file_request->topic) == NULL) {
    goto fail; //String
    }


    // send_file_request->options
    if(send_file_request->options) { 
    cJSON *options_local_JSON = send_options_convertToJSON(send_file_request->options);
    if(options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "options", options_local_JSON);
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

send_file_request_t *send_file_request_parseFromJSON(cJSON *send_file_requestJSON){

    send_file_request_t *send_file_request_local_var = NULL;

    // send_file_request->destination
    cJSON *destination = cJSON_GetObjectItemCaseSensitive(send_file_requestJSON, "destination");
    if (!destination) {
        goto end;
    }

    
    if(!cJSON_IsString(destination))
    {
    goto end; //String
    }

    // send_file_request->filepath
    cJSON *filepath = cJSON_GetObjectItemCaseSensitive(send_file_requestJSON, "filepath");
    if (!filepath) {
        goto end;
    }

    
    if(!cJSON_IsString(filepath))
    {
    goto end; //String
    }

    // send_file_request->topic
    cJSON *topic = cJSON_GetObjectItemCaseSensitive(send_file_requestJSON, "topic");
    if (!topic) {
        goto end;
    }

    
    if(!cJSON_IsString(topic))
    {
    goto end; //String
    }

    // send_file_request->options
    cJSON *options = cJSON_GetObjectItemCaseSensitive(send_file_requestJSON, "options");
    send_options_t *options_local_nonprim = NULL;
    if (options) { 
    options_local_nonprim = send_options_parseFromJSON(options); //nonprimitive
    }


    send_file_request_local_var = send_file_request_create (
        strdup(destination->valuestring),
        strdup(filepath->valuestring),
        strdup(topic->valuestring),
        options ? options_local_nonprim : NULL
        );

    return send_file_request_local_var;
end:
    return NULL;

}
