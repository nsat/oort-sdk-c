/*
 * adcs_response.h
 *
 * ADCS Orientation and status
 */

#ifndef _adcs_response_H_
#define _adcs_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct adcs_response_t adcs_response_t;

#include "adcs_hk.h"



typedef struct adcs_response_t {
    char *mode; // string
    double age; //numeric
    char *controller; // string
    struct adcs_hk_t *hk; //model

} adcs_response_t;

adcs_response_t *adcs_response_create(
    char *mode,
    double age,
    char *controller,
    adcs_hk_t *hk
);

void adcs_response_free(adcs_response_t *adcs_response);

adcs_response_t *adcs_response_parseFromJSON(cJSON *adcs_responseJSON);

cJSON *adcs_response_convertToJSON(adcs_response_t *adcs_response);

#endif /* _adcs_response_H_ */

