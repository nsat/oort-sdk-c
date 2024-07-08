/*
 * file_info.h
 *
 * Information about the file and the transfer request.
 */

#ifndef _file_info_H_
#define _file_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "delivery_hints.h"



typedef struct file_info_t {
    char *id; // string
    char *path; // string
    int size; //numeric
    int modified; //numeric
    int created; //numeric
    char *crc32; // string
    list_t* extra; //map

} file_info_t;

file_info_t *file_info_create(
    char *id,
    char *path,
    int size,
    int modified,
    int created,
    char *crc32,
    list_t* extra,
);

void file_info_free(file_info_t *file_info);

file_info_t *file_info_parseFromJSON(cJSON *file_infoJSON);

cJSON *file_info_convertToJSON(file_info_t *file_info);

#endif /* _file_info_H_ */

