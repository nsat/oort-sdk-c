#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "adcs_command_request.h"



adcs_command_request_t *adcs_command_request_create(
    char *command,
    char *aperture,
    adcs_target_t *target,
    double angle,
    adcs_xyz_float_t_t *vector,
    adcs_quat_t_t *quat
    ) {
    adcs_command_request_t *adcs_command_request_local_var = malloc(sizeof(adcs_command_request_t));
    if (!adcs_command_request_local_var) {
        return NULL;
    }
    adcs_command_request_local_var->command = command;
    adcs_command_request_local_var->aperture = aperture;
    adcs_command_request_local_var->target = target;
    adcs_command_request_local_var->angle = angle;
    adcs_command_request_local_var->vector = vector;
    adcs_command_request_local_var->quat = quat;

    return adcs_command_request_local_var;
}


void adcs_command_request_free(adcs_command_request_t *adcs_command_request) {
    if(NULL == adcs_command_request){
        return ;
    }
    listEntry_t *listEntry;
    free(adcs_command_request->command);
    free(adcs_command_request->aperture);
    adcs_target_free(adcs_command_request->target);
    adcs_xyz_float_t_free(adcs_command_request->vector);
    adcs_quat_t_free(adcs_command_request->quat);
    free(adcs_command_request);
}

cJSON *adcs_command_request_convertToJSON(adcs_command_request_t *adcs_command_request) {
    cJSON *item = cJSON_CreateObject();

    // adcs_command_request->command
    if (!adcs_command_request->command) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "command", adcs_command_request->command) == NULL) {
    goto fail; //String
    }


    // adcs_command_request->aperture
    if(adcs_command_request->aperture) { 
    if(cJSON_AddStringToObject(item, "aperture", adcs_command_request->aperture) == NULL) {
    goto fail; //String
    }
     } 


    // adcs_command_request->target
    if(adcs_command_request->target) { 
    cJSON *target_local_JSON = adcs_target_convertToJSON(adcs_command_request->target);
    if(target_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "target", target_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // adcs_command_request->angle
    if(adcs_command_request->angle) { 
    if(cJSON_AddNumberToObject(item, "angle", adcs_command_request->angle) == NULL) {
    goto fail; //Numeric
    }
     } 


    // adcs_command_request->vector
    if(adcs_command_request->vector) { 
    cJSON *vector_local_JSON = adcs_xyz_float_t_convertToJSON(adcs_command_request->vector);
    if(vector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "vector", vector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // adcs_command_request->quat
    if(adcs_command_request->quat) { 
    cJSON *quat_local_JSON = adcs_quat_t_convertToJSON(adcs_command_request->quat);
    if(quat_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "quat", quat_local_JSON);
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

adcs_command_request_t *adcs_command_request_parseFromJSON(cJSON *adcs_command_requestJSON){

    adcs_command_request_t *adcs_command_request_local_var = NULL;

    // adcs_command_request->command
    cJSON *command = cJSON_GetObjectItemCaseSensitive(adcs_command_requestJSON, "command");
    if (!command) {
        goto end;
    }

    
    if(!cJSON_IsString(command))
    {
    goto end; //String
    }

    // adcs_command_request->aperture
    cJSON *aperture = cJSON_GetObjectItemCaseSensitive(adcs_command_requestJSON, "aperture");
    if (aperture) { 
    if(!cJSON_IsString(aperture))
    {
    goto end; //String
    }
    }

    // adcs_command_request->target
    cJSON *target = cJSON_GetObjectItemCaseSensitive(adcs_command_requestJSON, "target");
    adcs_target_t *target_local_nonprim = NULL;
    if (target) { 
    target_local_nonprim = adcs_target_parseFromJSON(target); //nonprimitive
    }

    // adcs_command_request->angle
    cJSON *angle = cJSON_GetObjectItemCaseSensitive(adcs_command_requestJSON, "angle");
    if (angle) { 
    if(!cJSON_IsNumber(angle))
    {
    goto end; //Numeric
    }
    }

    // adcs_command_request->vector
    cJSON *vector = cJSON_GetObjectItemCaseSensitive(adcs_command_requestJSON, "vector");
    adcs_xyz_float_t_t *vector_local_nonprim = NULL;
    if (vector) { 
    vector_local_nonprim = adcs_xyz_float_t_parseFromJSON(vector); //nonprimitive
    }

    // adcs_command_request->quat
    cJSON *quat = cJSON_GetObjectItemCaseSensitive(adcs_command_requestJSON, "quat");
    adcs_quat_t_t *quat_local_nonprim = NULL;
    if (quat) { 
    quat_local_nonprim = adcs_quat_t_parseFromJSON(quat); //nonprimitive
    }


    adcs_command_request_local_var = adcs_command_request_create (
        strdup(command->valuestring),
        aperture ? strdup(aperture->valuestring) : NULL,
        target ? target_local_nonprim : NULL,
        angle ? angle->valuedouble : 0,
        vector ? vector_local_nonprim : NULL,
        quat ? quat_local_nonprim : NULL
        );

    return adcs_command_request_local_var;
end:
    return NULL;

}
