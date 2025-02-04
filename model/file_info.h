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
#include "../include/binary.h"

typedef struct file_info_t file_info_t;

#include "delivery_hints.h"



typedef struct file_info_t {
    char *id; // string
    char *path; // string
    long size; //numeric
    long modified; //numeric
    long created; //numeric
    char *crc32; // string
    list_t* extra; //map
    delivery_hints_t *delivery_hints; // custom

} file_info_t;

file_info_t *file_info_create(
    char *id,
    char *path,
    long size,
    long modified,
    long created,
    char *crc32,
    list_t* extra,
    delivery_hints_t *delivery_hints
);

void file_info_free(file_info_t *file_info);

file_info_t *file_info_parseFromJSON(cJSON *file_infoJSON);

cJSON *file_info_convertToJSON(file_info_t *file_info);

#endif /* _file_info_H_ */

