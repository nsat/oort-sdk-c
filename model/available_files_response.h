/*
 * available_files_response.h
 *
 * 
 */

#ifndef _available_files_response_H_
#define _available_files_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct available_files_response_t available_files_response_t;

#include "file_info.h"



typedef struct available_files_response_t {
    list_t *files; //nonprimitive container
    int overflow; //boolean

} available_files_response_t;

available_files_response_t *available_files_response_create(
    list_t *files,
    int overflow
);

void available_files_response_free(available_files_response_t *available_files_response);

available_files_response_t *available_files_response_parseFromJSON(cJSON *available_files_responseJSON);

cJSON *available_files_response_convertToJSON(available_files_response_t *available_files_response);

#endif /* _available_files_response_H_ */

