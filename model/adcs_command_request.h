/*
 * adcs_command_request.h
 *
 * Request to set ADCS mode and parameters
 */

#ifndef _adcs_command_request_H_
#define _adcs_command_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "adcs_quat_t.h"
#include "adcs_target.h"
#include "adcs_xyz_float_t.h"



typedef struct adcs_command_request_t {
    char *command; // string
    char *aperture; // string
    struct adcs_target_t *target; //model
    double angle; //numeric
    struct adcs_xyz_float_t_t *vector; //model
    struct adcs_quat_t_t *quat; //model

} adcs_command_request_t;

adcs_command_request_t *adcs_command_request_create(
    char *command,
    char *aperture,
    adcs_target_t *target,
    double angle,
    adcs_xyz_float_t_t *vector,
    adcs_quat_t_t *quat
);

void adcs_command_request_free(adcs_command_request_t *adcs_command_request);

adcs_command_request_t *adcs_command_request_parseFromJSON(cJSON *adcs_command_requestJSON);

cJSON *adcs_command_request_convertToJSON(adcs_command_request_t *adcs_command_request);

#endif /* _adcs_command_request_H_ */

