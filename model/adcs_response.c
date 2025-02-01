#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "adcs_response.h"



adcs_response_t *adcs_response_create(
    char *mode,
    double age,
    char *controller,
    adcs_hk_t *hk
    ) {
    adcs_response_t *adcs_response_local_var = malloc(sizeof(adcs_response_t));
    if (!adcs_response_local_var) {
        return NULL;
    }
    adcs_response_local_var->mode = mode;
    adcs_response_local_var->age = age;
    adcs_response_local_var->controller = controller;
    adcs_response_local_var->hk = hk;

    return adcs_response_local_var;
}


void adcs_response_free(adcs_response_t *adcs_response) {
    if(NULL == adcs_response){
        return ;
    }
    listEntry_t *listEntry;
    if (adcs_response->mode) {
        free(adcs_response->mode);
        adcs_response->mode = NULL;
    }
    if (adcs_response->controller) {
        free(adcs_response->controller);
        adcs_response->controller = NULL;
    }
    if (adcs_response->hk) {
        adcs_hk_free(adcs_response->hk);
        adcs_response->hk = NULL;
    }
    free(adcs_response);
}

cJSON *adcs_response_convertToJSON(adcs_response_t *adcs_response) {
    cJSON *item = cJSON_CreateObject();

    // adcs_response->mode
    if (!adcs_response->mode) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mode", adcs_response->mode) == NULL) {
    goto fail; //String
    }


    // adcs_response->age
    if (!adcs_response->age) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "age", adcs_response->age) == NULL) {
    goto fail; //Numeric
    }


    // adcs_response->controller
    if(adcs_response->controller) {
    if(cJSON_AddStringToObject(item, "controller", adcs_response->controller) == NULL) {
    goto fail; //String
    }
    }


    // adcs_response->hk
    if(adcs_response->hk) {
    cJSON *hk_local_JSON = adcs_hk_convertToJSON(adcs_response->hk);
    if(hk_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "hk", hk_local_JSON);
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

adcs_response_t *adcs_response_parseFromJSON(cJSON *adcs_responseJSON){

    adcs_response_t *adcs_response_local_var = NULL;

    // define the local variable for adcs_response->hk
    adcs_hk_t *hk_local_nonprim = NULL;

    // adcs_response->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(adcs_responseJSON, "mode");
    if (!mode) {
        goto end;
    }

    
    if(!cJSON_IsString(mode))
    {
    goto end; //String
    }

    // adcs_response->age
    cJSON *age = cJSON_GetObjectItemCaseSensitive(adcs_responseJSON, "age");
    if (!age) {
        goto end;
    }

    
    if(!cJSON_IsNumber(age))
    {
    goto end; //Numeric
    }

    // adcs_response->controller
    cJSON *controller = cJSON_GetObjectItemCaseSensitive(adcs_responseJSON, "controller");
    if (controller) { 
    if(!cJSON_IsString(controller) && !cJSON_IsNull(controller))
    {
    goto end; //String
    }
    }

    // adcs_response->hk
    cJSON *hk = cJSON_GetObjectItemCaseSensitive(adcs_responseJSON, "hk");
    if (hk) { 
    hk_local_nonprim = adcs_hk_parseFromJSON(hk); //nonprimitive
    }


    adcs_response_local_var = adcs_response_create (
        strdup(mode->valuestring),
        age->valuedouble,
        controller && !cJSON_IsNull(controller) ? strdup(controller->valuestring) : NULL,
        hk ? hk_local_nonprim : NULL
        );

    return adcs_response_local_var;
end:
    if (hk_local_nonprim) {
        adcs_hk_free(hk_local_nonprim);
        hk_local_nonprim = NULL;
    }
    return NULL;

}
