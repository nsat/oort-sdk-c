/*
 * adcs_hk.h
 *
 * ADCS hk response
 */

#ifndef _adcs_hk_H_
#define _adcs_hk_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "adcs_euler_t.h"
#include "adcs_quat_t.h"
#include "adcs_xyz_float_t.h"



typedef struct adcs_hk_t {
    double control_error_angle_deg; //numeric
    char *acs_mode_active; // string
    struct adcs_euler_t_t *euler_angles; //model
    struct adcs_quat_t_t *control_error_q; //model
    double lat_deg; //numeric
    struct adcs_quat_t_t *q_bo_est; //model
    double latlontrack_lat; //numeric
    int lease_active; //numeric
    double lon_deg; //numeric
    int eclipse_flag; //numeric
    struct adcs_quat_t_t *q_bi_est; //model
    double latlontrack_lon; //numeric
    struct adcs_xyz_float_t_t *r_eci; //model
    double altitude; //numeric
    struct adcs_xyz_float_t_t *latlontrack_body_vector; //model
    struct adcs_xyz_float_t_t *omega_bo_est; //model
    char *acs_mode_cmd; // string
    struct adcs_xyz_float_t_t *v_eci; //model
    struct adcs_quat_t_t *qcf; //model
    int lease_time_remaining; //numeric
    double unix_timestamp; //numeric
    struct adcs_xyz_float_t_t *omega_bi_est; //model
    struct adcs_xyz_float_t_t *control_error_omega; //model
    struct adcs_xyz_float_t_t *r_ecef; //model

} adcs_hk_t;

adcs_hk_t *adcs_hk_create(
    double control_error_angle_deg,
    char *acs_mode_active,
    adcs_euler_t_t *euler_angles,
    adcs_quat_t_t *control_error_q,
    double lat_deg,
    adcs_quat_t_t *q_bo_est,
    double latlontrack_lat,
    int lease_active,
    double lon_deg,
    int eclipse_flag,
    adcs_quat_t_t *q_bi_est,
    double latlontrack_lon,
    adcs_xyz_float_t_t *r_eci,
    double altitude,
    adcs_xyz_float_t_t *latlontrack_body_vector,
    adcs_xyz_float_t_t *omega_bo_est,
    char *acs_mode_cmd,
    adcs_xyz_float_t_t *v_eci,
    adcs_quat_t_t *qcf,
    int lease_time_remaining,
    double unix_timestamp,
    adcs_xyz_float_t_t *omega_bi_est,
    adcs_xyz_float_t_t *control_error_omega,
    adcs_xyz_float_t_t *r_ecef
);

void adcs_hk_free(adcs_hk_t *adcs_hk);

adcs_hk_t *adcs_hk_parseFromJSON(cJSON *adcs_hkJSON);

cJSON *adcs_hk_convertToJSON(adcs_hk_t *adcs_hk);

#endif /* _adcs_hk_H_ */

