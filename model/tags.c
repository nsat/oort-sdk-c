#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tags.h"



tags_t *tags_create(
    char *token
    ) {
    tags_t *tags_local_var = malloc(sizeof(tags_t));
    if (!tags_local_var) {
        return NULL;
    }
    tags_local_var->token = token;

    return tags_local_var;
}


void tags_free(tags_t *tags) {
    if(NULL == tags){
        return ;
    }
    listEntry_t *listEntry;
    free(tags->token);
    free(tags);
}

cJSON *tags_convertToJSON(tags_t *tags) {
    cJSON *item = cJSON_CreateObject();

    // tags->token
    if(tags->token) { 
    if(cJSON_AddStringToObject(item, "token", tags->token) == NULL) {
    goto fail; //String
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

tags_t *tags_parseFromJSON(cJSON *tagsJSON){

    tags_t *tags_local_var = NULL;

    // tags->token
    cJSON *token = cJSON_GetObjectItemCaseSensitive(tagsJSON, "token");
    if (token) { 
    if(!cJSON_IsString(token))
    {
    goto end; //String
    }
    }


    tags_local_var = tags_create (
        token ? strdup(token->valuestring) : NULL
        );

    return tags_local_var;
end:
    return NULL;

}
