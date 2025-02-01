#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "adcs_euler_t.h"



adcs_euler_t_t *adcs_euler_t_create(
    double roll,
    double pitch,
    double yaw
    ) {
    adcs_euler_t_t *adcs_euler_t_local_var = malloc(sizeof(adcs_euler_t_t));
    if (!adcs_euler_t_local_var) {
        return NULL;
    }
    adcs_euler_t_local_var->roll = roll;
    adcs_euler_t_local_var->pitch = pitch;
    adcs_euler_t_local_var->yaw = yaw;

    return adcs_euler_t_local_var;
}


void adcs_euler_t_free(adcs_euler_t_t *adcs_euler_t) {
    if(NULL == adcs_euler_t){
        return ;
    }
    listEntry_t *listEntry;
    free(adcs_euler_t);
}

cJSON *adcs_euler_t_convertToJSON(adcs_euler_t_t *adcs_euler_t) {
    cJSON *item = cJSON_CreateObject();

    // adcs_euler_t->roll
    if (!adcs_euler_t->roll) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "roll", adcs_euler_t->roll) == NULL) {
    goto fail; //Numeric
    }


    // adcs_euler_t->pitch
    if (!adcs_euler_t->pitch) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "pitch", adcs_euler_t->pitch) == NULL) {
    goto fail; //Numeric
    }


    // adcs_euler_t->yaw
    if (!adcs_euler_t->yaw) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "yaw", adcs_euler_t->yaw) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

adcs_euler_t_t *adcs_euler_t_parseFromJSON(cJSON *adcs_euler_tJSON){

    adcs_euler_t_t *adcs_euler_t_local_var = NULL;

    // adcs_euler_t->roll
    cJSON *roll = cJSON_GetObjectItemCaseSensitive(adcs_euler_tJSON, "roll");
    if (!roll) {
        goto end;
    }

    
    if(!cJSON_IsNumber(roll))
    {
    goto end; //Numeric
    }

    // adcs_euler_t->pitch
    cJSON *pitch = cJSON_GetObjectItemCaseSensitive(adcs_euler_tJSON, "pitch");
    if (!pitch) {
        goto end;
    }

    
    if(!cJSON_IsNumber(pitch))
    {
    goto end; //Numeric
    }

    // adcs_euler_t->yaw
    cJSON *yaw = cJSON_GetObjectItemCaseSensitive(adcs_euler_tJSON, "yaw");
    if (!yaw) {
        goto end;
    }

    
    if(!cJSON_IsNumber(yaw))
    {
    goto end; //Numeric
    }


    adcs_euler_t_local_var = adcs_euler_t_create (
        roll->valuedouble,
        pitch->valuedouble,
        yaw->valuedouble
        );

    return adcs_euler_t_local_var;
end:
    return NULL;

}
