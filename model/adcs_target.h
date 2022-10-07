/*
 * adcs_target.h
 *
 * A ground location for the satellite to point at
 */

#ifndef _adcs_target_H_
#define _adcs_target_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct adcs_target_t {
    double lat; //numeric
    double lon; //numeric

} adcs_target_t;

adcs_target_t *adcs_target_create(
    double lat,
    double lon
);

void adcs_target_free(adcs_target_t *adcs_target);

adcs_target_t *adcs_target_parseFromJSON(cJSON *adcs_targetJSON);

cJSON *adcs_target_convertToJSON(adcs_target_t *adcs_target);

#endif /* _adcs_target_H_ */

