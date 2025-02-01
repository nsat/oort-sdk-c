#ifndef available_files_response_TEST
#define available_files_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define available_files_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/available_files_response.h"
available_files_response_t* instantiate_available_files_response(int include_optional);



available_files_response_t* instantiate_available_files_response(int include_optional) {
  available_files_response_t* available_files_response = NULL;
  if (include_optional) {
    available_files_response = available_files_response_create(
      list_createList(),
      1
    );
  } else {
    available_files_response = available_files_response_create(
      list_createList(),
      1
    );
  }

  return available_files_response;
}


#ifdef available_files_response_MAIN

void test_available_files_response(int include_optional) {
    available_files_response_t* available_files_response_1 = instantiate_available_files_response(include_optional);

	cJSON* jsonavailable_files_response_1 = available_files_response_convertToJSON(available_files_response_1);
	printf("available_files_response :\n%s\n", cJSON_Print(jsonavailable_files_response_1));
	available_files_response_t* available_files_response_2 = available_files_response_parseFromJSON(jsonavailable_files_response_1);
	cJSON* jsonavailable_files_response_2 = available_files_response_convertToJSON(available_files_response_2);
	printf("repeating available_files_response:\n%s\n", cJSON_Print(jsonavailable_files_response_2));
}

int main() {
  test_available_files_response(1);
  test_available_files_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // available_files_response_MAIN
#endif // available_files_response_TEST
