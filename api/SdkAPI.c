#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "SdkAPI.h"

#define MAX_NUMBER_LENGTH 16
#define MAX_BUFFER_LENGTH 4096
#define intToStr(dst, src) \
    do {\
    char dst[256];\
    snprintf(dst, 256, "%ld", (long int)(src));\
}while(0)


// request adcs operation
//
adcs_command_response_t*
SdkAPI_commandAdcs(apiClient_t *apiClient, adcs_command_request_t * adcs_command_request )
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/adcs")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/adcs");




    // Body Param
    cJSON *localVarSingleItemJSON_adcs_command_request = NULL;
    if (adcs_command_request != NULL)
    {
        //string
        localVarSingleItemJSON_adcs_command_request = adcs_command_request_convertToJSON(adcs_command_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_adcs_command_request);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","ERROR");
    //}
    //nonprimitive not container
    cJSON *SdkAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    adcs_command_response_t *elementToReturn = adcs_command_response_parseFromJSON(SdkAPIlocalVarJSON);
    cJSON_Delete(SdkAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_adcs_command_request) {
        cJSON_Delete(localVarSingleItemJSON_adcs_command_request);
        localVarSingleItemJSON_adcs_command_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// query adcs status
//
adcs_response_t*
SdkAPI_getAdcs(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/adcs")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/adcs");



    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    //nonprimitive not container
    cJSON *SdkAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    adcs_response_t *elementToReturn = adcs_response_parseFromJSON(SdkAPIlocalVarJSON);
    cJSON_Delete(SdkAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

// get tfrs values
//
tfrs_response_t*
SdkAPI_getTfrs(apiClient_t *apiClient)
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/tfrs")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/tfrs");



    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    //nonprimitive not container
    cJSON *SdkAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    tfrs_response_t *elementToReturn = tfrs_response_parseFromJSON(SdkAPIlocalVarJSON);
    cJSON_Delete(SdkAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

available_files_response_t*
SdkAPI_queryAvailableFiles(apiClient_t *apiClient, char * topic )
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = NULL;
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/query_available_files/{topic}")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/query_available_files/{topic}");


    // Path Params
    long sizeOfPathParams_topic = strlen(topic)+3 + strlen("{ topic }");
    if(topic == NULL) {
        goto end;
    }
    char* localVarToReplace_topic = malloc(sizeOfPathParams_topic);
    sprintf(localVarToReplace_topic, "{%s}", "topic");

    localVarPath = strReplace(localVarPath, localVarToReplace_topic, topic);


    list_addElement(localVarHeaderType,"application/json"); //produces
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "GET");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    //nonprimitive not container
    cJSON *SdkAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    available_files_response_t *elementToReturn = available_files_response_parseFromJSON(SdkAPIlocalVarJSON);
    cJSON_Delete(SdkAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    
    free(localVarPath);
    free(localVarToReplace_topic);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

file_info_t*
SdkAPI_retrieveFile(apiClient_t *apiClient, retrieve_file_request_t * retrieve_file_request )
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/retrieve_file")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/retrieve_file");




    // Body Param
    cJSON *localVarSingleItemJSON_retrieve_file_request = NULL;
    if (retrieve_file_request != NULL)
    {
        //string
        localVarSingleItemJSON_retrieve_file_request = retrieve_file_request_convertToJSON(retrieve_file_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_retrieve_file_request);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request");
    //}
    //nonprimitive not container
    cJSON *SdkAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    file_info_t *elementToReturn = file_info_parseFromJSON(SdkAPIlocalVarJSON);
    cJSON_Delete(SdkAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_retrieve_file_request) {
        cJSON_Delete(localVarSingleItemJSON_retrieve_file_request);
        localVarSingleItemJSON_retrieve_file_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

send_file_response_t*
SdkAPI_sendFile(apiClient_t *apiClient, send_file_request_t * send_file_request )
{
    list_t    *localVarQueryParameters = NULL;
    list_t    *localVarHeaderParameters = NULL;
    list_t    *localVarFormParameters = NULL;
    list_t *localVarHeaderType = list_createList();
    list_t *localVarContentType = list_createList();
    char      *localVarBodyParameters = NULL;

    // create the path
    long sizeOfPath = strlen("/send_file")+1;
    char *localVarPath = malloc(sizeOfPath);
    snprintf(localVarPath, sizeOfPath, "/send_file");




    // Body Param
    cJSON *localVarSingleItemJSON_send_file_request = NULL;
    if (send_file_request != NULL)
    {
        //string
        localVarSingleItemJSON_send_file_request = send_file_request_convertToJSON(send_file_request);
        localVarBodyParameters = cJSON_Print(localVarSingleItemJSON_send_file_request);
    }
    list_addElement(localVarHeaderType,"application/json"); //produces
    list_addElement(localVarContentType,"application/json"); //consumes
    apiClient_invoke(apiClient,
                    localVarPath,
                    localVarQueryParameters,
                    localVarHeaderParameters,
                    localVarFormParameters,
                    localVarHeaderType,
                    localVarContentType,
                    localVarBodyParameters,
                    "POST");

    // uncomment below to debug the error response
    //if (apiClient->response_code == 200) {
    //    printf("%s\n","OK");
    //}
    // uncomment below to debug the error response
    //if (apiClient->response_code == 400) {
    //    printf("%s\n","Bad request");
    //}
    //nonprimitive not container
    cJSON *SdkAPIlocalVarJSON = cJSON_Parse(apiClient->dataReceived);
    send_file_response_t *elementToReturn = send_file_response_parseFromJSON(SdkAPIlocalVarJSON);
    cJSON_Delete(SdkAPIlocalVarJSON);
    if(elementToReturn == NULL) {
        // return 0;
    }

    //return type
    if (apiClient->dataReceived) {
        free(apiClient->dataReceived);
        apiClient->dataReceived = NULL;
        apiClient->dataReceivedLen = 0;
    }
    
    
    
    list_freeList(localVarHeaderType);
    list_freeList(localVarContentType);
    free(localVarPath);
    if (localVarSingleItemJSON_send_file_request) {
        cJSON_Delete(localVarSingleItemJSON_send_file_request);
        localVarSingleItemJSON_send_file_request = NULL;
    }
    free(localVarBodyParameters);
    return elementToReturn;
end:
    free(localVarPath);
    return NULL;

}

