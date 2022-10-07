/*
 * adcs_command_response.h
 *
 * Response to ADCS command request
 */

#ifndef _adcs_command_response_H_
#define _adcs_command_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "adcs_quat_t.h"
#include "adcs_target.h"
#include "adcs_xyz_float_t.h"

                typedef enum  {  OK, FAIL } status_e;

        char* status_ToString(status_e status);

        status_e status_FromString(char* status);


typedef struct adcs_command_response_t {
    status_e status; //enum
    char *reason; // string
    char *mode; // string
    struct adcs_target_t *target; //model
    struct adcs_xyz_float_t_t *vector; //model
    struct adcs_quat_t_t *quat; //model

} adcs_command_response_t;

adcs_command_response_t *adcs_command_response_create(
    status_e status,
    char *reason,
    char *mode,
    adcs_target_t *target,
    adcs_xyz_float_t_t *vector,
    adcs_quat_t_t *quat
);

void adcs_command_response_free(adcs_command_response_t *adcs_command_response);

adcs_command_response_t *adcs_command_response_parseFromJSON(cJSON *adcs_command_responseJSON);

cJSON *adcs_command_response_convertToJSON(adcs_command_response_t *adcs_command_response);

#endif /* _adcs_command_response_H_ */

