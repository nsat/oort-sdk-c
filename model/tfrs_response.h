/*
 * tfrs_response.h
 *
 * TFRS time and position
 */

#ifndef _tfrs_response_H_
#define _tfrs_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct tfrs_response_t tfrs_response_t;




typedef struct tfrs_response_t {
    double age; //numeric
    int utc_time; //numeric
    double ecef_pos_x; //numeric
    double ecef_pos_y; //numeric
    double ecef_pos_z; //numeric
    double ecef_vel_x; //numeric
    double ecef_vel_y; //numeric
    double ecef_vel_z; //numeric

} tfrs_response_t;

tfrs_response_t *tfrs_response_create(
    double age,
    int utc_time,
    double ecef_pos_x,
    double ecef_pos_y,
    double ecef_pos_z,
    double ecef_vel_x,
    double ecef_vel_y,
    double ecef_vel_z
);

void tfrs_response_free(tfrs_response_t *tfrs_response);

tfrs_response_t *tfrs_response_parseFromJSON(cJSON *tfrs_responseJSON);

cJSON *tfrs_response_convertToJSON(tfrs_response_t *tfrs_response);

#endif /* _tfrs_response_H_ */

