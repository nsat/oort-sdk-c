# SdkAPI

All URIs are relative to *http://localhost:2005/sdk/v1*

Method | HTTP request | Description
------------- | ------------- | -------------
[**SdkAPI_commandAdcs**](SdkAPI.md#SdkAPI_commandAdcs) | **POST** /adcs | 
[**SdkAPI_getAdcs**](SdkAPI.md#SdkAPI_getAdcs) | **GET** /adcs | 
[**SdkAPI_getTfrs**](SdkAPI.md#SdkAPI_getTfrs) | **GET** /tfrs | 
[**SdkAPI_queryAvailableFiles**](SdkAPI.md#SdkAPI_queryAvailableFiles) | **GET** /query_available_files/{topic} | 
[**SdkAPI_retrieveFile**](SdkAPI.md#SdkAPI_retrieveFile) | **POST** /retrieve_file | 
[**SdkAPI_sendFile**](SdkAPI.md#SdkAPI_sendFile) | **POST** /send_file | 


# **SdkAPI_commandAdcs**
```c
// request adcs operation
//
adcs_command_response_t* SdkAPI_commandAdcs(apiClient_t *apiClient, adcs_command_request_t * adcs_command_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**adcs_command_request** | **[adcs_command_request_t](adcs_command_request.md) \*** | The file and parameters for sending | 

### Return type

[adcs_command_response_t](adcs_command_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SdkAPI_getAdcs**
```c
// query adcs status
//
adcs_response_t* SdkAPI_getAdcs(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[adcs_response_t](adcs_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SdkAPI_getTfrs**
```c
// get tfrs values
//
tfrs_response_t* SdkAPI_getTfrs(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[tfrs_response_t](tfrs_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SdkAPI_queryAvailableFiles**
```c
available_files_response_t* SdkAPI_queryAvailableFiles(apiClient_t *apiClient, char * topic);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**topic** | **char \*** |  | 

### Return type

[available_files_response_t](available_files_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SdkAPI_retrieveFile**
```c
file_info_t* SdkAPI_retrieveFile(apiClient_t *apiClient, retrieve_file_request_t * retrieve_file_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**retrieve_file_request** | **[retrieve_file_request_t](retrieve_file_request.md) \*** |  | 

### Return type

[file_info_t](file_info.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **SdkAPI_sendFile**
```c
send_file_response_t* SdkAPI_sendFile(apiClient_t *apiClient, send_file_request_t * send_file_request);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**send_file_request** | **[send_file_request_t](send_file_request.md) \*** | The file and parameters for sending | 

### Return type

[send_file_response_t](send_file_response.md) *


### Authorization

No authorization required

### HTTP request headers

 - **Content-Type**: application/json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

