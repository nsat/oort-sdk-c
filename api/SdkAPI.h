#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../model/available_files_response.h"
#include "../model/error_response.h"
#include "../model/file_info.h"
#include "../model/retrieve_file_request.h"
#include "../model/send_file_request.h"
#include "../model/send_file_response.h"


available_files_response_t*
SdkAPI_queryAvailableFiles(apiClient_t *apiClient ,char * topic);


file_info_t*
SdkAPI_retrieveFile(apiClient_t *apiClient ,retrieve_file_request_t * retrieve_file_request);


send_file_response_t*
SdkAPI_sendFile(apiClient_t *apiClient ,send_file_request_t * send_file_request);


