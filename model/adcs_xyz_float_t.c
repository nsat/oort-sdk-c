#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "adcs_xyz_float_t.h"



adcs_xyz_float_t_t *adcs_xyz_float_t_create(
    double x,
    double y,
    double z
    ) {
    adcs_xyz_float_t_t *adcs_xyz_float_t_local_var = malloc(sizeof(adcs_xyz_float_t_t));
    if (!adcs_xyz_float_t_local_var) {
        return NULL;
    }
    adcs_xyz_float_t_local_var->x = x;
    adcs_xyz_float_t_local_var->y = y;
    adcs_xyz_float_t_local_var->z = z;

    return adcs_xyz_float_t_local_var;
}


void adcs_xyz_float_t_free(adcs_xyz_float_t_t *adcs_xyz_float_t) {
    if(NULL == adcs_xyz_float_t){
        return ;
    }
    listEntry_t *listEntry;
    free(adcs_xyz_float_t);
}

cJSON *adcs_xyz_float_t_convertToJSON(adcs_xyz_float_t_t *adcs_xyz_float_t) {
    cJSON *item = cJSON_CreateObject();

    // adcs_xyz_float_t->x
    if (!adcs_xyz_float_t->x) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "x", adcs_xyz_float_t->x) == NULL) {
    goto fail; //Numeric
    }


    // adcs_xyz_float_t->y
    if (!adcs_xyz_float_t->y) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "y", adcs_xyz_float_t->y) == NULL) {
    goto fail; //Numeric
    }


    // adcs_xyz_float_t->z
    if (!adcs_xyz_float_t->z) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "z", adcs_xyz_float_t->z) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

adcs_xyz_float_t_t *adcs_xyz_float_t_parseFromJSON(cJSON *adcs_xyz_float_tJSON){

    adcs_xyz_float_t_t *adcs_xyz_float_t_local_var = NULL;

    // adcs_xyz_float_t->x
    cJSON *x = cJSON_GetObjectItemCaseSensitive(adcs_xyz_float_tJSON, "x");
    if (!x) {
        goto end;
    }

    
    if(!cJSON_IsNumber(x))
    {
    goto end; //Numeric
    }

    // adcs_xyz_float_t->y
    cJSON *y = cJSON_GetObjectItemCaseSensitive(adcs_xyz_float_tJSON, "y");
    if (!y) {
        goto end;
    }

    
    if(!cJSON_IsNumber(y))
    {
    goto end; //Numeric
    }

    // adcs_xyz_float_t->z
    cJSON *z = cJSON_GetObjectItemCaseSensitive(adcs_xyz_float_tJSON, "z");
    if (!z) {
        goto end;
    }

    
    if(!cJSON_IsNumber(z))
    {
    goto end; //Numeric
    }


    adcs_xyz_float_t_local_var = adcs_xyz_float_t_create (
        x->valuedouble,
        y->valuedouble,
        z->valuedouble
        );

    return adcs_xyz_float_t_local_var;
end:
    return NULL;

}
