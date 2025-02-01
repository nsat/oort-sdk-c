/*
 * retrieve_file_request.h
 *
 * 
 */

#ifndef _retrieve_file_request_H_
#define _retrieve_file_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct retrieve_file_request_t retrieve_file_request_t;




typedef struct retrieve_file_request_t {
    char *id; // string
    char *save_path; // string

} retrieve_file_request_t;

retrieve_file_request_t *retrieve_file_request_create(
    char *id,
    char *save_path
);

void retrieve_file_request_free(retrieve_file_request_t *retrieve_file_request);

retrieve_file_request_t *retrieve_file_request_parseFromJSON(cJSON *retrieve_file_requestJSON);

cJSON *retrieve_file_request_convertToJSON(retrieve_file_request_t *retrieve_file_request);

#endif /* _retrieve_file_request_H_ */

