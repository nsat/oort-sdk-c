# adcs_hk_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**control_error_angle_deg** | **double** | Absolute control error angle  | [optional] 
**acs_mode_active** | **char \*** | Active ADCS mode  | [optional] 
**euler_angles** | [**adcs_euler_t_t**](adcs_euler_t.md) \* |  | [optional] 
**control_error_q** | [**adcs_quat_t_t**](adcs_quat_t.md) \* |  | [optional] 
**lat_deg** | **double** | Subsatellite latitude, in degrees  | [optional] 
**q_bo_est** | [**adcs_quat_t_t**](adcs_quat_t.md) \* |  | [optional] 
**latlontrack_lat** | **double** | latitude used for ground target tracking  | [optional] 
**lease_active** | **int** | Flag if a lease is currently active  | [optional] 
**lon_deg** | **double** | Subsatellite longitude, in degrees  | [optional] 
**eclipse_flag** | **int** | Sunlit/eclipse status of spacecraft  | [optional] 
**q_bi_est** | [**adcs_quat_t_t**](adcs_quat_t.md) \* |  | [optional] 
**latlontrack_lon** | **double** | longitude used for ground target tracking  | [optional] 
**r_eci** | [**adcs_xyz_float_t_t**](adcs_xyz_float_t.md) \* |  | [optional] 
**altitude** | **double** | Estimated altitude of satellite in meters  | [optional] 
**latlontrack_body_vector** | [**adcs_xyz_float_t_t**](adcs_xyz_float_t.md) \* |  | [optional] 
**omega_bo_est** | [**adcs_xyz_float_t_t**](adcs_xyz_float_t.md) \* |  | [optional] 
**acs_mode_cmd** | **char \*** | Commanded ADCS mode  | [optional] 
**v_eci** | [**adcs_xyz_float_t_t**](adcs_xyz_float_t.md) \* |  | [optional] 
**qcf** | [**adcs_quat_t_t**](adcs_quat_t.md) \* |  | [optional] 
**lease_time_remaining** | **int** | time remaining in current ADCS lease  | [optional] 
**unix_timestamp** | **double** | Unix epoch time  | [optional] 
**omega_bi_est** | [**adcs_xyz_float_t_t**](adcs_xyz_float_t.md) \* |  | [optional] 
**control_error_omega** | [**adcs_xyz_float_t_t**](adcs_xyz_float_t.md) \* |  | [optional] 
**r_ecef** | [**adcs_xyz_float_t_t**](adcs_xyz_float_t.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


