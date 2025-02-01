/*
 * adcs_quat_t.h
 *
 * ADCS QBO type
 */

#ifndef _adcs_quat_t_H_
#define _adcs_quat_t_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct adcs_quat_t_t adcs_quat_t_t;




typedef struct adcs_quat_t_t {
    double q1; //numeric
    double q2; //numeric
    double q3; //numeric
    double q4; //numeric

} adcs_quat_t_t;

adcs_quat_t_t *adcs_quat_t_create(
    double q1,
    double q2,
    double q3,
    double q4
);

void adcs_quat_t_free(adcs_quat_t_t *adcs_quat_t);

adcs_quat_t_t *adcs_quat_t_parseFromJSON(cJSON *adcs_quat_tJSON);

cJSON *adcs_quat_t_convertToJSON(adcs_quat_t_t *adcs_quat_t);

#endif /* _adcs_quat_t_H_ */

