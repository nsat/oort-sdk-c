#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delivery_hints.h"



delivery_hints_t *delivery_hints_create(
    char *dest_path,
    char *mode
    ) {
    delivery_hints_t *delivery_hints_local_var = malloc(sizeof(delivery_hints_t));
    if (!delivery_hints_local_var) {
        return NULL;
    }
    delivery_hints_local_var->dest_path = dest_path;
    delivery_hints_local_var->mode = mode;

    return delivery_hints_local_var;
}


void delivery_hints_free(delivery_hints_t *delivery_hints) {
    if(NULL == delivery_hints){
        return ;
    }
    listEntry_t *listEntry;
    if (delivery_hints->dest_path) {
        free(delivery_hints->dest_path);
        delivery_hints->dest_path = NULL;
    }
    if (delivery_hints->mode) {
        free(delivery_hints->mode);
        delivery_hints->mode = NULL;
    }
    free(delivery_hints);
}

cJSON *delivery_hints_convertToJSON(delivery_hints_t *delivery_hints) {
    cJSON *item = cJSON_CreateObject();

    // delivery_hints->dest_path
    if (!delivery_hints->dest_path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "dest_path", delivery_hints->dest_path) == NULL) {
    goto fail; //String
    }


    // delivery_hints->mode
    if (!delivery_hints->mode) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mode", delivery_hints->mode) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

delivery_hints_t *delivery_hints_parseFromJSON(cJSON *delivery_hintsJSON){

    delivery_hints_t *delivery_hints_local_var = NULL;

    // delivery_hints->dest_path
    cJSON *dest_path = cJSON_GetObjectItemCaseSensitive(delivery_hintsJSON, "dest_path");
    if (!dest_path) {
        goto end;
    }

    
    if(!cJSON_IsString(dest_path))
    {
    goto end; //String
    }

    // delivery_hints->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(delivery_hintsJSON, "mode");
    if (!mode) {
        goto end;
    }

    
    if(!cJSON_IsString(mode))
    {
    goto end; //String
    }


    delivery_hints_local_var = delivery_hints_create (
        strdup(dest_path->valuestring),
        strdup(mode->valuestring)
        );

    return delivery_hints_local_var;
end:
    return NULL;

}
