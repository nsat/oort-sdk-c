#ifndef retrieve_file_request_TEST
#define retrieve_file_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define retrieve_file_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/retrieve_file_request.h"
retrieve_file_request_t* instantiate_retrieve_file_request(int include_optional);



retrieve_file_request_t* instantiate_retrieve_file_request(int include_optional) {
  retrieve_file_request_t* retrieve_file_request = NULL;
  if (include_optional) {
    retrieve_file_request = retrieve_file_request_create(
      "0",
      "a"
    );
  } else {
    retrieve_file_request = retrieve_file_request_create(
      "0",
      "a"
    );
  }

  return retrieve_file_request;
}


#ifdef retrieve_file_request_MAIN

void test_retrieve_file_request(int include_optional) {
    retrieve_file_request_t* retrieve_file_request_1 = instantiate_retrieve_file_request(include_optional);

	cJSON* jsonretrieve_file_request_1 = retrieve_file_request_convertToJSON(retrieve_file_request_1);
	printf("retrieve_file_request :\n%s\n", cJSON_Print(jsonretrieve_file_request_1));
	retrieve_file_request_t* retrieve_file_request_2 = retrieve_file_request_parseFromJSON(jsonretrieve_file_request_1);
	cJSON* jsonretrieve_file_request_2 = retrieve_file_request_convertToJSON(retrieve_file_request_2);
	printf("repeating retrieve_file_request:\n%s\n", cJSON_Print(jsonretrieve_file_request_2));
}

int main() {
  test_retrieve_file_request(1);
  test_retrieve_file_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // retrieve_file_request_MAIN
#endif // retrieve_file_request_TEST
