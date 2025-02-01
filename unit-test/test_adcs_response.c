#ifndef adcs_response_TEST
#define adcs_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define adcs_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/adcs_response.h"
adcs_response_t* instantiate_adcs_response(int include_optional);

#include "test_adcs_hk.c"


adcs_response_t* instantiate_adcs_response(int include_optional) {
  adcs_response_t* adcs_response = NULL;
  if (include_optional) {
    adcs_response = adcs_response_create(
      "0",
      1.337,
      "0",
       // false, not to have infinite recursion
      instantiate_adcs_hk(0)
    );
  } else {
    adcs_response = adcs_response_create(
      "0",
      1.337,
      "0",
      NULL
    );
  }

  return adcs_response;
}


#ifdef adcs_response_MAIN

void test_adcs_response(int include_optional) {
    adcs_response_t* adcs_response_1 = instantiate_adcs_response(include_optional);

	cJSON* jsonadcs_response_1 = adcs_response_convertToJSON(adcs_response_1);
	printf("adcs_response :\n%s\n", cJSON_Print(jsonadcs_response_1));
	adcs_response_t* adcs_response_2 = adcs_response_parseFromJSON(jsonadcs_response_1);
	cJSON* jsonadcs_response_2 = adcs_response_convertToJSON(adcs_response_2);
	printf("repeating adcs_response:\n%s\n", cJSON_Print(jsonadcs_response_2));
}

int main() {
  test_adcs_response(1);
  test_adcs_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // adcs_response_MAIN
#endif // adcs_response_TEST
