#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "adcs_hk.h"



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
    ) {
    adcs_hk_t *adcs_hk_local_var = malloc(sizeof(adcs_hk_t));
    if (!adcs_hk_local_var) {
        return NULL;
    }
    adcs_hk_local_var->control_error_angle_deg = control_error_angle_deg;
    adcs_hk_local_var->acs_mode_active = acs_mode_active;
    adcs_hk_local_var->euler_angles = euler_angles;
    adcs_hk_local_var->control_error_q = control_error_q;
    adcs_hk_local_var->lat_deg = lat_deg;
    adcs_hk_local_var->q_bo_est = q_bo_est;
    adcs_hk_local_var->latlontrack_lat = latlontrack_lat;
    adcs_hk_local_var->lease_active = lease_active;
    adcs_hk_local_var->lon_deg = lon_deg;
    adcs_hk_local_var->eclipse_flag = eclipse_flag;
    adcs_hk_local_var->q_bi_est = q_bi_est;
    adcs_hk_local_var->latlontrack_lon = latlontrack_lon;
    adcs_hk_local_var->r_eci = r_eci;
    adcs_hk_local_var->altitude = altitude;
    adcs_hk_local_var->latlontrack_body_vector = latlontrack_body_vector;
    adcs_hk_local_var->omega_bo_est = omega_bo_est;
    adcs_hk_local_var->acs_mode_cmd = acs_mode_cmd;
    adcs_hk_local_var->v_eci = v_eci;
    adcs_hk_local_var->qcf = qcf;
    adcs_hk_local_var->lease_time_remaining = lease_time_remaining;
    adcs_hk_local_var->unix_timestamp = unix_timestamp;
    adcs_hk_local_var->omega_bi_est = omega_bi_est;
    adcs_hk_local_var->control_error_omega = control_error_omega;
    adcs_hk_local_var->r_ecef = r_ecef;

    return adcs_hk_local_var;
}


void adcs_hk_free(adcs_hk_t *adcs_hk) {
    if(NULL == adcs_hk){
        return ;
    }
    listEntry_t *listEntry;
    if (adcs_hk->acs_mode_active) {
        free(adcs_hk->acs_mode_active);
        adcs_hk->acs_mode_active = NULL;
    }
    if (adcs_hk->euler_angles) {
        adcs_euler_t_free(adcs_hk->euler_angles);
        adcs_hk->euler_angles = NULL;
    }
    if (adcs_hk->control_error_q) {
        adcs_quat_t_free(adcs_hk->control_error_q);
        adcs_hk->control_error_q = NULL;
    }
    if (adcs_hk->q_bo_est) {
        adcs_quat_t_free(adcs_hk->q_bo_est);
        adcs_hk->q_bo_est = NULL;
    }
    if (adcs_hk->q_bi_est) {
        adcs_quat_t_free(adcs_hk->q_bi_est);
        adcs_hk->q_bi_est = NULL;
    }
    if (adcs_hk->r_eci) {
        adcs_xyz_float_t_free(adcs_hk->r_eci);
        adcs_hk->r_eci = NULL;
    }
    if (adcs_hk->latlontrack_body_vector) {
        adcs_xyz_float_t_free(adcs_hk->latlontrack_body_vector);
        adcs_hk->latlontrack_body_vector = NULL;
    }
    if (adcs_hk->omega_bo_est) {
        adcs_xyz_float_t_free(adcs_hk->omega_bo_est);
        adcs_hk->omega_bo_est = NULL;
    }
    if (adcs_hk->acs_mode_cmd) {
        free(adcs_hk->acs_mode_cmd);
        adcs_hk->acs_mode_cmd = NULL;
    }
    if (adcs_hk->v_eci) {
        adcs_xyz_float_t_free(adcs_hk->v_eci);
        adcs_hk->v_eci = NULL;
    }
    if (adcs_hk->qcf) {
        adcs_quat_t_free(adcs_hk->qcf);
        adcs_hk->qcf = NULL;
    }
    if (adcs_hk->omega_bi_est) {
        adcs_xyz_float_t_free(adcs_hk->omega_bi_est);
        adcs_hk->omega_bi_est = NULL;
    }
    if (adcs_hk->control_error_omega) {
        adcs_xyz_float_t_free(adcs_hk->control_error_omega);
        adcs_hk->control_error_omega = NULL;
    }
    if (adcs_hk->r_ecef) {
        adcs_xyz_float_t_free(adcs_hk->r_ecef);
        adcs_hk->r_ecef = NULL;
    }
    free(adcs_hk);
}

cJSON *adcs_hk_convertToJSON(adcs_hk_t *adcs_hk) {
    cJSON *item = cJSON_CreateObject();

    // adcs_hk->control_error_angle_deg
    if(adcs_hk->control_error_angle_deg) {
    if(cJSON_AddNumberToObject(item, "control_error_angle_deg", adcs_hk->control_error_angle_deg) == NULL) {
    goto fail; //Numeric
    }
    }


    // adcs_hk->acs_mode_active
    if(adcs_hk->acs_mode_active) {
    if(cJSON_AddStringToObject(item, "acs_mode_active", adcs_hk->acs_mode_active) == NULL) {
    goto fail; //String
    }
    }


    // adcs_hk->euler_angles
    if(adcs_hk->euler_angles) {
    cJSON *euler_angles_local_JSON = adcs_euler_t_convertToJSON(adcs_hk->euler_angles);
    if(euler_angles_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "euler_angles", euler_angles_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // adcs_hk->control_error_q
    if(adcs_hk->control_error_q) {
    cJSON *control_error_q_local_JSON = adcs_quat_t_convertToJSON(adcs_hk->control_error_q);
    if(control_error_q_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "control_error_q", control_error_q_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // adcs_hk->lat_deg
    if(adcs_hk->lat_deg) {
    if(cJSON_AddNumberToObject(item, "lat_deg", adcs_hk->lat_deg) == NULL) {
    goto fail; //Numeric
    }
    }


    // adcs_hk->q_bo_est
    if(adcs_hk->q_bo_est) {
    cJSON *q_bo_est_local_JSON = adcs_quat_t_convertToJSON(adcs_hk->q_bo_est);
    if(q_bo_est_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "q_bo_est", q_bo_est_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // adcs_hk->latlontrack_lat
    if(adcs_hk->latlontrack_lat) {
    if(cJSON_AddNumberToObject(item, "latlontrack_lat", adcs_hk->latlontrack_lat) == NULL) {
    goto fail; //Numeric
    }
    }


    // adcs_hk->lease_active
    if(adcs_hk->lease_active) {
    if(cJSON_AddNumberToObject(item, "lease_active", adcs_hk->lease_active) == NULL) {
    goto fail; //Numeric
    }
    }


    // adcs_hk->lon_deg
    if(adcs_hk->lon_deg) {
    if(cJSON_AddNumberToObject(item, "lon_deg", adcs_hk->lon_deg) == NULL) {
    goto fail; //Numeric
    }
    }


    // adcs_hk->eclipse_flag
    if(adcs_hk->eclipse_flag) {
    if(cJSON_AddNumberToObject(item, "eclipse_flag", adcs_hk->eclipse_flag) == NULL) {
    goto fail; //Numeric
    }
    }


    // adcs_hk->q_bi_est
    if(adcs_hk->q_bi_est) {
    cJSON *q_bi_est_local_JSON = adcs_quat_t_convertToJSON(adcs_hk->q_bi_est);
    if(q_bi_est_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "q_bi_est", q_bi_est_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // adcs_hk->latlontrack_lon
    if(adcs_hk->latlontrack_lon) {
    if(cJSON_AddNumberToObject(item, "latlontrack_lon", adcs_hk->latlontrack_lon) == NULL) {
    goto fail; //Numeric
    }
    }


    // adcs_hk->r_eci
    if(adcs_hk->r_eci) {
    cJSON *r_eci_local_JSON = adcs_xyz_float_t_convertToJSON(adcs_hk->r_eci);
    if(r_eci_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "r_eci", r_eci_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // adcs_hk->altitude
    if(adcs_hk->altitude) {
    if(cJSON_AddNumberToObject(item, "altitude", adcs_hk->altitude) == NULL) {
    goto fail; //Numeric
    }
    }


    // adcs_hk->latlontrack_body_vector
    if(adcs_hk->latlontrack_body_vector) {
    cJSON *latlontrack_body_vector_local_JSON = adcs_xyz_float_t_convertToJSON(adcs_hk->latlontrack_body_vector);
    if(latlontrack_body_vector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "latlontrack_body_vector", latlontrack_body_vector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // adcs_hk->omega_bo_est
    if(adcs_hk->omega_bo_est) {
    cJSON *omega_bo_est_local_JSON = adcs_xyz_float_t_convertToJSON(adcs_hk->omega_bo_est);
    if(omega_bo_est_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "omega_bo_est", omega_bo_est_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // adcs_hk->acs_mode_cmd
    if(adcs_hk->acs_mode_cmd) {
    if(cJSON_AddStringToObject(item, "acs_mode_cmd", adcs_hk->acs_mode_cmd) == NULL) {
    goto fail; //String
    }
    }


    // adcs_hk->v_eci
    if(adcs_hk->v_eci) {
    cJSON *v_eci_local_JSON = adcs_xyz_float_t_convertToJSON(adcs_hk->v_eci);
    if(v_eci_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "v_eci", v_eci_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // adcs_hk->qcf
    if(adcs_hk->qcf) {
    cJSON *qcf_local_JSON = adcs_quat_t_convertToJSON(adcs_hk->qcf);
    if(qcf_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "qcf", qcf_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // adcs_hk->lease_time_remaining
    if(adcs_hk->lease_time_remaining) {
    if(cJSON_AddNumberToObject(item, "lease_time_remaining", adcs_hk->lease_time_remaining) == NULL) {
    goto fail; //Numeric
    }
    }


    // adcs_hk->unix_timestamp
    if(adcs_hk->unix_timestamp) {
    if(cJSON_AddNumberToObject(item, "unix_timestamp", adcs_hk->unix_timestamp) == NULL) {
    goto fail; //Numeric
    }
    }


    // adcs_hk->omega_bi_est
    if(adcs_hk->omega_bi_est) {
    cJSON *omega_bi_est_local_JSON = adcs_xyz_float_t_convertToJSON(adcs_hk->omega_bi_est);
    if(omega_bi_est_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "omega_bi_est", omega_bi_est_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // adcs_hk->control_error_omega
    if(adcs_hk->control_error_omega) {
    cJSON *control_error_omega_local_JSON = adcs_xyz_float_t_convertToJSON(adcs_hk->control_error_omega);
    if(control_error_omega_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "control_error_omega", control_error_omega_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // adcs_hk->r_ecef
    if(adcs_hk->r_ecef) {
    cJSON *r_ecef_local_JSON = adcs_xyz_float_t_convertToJSON(adcs_hk->r_ecef);
    if(r_ecef_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "r_ecef", r_ecef_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

adcs_hk_t *adcs_hk_parseFromJSON(cJSON *adcs_hkJSON){

    adcs_hk_t *adcs_hk_local_var = NULL;

    // define the local variable for adcs_hk->euler_angles
    adcs_euler_t_t *euler_angles_local_nonprim = NULL;

    // define the local variable for adcs_hk->control_error_q
    adcs_quat_t_t *control_error_q_local_nonprim = NULL;

    // define the local variable for adcs_hk->q_bo_est
    adcs_quat_t_t *q_bo_est_local_nonprim = NULL;

    // define the local variable for adcs_hk->q_bi_est
    adcs_quat_t_t *q_bi_est_local_nonprim = NULL;

    // define the local variable for adcs_hk->r_eci
    adcs_xyz_float_t_t *r_eci_local_nonprim = NULL;

    // define the local variable for adcs_hk->latlontrack_body_vector
    adcs_xyz_float_t_t *latlontrack_body_vector_local_nonprim = NULL;

    // define the local variable for adcs_hk->omega_bo_est
    adcs_xyz_float_t_t *omega_bo_est_local_nonprim = NULL;

    // define the local variable for adcs_hk->v_eci
    adcs_xyz_float_t_t *v_eci_local_nonprim = NULL;

    // define the local variable for adcs_hk->qcf
    adcs_quat_t_t *qcf_local_nonprim = NULL;

    // define the local variable for adcs_hk->omega_bi_est
    adcs_xyz_float_t_t *omega_bi_est_local_nonprim = NULL;

    // define the local variable for adcs_hk->control_error_omega
    adcs_xyz_float_t_t *control_error_omega_local_nonprim = NULL;

    // define the local variable for adcs_hk->r_ecef
    adcs_xyz_float_t_t *r_ecef_local_nonprim = NULL;

    // adcs_hk->control_error_angle_deg
    cJSON *control_error_angle_deg = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "control_error_angle_deg");
    if (control_error_angle_deg) { 
    if(!cJSON_IsNumber(control_error_angle_deg))
    {
    goto end; //Numeric
    }
    }

    // adcs_hk->acs_mode_active
    cJSON *acs_mode_active = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "acs_mode_active");
    if (acs_mode_active) { 
    if(!cJSON_IsString(acs_mode_active) && !cJSON_IsNull(acs_mode_active))
    {
    goto end; //String
    }
    }

    // adcs_hk->euler_angles
    cJSON *euler_angles = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "euler_angles");
    if (euler_angles) { 
    euler_angles_local_nonprim = adcs_euler_t_parseFromJSON(euler_angles); //nonprimitive
    }

    // adcs_hk->control_error_q
    cJSON *control_error_q = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "control_error_q");
    if (control_error_q) { 
    control_error_q_local_nonprim = adcs_quat_t_parseFromJSON(control_error_q); //nonprimitive
    }

    // adcs_hk->lat_deg
    cJSON *lat_deg = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "lat_deg");
    if (lat_deg) { 
    if(!cJSON_IsNumber(lat_deg))
    {
    goto end; //Numeric
    }
    }

    // adcs_hk->q_bo_est
    cJSON *q_bo_est = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "q_bo_est");
    if (q_bo_est) { 
    q_bo_est_local_nonprim = adcs_quat_t_parseFromJSON(q_bo_est); //nonprimitive
    }

    // adcs_hk->latlontrack_lat
    cJSON *latlontrack_lat = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "latlontrack_lat");
    if (latlontrack_lat) { 
    if(!cJSON_IsNumber(latlontrack_lat))
    {
    goto end; //Numeric
    }
    }

    // adcs_hk->lease_active
    cJSON *lease_active = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "lease_active");
    if (lease_active) { 
    if(!cJSON_IsNumber(lease_active))
    {
    goto end; //Numeric
    }
    }

    // adcs_hk->lon_deg
    cJSON *lon_deg = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "lon_deg");
    if (lon_deg) { 
    if(!cJSON_IsNumber(lon_deg))
    {
    goto end; //Numeric
    }
    }

    // adcs_hk->eclipse_flag
    cJSON *eclipse_flag = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "eclipse_flag");
    if (eclipse_flag) { 
    if(!cJSON_IsNumber(eclipse_flag))
    {
    goto end; //Numeric
    }
    }

    // adcs_hk->q_bi_est
    cJSON *q_bi_est = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "q_bi_est");
    if (q_bi_est) { 
    q_bi_est_local_nonprim = adcs_quat_t_parseFromJSON(q_bi_est); //nonprimitive
    }

    // adcs_hk->latlontrack_lon
    cJSON *latlontrack_lon = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "latlontrack_lon");
    if (latlontrack_lon) { 
    if(!cJSON_IsNumber(latlontrack_lon))
    {
    goto end; //Numeric
    }
    }

    // adcs_hk->r_eci
    cJSON *r_eci = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "r_eci");
    if (r_eci) { 
    r_eci_local_nonprim = adcs_xyz_float_t_parseFromJSON(r_eci); //nonprimitive
    }

    // adcs_hk->altitude
    cJSON *altitude = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "altitude");
    if (altitude) { 
    if(!cJSON_IsNumber(altitude))
    {
    goto end; //Numeric
    }
    }

    // adcs_hk->latlontrack_body_vector
    cJSON *latlontrack_body_vector = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "latlontrack_body_vector");
    if (latlontrack_body_vector) { 
    latlontrack_body_vector_local_nonprim = adcs_xyz_float_t_parseFromJSON(latlontrack_body_vector); //nonprimitive
    }

    // adcs_hk->omega_bo_est
    cJSON *omega_bo_est = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "omega_bo_est");
    if (omega_bo_est) { 
    omega_bo_est_local_nonprim = adcs_xyz_float_t_parseFromJSON(omega_bo_est); //nonprimitive
    }

    // adcs_hk->acs_mode_cmd
    cJSON *acs_mode_cmd = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "acs_mode_cmd");
    if (acs_mode_cmd) { 
    if(!cJSON_IsString(acs_mode_cmd) && !cJSON_IsNull(acs_mode_cmd))
    {
    goto end; //String
    }
    }

    // adcs_hk->v_eci
    cJSON *v_eci = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "v_eci");
    if (v_eci) { 
    v_eci_local_nonprim = adcs_xyz_float_t_parseFromJSON(v_eci); //nonprimitive
    }

    // adcs_hk->qcf
    cJSON *qcf = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "qcf");
    if (qcf) { 
    qcf_local_nonprim = adcs_quat_t_parseFromJSON(qcf); //nonprimitive
    }

    // adcs_hk->lease_time_remaining
    cJSON *lease_time_remaining = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "lease_time_remaining");
    if (lease_time_remaining) { 
    if(!cJSON_IsNumber(lease_time_remaining))
    {
    goto end; //Numeric
    }
    }

    // adcs_hk->unix_timestamp
    cJSON *unix_timestamp = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "unix_timestamp");
    if (unix_timestamp) { 
    if(!cJSON_IsNumber(unix_timestamp))
    {
    goto end; //Numeric
    }
    }

    // adcs_hk->omega_bi_est
    cJSON *omega_bi_est = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "omega_bi_est");
    if (omega_bi_est) { 
    omega_bi_est_local_nonprim = adcs_xyz_float_t_parseFromJSON(omega_bi_est); //nonprimitive
    }

    // adcs_hk->control_error_omega
    cJSON *control_error_omega = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "control_error_omega");
    if (control_error_omega) { 
    control_error_omega_local_nonprim = adcs_xyz_float_t_parseFromJSON(control_error_omega); //nonprimitive
    }

    // adcs_hk->r_ecef
    cJSON *r_ecef = cJSON_GetObjectItemCaseSensitive(adcs_hkJSON, "r_ecef");
    if (r_ecef) { 
    r_ecef_local_nonprim = adcs_xyz_float_t_parseFromJSON(r_ecef); //nonprimitive
    }


    adcs_hk_local_var = adcs_hk_create (
        control_error_angle_deg ? control_error_angle_deg->valuedouble : 0,
        acs_mode_active && !cJSON_IsNull(acs_mode_active) ? strdup(acs_mode_active->valuestring) : NULL,
        euler_angles ? euler_angles_local_nonprim : NULL,
        control_error_q ? control_error_q_local_nonprim : NULL,
        lat_deg ? lat_deg->valuedouble : 0,
        q_bo_est ? q_bo_est_local_nonprim : NULL,
        latlontrack_lat ? latlontrack_lat->valuedouble : 0,
        lease_active ? lease_active->valuedouble : 0,
        lon_deg ? lon_deg->valuedouble : 0,
        eclipse_flag ? eclipse_flag->valuedouble : 0,
        q_bi_est ? q_bi_est_local_nonprim : NULL,
        latlontrack_lon ? latlontrack_lon->valuedouble : 0,
        r_eci ? r_eci_local_nonprim : NULL,
        altitude ? altitude->valuedouble : 0,
        latlontrack_body_vector ? latlontrack_body_vector_local_nonprim : NULL,
        omega_bo_est ? omega_bo_est_local_nonprim : NULL,
        acs_mode_cmd && !cJSON_IsNull(acs_mode_cmd) ? strdup(acs_mode_cmd->valuestring) : NULL,
        v_eci ? v_eci_local_nonprim : NULL,
        qcf ? qcf_local_nonprim : NULL,
        lease_time_remaining ? lease_time_remaining->valuedouble : 0,
        unix_timestamp ? unix_timestamp->valuedouble : 0,
        omega_bi_est ? omega_bi_est_local_nonprim : NULL,
        control_error_omega ? control_error_omega_local_nonprim : NULL,
        r_ecef ? r_ecef_local_nonprim : NULL
        );

    return adcs_hk_local_var;
end:
    if (euler_angles_local_nonprim) {
        adcs_euler_t_free(euler_angles_local_nonprim);
        euler_angles_local_nonprim = NULL;
    }
    if (control_error_q_local_nonprim) {
        adcs_quat_t_free(control_error_q_local_nonprim);
        control_error_q_local_nonprim = NULL;
    }
    if (q_bo_est_local_nonprim) {
        adcs_quat_t_free(q_bo_est_local_nonprim);
        q_bo_est_local_nonprim = NULL;
    }
    if (q_bi_est_local_nonprim) {
        adcs_quat_t_free(q_bi_est_local_nonprim);
        q_bi_est_local_nonprim = NULL;
    }
    if (r_eci_local_nonprim) {
        adcs_xyz_float_t_free(r_eci_local_nonprim);
        r_eci_local_nonprim = NULL;
    }
    if (latlontrack_body_vector_local_nonprim) {
        adcs_xyz_float_t_free(latlontrack_body_vector_local_nonprim);
        latlontrack_body_vector_local_nonprim = NULL;
    }
    if (omega_bo_est_local_nonprim) {
        adcs_xyz_float_t_free(omega_bo_est_local_nonprim);
        omega_bo_est_local_nonprim = NULL;
    }
    if (v_eci_local_nonprim) {
        adcs_xyz_float_t_free(v_eci_local_nonprim);
        v_eci_local_nonprim = NULL;
    }
    if (qcf_local_nonprim) {
        adcs_quat_t_free(qcf_local_nonprim);
        qcf_local_nonprim = NULL;
    }
    if (omega_bi_est_local_nonprim) {
        adcs_xyz_float_t_free(omega_bi_est_local_nonprim);
        omega_bi_est_local_nonprim = NULL;
    }
    if (control_error_omega_local_nonprim) {
        adcs_xyz_float_t_free(control_error_omega_local_nonprim);
        control_error_omega_local_nonprim = NULL;
    }
    if (r_ecef_local_nonprim) {
        adcs_xyz_float_t_free(r_ecef_local_nonprim);
        r_ecef_local_nonprim = NULL;
    }
    return NULL;

}
