#ifndef adcs_command_request_TEST
#define adcs_command_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define adcs_command_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/adcs_command_request.h"
adcs_command_request_t* instantiate_adcs_command_request(int include_optional);

#include "test_adcs_target.c"
#include "test_adcs_xyz_float_t.c"
#include "test_adcs_quat_t.c"


adcs_command_request_t* instantiate_adcs_command_request(int include_optional) {
  adcs_command_request_t* adcs_command_request = NULL;
  if (include_optional) {
    adcs_command_request = adcs_command_request_create(
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_adcs_target(0),
      1.337,
       // false, not to have infinite recursion
      instantiate_adcs_xyz_float_t(0),
       // false, not to have infinite recursion
      instantiate_adcs_quat_t(0)
    );
  } else {
    adcs_command_request = adcs_command_request_create(
      "0",
      "0",
      NULL,
      1.337,
      NULL,
      NULL
    );
  }

  return adcs_command_request;
}


#ifdef adcs_command_request_MAIN

void test_adcs_command_request(int include_optional) {
    adcs_command_request_t* adcs_command_request_1 = instantiate_adcs_command_request(include_optional);

	cJSON* jsonadcs_command_request_1 = adcs_command_request_convertToJSON(adcs_command_request_1);
	printf("adcs_command_request :\n%s\n", cJSON_Print(jsonadcs_command_request_1));
	adcs_command_request_t* adcs_command_request_2 = adcs_command_request_parseFromJSON(jsonadcs_command_request_1);
	cJSON* jsonadcs_command_request_2 = adcs_command_request_convertToJSON(adcs_command_request_2);
	printf("repeating adcs_command_request:\n%s\n", cJSON_Print(jsonadcs_command_request_2));
}

int main() {
  test_adcs_command_request(1);
  test_adcs_command_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // adcs_command_request_MAIN
#endif // adcs_command_request_TEST
