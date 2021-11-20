#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "adcs_quat_t.h"



adcs_quat_t_t *adcs_quat_t_create(
    double q1,
    double q2,
    double q3,
    double q4
    ) {
    adcs_quat_t_t *adcs_quat_t_local_var = malloc(sizeof(adcs_quat_t_t));
    if (!adcs_quat_t_local_var) {
        return NULL;
    }
    adcs_quat_t_local_var->q1 = q1;
    adcs_quat_t_local_var->q2 = q2;
    adcs_quat_t_local_var->q3 = q3;
    adcs_quat_t_local_var->q4 = q4;

    return adcs_quat_t_local_var;
}


void adcs_quat_t_free(adcs_quat_t_t *adcs_quat_t) {
    if(NULL == adcs_quat_t){
        return ;
    }
    listEntry_t *listEntry;
    free(adcs_quat_t);
}

cJSON *adcs_quat_t_convertToJSON(adcs_quat_t_t *adcs_quat_t) {
    cJSON *item = cJSON_CreateObject();

    // adcs_quat_t->q1
    if (!adcs_quat_t->q1) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "q1", adcs_quat_t->q1) == NULL) {
    goto fail; //Numeric
    }


    // adcs_quat_t->q2
    if (!adcs_quat_t->q2) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "q2", adcs_quat_t->q2) == NULL) {
    goto fail; //Numeric
    }


    // adcs_quat_t->q3
    if (!adcs_quat_t->q3) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "q3", adcs_quat_t->q3) == NULL) {
    goto fail; //Numeric
    }


    // adcs_quat_t->q4
    if (!adcs_quat_t->q4) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "q4", adcs_quat_t->q4) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

adcs_quat_t_t *adcs_quat_t_parseFromJSON(cJSON *adcs_quat_tJSON){

    adcs_quat_t_t *adcs_quat_t_local_var = NULL;

    // adcs_quat_t->q1
    cJSON *q1 = cJSON_GetObjectItemCaseSensitive(adcs_quat_tJSON, "q1");
    if (!q1) {
        goto end;
    }

    
    if(!cJSON_IsNumber(q1))
    {
    goto end; //Numeric
    }

    // adcs_quat_t->q2
    cJSON *q2 = cJSON_GetObjectItemCaseSensitive(adcs_quat_tJSON, "q2");
    if (!q2) {
        goto end;
    }

    
    if(!cJSON_IsNumber(q2))
    {
    goto end; //Numeric
    }

    // adcs_quat_t->q3
    cJSON *q3 = cJSON_GetObjectItemCaseSensitive(adcs_quat_tJSON, "q3");
    if (!q3) {
        goto end;
    }

    
    if(!cJSON_IsNumber(q3))
    {
    goto end; //Numeric
    }

    // adcs_quat_t->q4
    cJSON *q4 = cJSON_GetObjectItemCaseSensitive(adcs_quat_tJSON, "q4");
    if (!q4) {
        goto end;
    }

    
    if(!cJSON_IsNumber(q4))
    {
    goto end; //Numeric
    }


    adcs_quat_t_local_var = adcs_quat_t_create (
        q1->valuedouble,
        q2->valuedouble,
        q3->valuedouble,
        q4->valuedouble
        );

    return adcs_quat_t_local_var;
end:
    return NULL;

}
