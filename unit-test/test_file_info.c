#ifndef file_info_TEST
#define file_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define file_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/file_info.h"
file_info_t* instantiate_file_info(int include_optional);



file_info_t* instantiate_file_info(int include_optional) {
  file_info_t* file_info = NULL;
  if (include_optional) {
    file_info = file_info_create(
      "0",
      "0",
      56,
      56,
      56,
      "0",
      list_createList(),
      list_createList()
    );
  } else {
    file_info = file_info_create(
      "0",
      "0",
      56,
      56,
      56,
      "0",
      list_createList(),
      list_createList()
    );
  }

  return file_info;
}


#ifdef file_info_MAIN

void test_file_info(int include_optional) {
    file_info_t* file_info_1 = instantiate_file_info(include_optional);

	cJSON* jsonfile_info_1 = file_info_convertToJSON(file_info_1);
	printf("file_info :\n%s\n", cJSON_Print(jsonfile_info_1));
	file_info_t* file_info_2 = file_info_parseFromJSON(jsonfile_info_1);
	cJSON* jsonfile_info_2 = file_info_convertToJSON(file_info_2);
	printf("repeating file_info:\n%s\n", cJSON_Print(jsonfile_info_2));
}

int main() {
  test_file_info(1);
  test_file_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // file_info_MAIN
#endif // file_info_TEST
