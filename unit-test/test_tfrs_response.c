#ifndef tfrs_response_TEST
#define tfrs_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define tfrs_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/tfrs_response.h"
tfrs_response_t* instantiate_tfrs_response(int include_optional);



tfrs_response_t* instantiate_tfrs_response(int include_optional) {
  tfrs_response_t* tfrs_response = NULL;
  if (include_optional) {
    tfrs_response = tfrs_response_create(
      1.337,
      56,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337
    );
  } else {
    tfrs_response = tfrs_response_create(
      1.337,
      56,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337,
      1.337
    );
  }

  return tfrs_response;
}


#ifdef tfrs_response_MAIN

void test_tfrs_response(int include_optional) {
    tfrs_response_t* tfrs_response_1 = instantiate_tfrs_response(include_optional);

	cJSON* jsontfrs_response_1 = tfrs_response_convertToJSON(tfrs_response_1);
	printf("tfrs_response :\n%s\n", cJSON_Print(jsontfrs_response_1));
	tfrs_response_t* tfrs_response_2 = tfrs_response_parseFromJSON(jsontfrs_response_1);
	cJSON* jsontfrs_response_2 = tfrs_response_convertToJSON(tfrs_response_2);
	printf("repeating tfrs_response:\n%s\n", cJSON_Print(jsontfrs_response_2));
}

int main() {
  test_tfrs_response(1);
  test_tfrs_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // tfrs_response_MAIN
#endif // tfrs_response_TEST
