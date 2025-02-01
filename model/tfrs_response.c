#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tfrs_response.h"



tfrs_response_t *tfrs_response_create(
    double age,
    int utc_time,
    double ecef_pos_x,
    double ecef_pos_y,
    double ecef_pos_z,
    double ecef_vel_x,
    double ecef_vel_y,
    double ecef_vel_z
    ) {
    tfrs_response_t *tfrs_response_local_var = malloc(sizeof(tfrs_response_t));
    if (!tfrs_response_local_var) {
        return NULL;
    }
    tfrs_response_local_var->age = age;
    tfrs_response_local_var->utc_time = utc_time;
    tfrs_response_local_var->ecef_pos_x = ecef_pos_x;
    tfrs_response_local_var->ecef_pos_y = ecef_pos_y;
    tfrs_response_local_var->ecef_pos_z = ecef_pos_z;
    tfrs_response_local_var->ecef_vel_x = ecef_vel_x;
    tfrs_response_local_var->ecef_vel_y = ecef_vel_y;
    tfrs_response_local_var->ecef_vel_z = ecef_vel_z;

    return tfrs_response_local_var;
}


void tfrs_response_free(tfrs_response_t *tfrs_response) {
    if(NULL == tfrs_response){
        return ;
    }
    listEntry_t *listEntry;
    free(tfrs_response);
}

cJSON *tfrs_response_convertToJSON(tfrs_response_t *tfrs_response) {
    cJSON *item = cJSON_CreateObject();

    // tfrs_response->age
    if (!tfrs_response->age) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "age", tfrs_response->age) == NULL) {
    goto fail; //Numeric
    }


    // tfrs_response->utc_time
    if (!tfrs_response->utc_time) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "utc_time", tfrs_response->utc_time) == NULL) {
    goto fail; //Numeric
    }


    // tfrs_response->ecef_pos_x
    if (!tfrs_response->ecef_pos_x) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "ecef_pos_x", tfrs_response->ecef_pos_x) == NULL) {
    goto fail; //Numeric
    }


    // tfrs_response->ecef_pos_y
    if (!tfrs_response->ecef_pos_y) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "ecef_pos_y", tfrs_response->ecef_pos_y) == NULL) {
    goto fail; //Numeric
    }


    // tfrs_response->ecef_pos_z
    if (!tfrs_response->ecef_pos_z) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "ecef_pos_z", tfrs_response->ecef_pos_z) == NULL) {
    goto fail; //Numeric
    }


    // tfrs_response->ecef_vel_x
    if (!tfrs_response->ecef_vel_x) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "ecef_vel_x", tfrs_response->ecef_vel_x) == NULL) {
    goto fail; //Numeric
    }


    // tfrs_response->ecef_vel_y
    if (!tfrs_response->ecef_vel_y) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "ecef_vel_y", tfrs_response->ecef_vel_y) == NULL) {
    goto fail; //Numeric
    }


    // tfrs_response->ecef_vel_z
    if (!tfrs_response->ecef_vel_z) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "ecef_vel_z", tfrs_response->ecef_vel_z) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

tfrs_response_t *tfrs_response_parseFromJSON(cJSON *tfrs_responseJSON){

    tfrs_response_t *tfrs_response_local_var = NULL;

    // tfrs_response->age
    cJSON *age = cJSON_GetObjectItemCaseSensitive(tfrs_responseJSON, "age");
    if (!age) {
        goto end;
    }

    
    if(!cJSON_IsNumber(age))
    {
    goto end; //Numeric
    }

    // tfrs_response->utc_time
    cJSON *utc_time = cJSON_GetObjectItemCaseSensitive(tfrs_responseJSON, "utc_time");
    if (!utc_time) {
        goto end;
    }

    
    if(!cJSON_IsNumber(utc_time))
    {
    goto end; //Numeric
    }

    // tfrs_response->ecef_pos_x
    cJSON *ecef_pos_x = cJSON_GetObjectItemCaseSensitive(tfrs_responseJSON, "ecef_pos_x");
    if (!ecef_pos_x) {
        goto end;
    }

    
    if(!cJSON_IsNumber(ecef_pos_x))
    {
    goto end; //Numeric
    }

    // tfrs_response->ecef_pos_y
    cJSON *ecef_pos_y = cJSON_GetObjectItemCaseSensitive(tfrs_responseJSON, "ecef_pos_y");
    if (!ecef_pos_y) {
        goto end;
    }

    
    if(!cJSON_IsNumber(ecef_pos_y))
    {
    goto end; //Numeric
    }

    // tfrs_response->ecef_pos_z
    cJSON *ecef_pos_z = cJSON_GetObjectItemCaseSensitive(tfrs_responseJSON, "ecef_pos_z");
    if (!ecef_pos_z) {
        goto end;
    }

    
    if(!cJSON_IsNumber(ecef_pos_z))
    {
    goto end; //Numeric
    }

    // tfrs_response->ecef_vel_x
    cJSON *ecef_vel_x = cJSON_GetObjectItemCaseSensitive(tfrs_responseJSON, "ecef_vel_x");
    if (!ecef_vel_x) {
        goto end;
    }

    
    if(!cJSON_IsNumber(ecef_vel_x))
    {
    goto end; //Numeric
    }

    // tfrs_response->ecef_vel_y
    cJSON *ecef_vel_y = cJSON_GetObjectItemCaseSensitive(tfrs_responseJSON, "ecef_vel_y");
    if (!ecef_vel_y) {
        goto end;
    }

    
    if(!cJSON_IsNumber(ecef_vel_y))
    {
    goto end; //Numeric
    }

    // tfrs_response->ecef_vel_z
    cJSON *ecef_vel_z = cJSON_GetObjectItemCaseSensitive(tfrs_responseJSON, "ecef_vel_z");
    if (!ecef_vel_z) {
        goto end;
    }

    
    if(!cJSON_IsNumber(ecef_vel_z))
    {
    goto end; //Numeric
    }


    tfrs_response_local_var = tfrs_response_create (
        age->valuedouble,
        utc_time->valuedouble,
        ecef_pos_x->valuedouble,
        ecef_pos_y->valuedouble,
        ecef_pos_z->valuedouble,
        ecef_vel_x->valuedouble,
        ecef_vel_y->valuedouble,
        ecef_vel_z->valuedouble
        );

    return tfrs_response_local_var;
end:
    return NULL;

}
