#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "adcs_command_response.h"


    char* statusadcs_command_response_ToString(status_e status){
    char *statusArray[] =  { "OK","FAIL" };
        return statusArray[status];
    }

    status_e statusadcs_command_response_FromString(char* status){
    int stringToReturn = 0;
    char *statusArray[] =  { "OK","FAIL" };
    size_t sizeofArray = sizeof(statusArray) / sizeof(statusArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(status, statusArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
    }

adcs_command_response_t *adcs_command_response_create(
    status_e status,
    char *reason,
    char *mode,
    adcs_target_t *target,
    adcs_xyz_float_t_t *vector,
    adcs_quat_t_t *quat
    ) {
    adcs_command_response_t *adcs_command_response_local_var = malloc(sizeof(adcs_command_response_t));
    if (!adcs_command_response_local_var) {
        return NULL;
    }
    adcs_command_response_local_var->status = status;
    adcs_command_response_local_var->reason = reason;
    adcs_command_response_local_var->mode = mode;
    adcs_command_response_local_var->target = target;
    adcs_command_response_local_var->vector = vector;
    adcs_command_response_local_var->quat = quat;

    return adcs_command_response_local_var;
}


void adcs_command_response_free(adcs_command_response_t *adcs_command_response) {
    if(NULL == adcs_command_response){
        return ;
    }
    listEntry_t *listEntry;
    free(adcs_command_response->reason);
    free(adcs_command_response->mode);
    adcs_target_free(adcs_command_response->target);
    adcs_xyz_float_t_free(adcs_command_response->vector);
    adcs_quat_t_free(adcs_command_response->quat);
    free(adcs_command_response);
}

cJSON *adcs_command_response_convertToJSON(adcs_command_response_t *adcs_command_response) {
    cJSON *item = cJSON_CreateObject();

    // adcs_command_response->status
    
    if(cJSON_AddStringToObject(item, "status", statusadcs_command_response_ToString(adcs_command_response->status)) == NULL)
    {
    goto fail; //Enum
    }


    // adcs_command_response->reason
    if(adcs_command_response->reason) { 
    if(cJSON_AddStringToObject(item, "reason", adcs_command_response->reason) == NULL) {
    goto fail; //String
    }
     } 


    // adcs_command_response->mode
    if (!adcs_command_response->mode) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "mode", adcs_command_response->mode) == NULL) {
    goto fail; //String
    }


    // adcs_command_response->target
    if(adcs_command_response->target) { 
    cJSON *target_local_JSON = adcs_target_convertToJSON(adcs_command_response->target);
    if(target_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "target", target_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // adcs_command_response->vector
    if(adcs_command_response->vector) { 
    cJSON *vector_local_JSON = adcs_xyz_float_t_convertToJSON(adcs_command_response->vector);
    if(vector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "vector", vector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // adcs_command_response->quat
    if(adcs_command_response->quat) { 
    cJSON *quat_local_JSON = adcs_quat_t_convertToJSON(adcs_command_response->quat);
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

adcs_command_response_t *adcs_command_response_parseFromJSON(cJSON *adcs_command_responseJSON){

    adcs_command_response_t *adcs_command_response_local_var = NULL;

    // adcs_command_response->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(adcs_command_responseJSON, "status");
    if (!status) {
        goto end;
    }

    status_e statusVariable;
    
    if(!cJSON_IsString(status))
    {
    goto end; //Enum
    }
    statusVariable = statusadcs_command_response_FromString(status->valuestring);

    // adcs_command_response->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(adcs_command_responseJSON, "reason");
    if (reason) { 
    if(!cJSON_IsString(reason))
    {
    goto end; //String
    }
    }

    // adcs_command_response->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(adcs_command_responseJSON, "mode");
    if (!mode) {
        goto end;
    }

    
    if(!cJSON_IsString(mode))
    {
    goto end; //String
    }

    // adcs_command_response->target
    cJSON *target = cJSON_GetObjectItemCaseSensitive(adcs_command_responseJSON, "target");
    adcs_target_t *target_local_nonprim = NULL;
    if (target) { 
    target_local_nonprim = adcs_target_parseFromJSON(target); //nonprimitive
    }

    // adcs_command_response->vector
    cJSON *vector = cJSON_GetObjectItemCaseSensitive(adcs_command_responseJSON, "vector");
    adcs_xyz_float_t_t *vector_local_nonprim = NULL;
    if (vector) { 
    vector_local_nonprim = adcs_xyz_float_t_parseFromJSON(vector); //nonprimitive
    }

    // adcs_command_response->quat
    cJSON *quat = cJSON_GetObjectItemCaseSensitive(adcs_command_responseJSON, "quat");
    adcs_quat_t_t *quat_local_nonprim = NULL;
    if (quat) { 
    quat_local_nonprim = adcs_quat_t_parseFromJSON(quat); //nonprimitive
    }


    adcs_command_response_local_var = adcs_command_response_create (
        statusVariable,
        reason ? strdup(reason->valuestring) : NULL,
        strdup(mode->valuestring),
        target ? target_local_nonprim : NULL,
        vector ? vector_local_nonprim : NULL,
        quat ? quat_local_nonprim : NULL
        );

    return adcs_command_response_local_var;
end:
    return NULL;

}
