#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ttl_params.h"



ttl_params_t *ttl_params_create(
    int urgent,
    int bulk,
    int surplus
    ) {
    ttl_params_t *ttl_params_local_var = malloc(sizeof(ttl_params_t));
    if (!ttl_params_local_var) {
        return NULL;
    }
    ttl_params_local_var->urgent = urgent;
    ttl_params_local_var->bulk = bulk;
    ttl_params_local_var->surplus = surplus;

    return ttl_params_local_var;
}


void ttl_params_free(ttl_params_t *ttl_params) {
    if(NULL == ttl_params){
        return ;
    }
    listEntry_t *listEntry;
    free(ttl_params);
}

cJSON *ttl_params_convertToJSON(ttl_params_t *ttl_params) {
    cJSON *item = cJSON_CreateObject();

    // ttl_params->urgent
    if(ttl_params->urgent) {
    if(cJSON_AddNumberToObject(item, "urgent", ttl_params->urgent) == NULL) {
    goto fail; //Numeric
    }
    }


    // ttl_params->bulk
    if(ttl_params->bulk) {
    if(cJSON_AddNumberToObject(item, "bulk", ttl_params->bulk) == NULL) {
    goto fail; //Numeric
    }
    }


    // ttl_params->surplus
    if(ttl_params->surplus) {
    if(cJSON_AddNumberToObject(item, "surplus", ttl_params->surplus) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ttl_params_t *ttl_params_parseFromJSON(cJSON *ttl_paramsJSON){

    ttl_params_t *ttl_params_local_var = NULL;

    // ttl_params->urgent
    cJSON *urgent = cJSON_GetObjectItemCaseSensitive(ttl_paramsJSON, "urgent");
    if (urgent) { 
    if(!cJSON_IsNumber(urgent))
    {
    goto end; //Numeric
    }
    }

    // ttl_params->bulk
    cJSON *bulk = cJSON_GetObjectItemCaseSensitive(ttl_paramsJSON, "bulk");
    if (bulk) { 
    if(!cJSON_IsNumber(bulk))
    {
    goto end; //Numeric
    }
    }

    // ttl_params->surplus
    cJSON *surplus = cJSON_GetObjectItemCaseSensitive(ttl_paramsJSON, "surplus");
    if (surplus) { 
    if(!cJSON_IsNumber(surplus))
    {
    goto end; //Numeric
    }
    }


    ttl_params_local_var = ttl_params_create (
        urgent ? urgent->valuedouble : 0,
        bulk ? bulk->valuedouble : 0,
        surplus ? surplus->valuedouble : 0
        );

    return ttl_params_local_var;
end:
    return NULL;

}
