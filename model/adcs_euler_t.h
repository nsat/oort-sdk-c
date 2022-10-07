/*
 * adcs_euler_t.h
 *
 * ADCS Euler angles -- roll, pitch, yaw
 */

#ifndef _adcs_euler_t_H_
#define _adcs_euler_t_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct adcs_euler_t_t {
    double roll; //numeric
    double pitch; //numeric
    double yaw; //numeric

} adcs_euler_t_t;

adcs_euler_t_t *adcs_euler_t_create(
    double roll,
    double pitch,
    double yaw
);

void adcs_euler_t_free(adcs_euler_t_t *adcs_euler_t);

adcs_euler_t_t *adcs_euler_t_parseFromJSON(cJSON *adcs_euler_tJSON);

cJSON *adcs_euler_t_convertToJSON(adcs_euler_t_t *adcs_euler_t);

#endif /* _adcs_euler_t_H_ */

