#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "adcs_target.h"



adcs_target_t *adcs_target_create(
    double lat,
    double lon
    ) {
    adcs_target_t *adcs_target_local_var = malloc(sizeof(adcs_target_t));
    if (!adcs_target_local_var) {
        return NULL;
    }
    adcs_target_local_var->lat = lat;
    adcs_target_local_var->lon = lon;

    return adcs_target_local_var;
}


void adcs_target_free(adcs_target_t *adcs_target) {
    if(NULL == adcs_target){
        return ;
    }
    listEntry_t *listEntry;
    free(adcs_target);
}

cJSON *adcs_target_convertToJSON(adcs_target_t *adcs_target) {
    cJSON *item = cJSON_CreateObject();

    // adcs_target->lat
    if (!adcs_target->lat) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "lat", adcs_target->lat) == NULL) {
    goto fail; //Numeric
    }


    // adcs_target->lon
    if (!adcs_target->lon) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "lon", adcs_target->lon) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

adcs_target_t *adcs_target_parseFromJSON(cJSON *adcs_targetJSON){

    adcs_target_t *adcs_target_local_var = NULL;

    // adcs_target->lat
    cJSON *lat = cJSON_GetObjectItemCaseSensitive(adcs_targetJSON, "lat");
    if (!lat) {
        goto end;
    }

    
    if(!cJSON_IsNumber(lat))
    {
    goto end; //Numeric
    }

    // adcs_target->lon
    cJSON *lon = cJSON_GetObjectItemCaseSensitive(adcs_targetJSON, "lon");
    if (!lon) {
        goto end;
    }

    
    if(!cJSON_IsNumber(lon))
    {
    goto end; //Numeric
    }


    adcs_target_local_var = adcs_target_create (
        lat->valuedouble,
        lon->valuedouble
        );

    return adcs_target_local_var;
end:
    return NULL;

}
