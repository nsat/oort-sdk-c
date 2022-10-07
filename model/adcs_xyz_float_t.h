/*
 * adcs_xyz_float_t.h
 *
 * ADCS float x,y,z type
 */

#ifndef _adcs_xyz_float_t_H_
#define _adcs_xyz_float_t_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct adcs_xyz_float_t_t {
    double x; //numeric
    double y; //numeric
    double z; //numeric

} adcs_xyz_float_t_t;

adcs_xyz_float_t_t *adcs_xyz_float_t_create(
    double x,
    double y,
    double z
);

void adcs_xyz_float_t_free(adcs_xyz_float_t_t *adcs_xyz_float_t);

adcs_xyz_float_t_t *adcs_xyz_float_t_parseFromJSON(cJSON *adcs_xyz_float_tJSON);

cJSON *adcs_xyz_float_t_convertToJSON(adcs_xyz_float_t_t *adcs_xyz_float_t);

#endif /* _adcs_xyz_float_t_H_ */

