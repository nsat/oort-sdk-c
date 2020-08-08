/*
 * send_file_response.h
 *
 * Response to a send file request
 */

#ifndef _send_file_response_H_
#define _send_file_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct send_file_response_t {
    char *uuid; // string

} send_file_response_t;

send_file_response_t *send_file_response_create(
    char *uuid
);

void send_file_response_free(send_file_response_t *send_file_response);

send_file_response_t *send_file_response_parseFromJSON(cJSON *send_file_responseJSON);

cJSON *send_file_response_convertToJSON(send_file_response_t *send_file_response);

#endif /* _send_file_response_H_ */

