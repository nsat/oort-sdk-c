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
#include "../include/binary.h"

typedef struct adcs_command_response_t adcs_command_response_t;

#include "adcs_quat_t.h"
#include "adcs_target.h"
#include "adcs_xyz_float_t.h"

// Enum STATUS for adcs_command_response

typedef enum  { oort_agent_sdk_interface_adcs_command_response_STATUS_NULL = 0, oort_agent_sdk_interface_adcs_command_response_STATUS_OK, oort_agent_sdk_interface_adcs_command_response_STATUS_FAIL } oort_agent_sdk_interface_adcs_command_response_STATUS_e;

char* adcs_command_response_status_ToString(oort_agent_sdk_interface_adcs_command_response_STATUS_e status);

oort_agent_sdk_interface_adcs_command_response_STATUS_e adcs_command_response_status_FromString(char* status);



typedef struct adcs_command_response_t {
    oort_agent_sdk_interface_adcs_command_response_STATUS_e status; //enum
    char *reason; // string
    char *mode; // string
    struct adcs_target_t *target; //model
    struct adcs_xyz_float_t_t *vector; //model
    struct adcs_quat_t_t *quat; //model

} adcs_command_response_t;

adcs_command_response_t *adcs_command_response_create(
    oort_agent_sdk_interface_adcs_command_response_STATUS_e status,
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

