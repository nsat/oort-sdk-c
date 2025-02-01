#ifndef adcs_command_response_TEST
#define adcs_command_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define adcs_command_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/adcs_command_response.h"
adcs_command_response_t* instantiate_adcs_command_response(int include_optional);

#include "test_adcs_target.c"
#include "test_adcs_xyz_float_t.c"
#include "test_adcs_quat_t.c"


adcs_command_response_t* instantiate_adcs_command_response(int include_optional) {
  adcs_command_response_t* adcs_command_response = NULL;
  if (include_optional) {
    adcs_command_response = adcs_command_response_create(
      oort_agent_sdk_interface_adcs_command_response_STATUS_OK,
      "0",
      "0",
       // false, not to have infinite recursion
      instantiate_adcs_target(0),
       // false, not to have infinite recursion
      instantiate_adcs_xyz_float_t(0),
       // false, not to have infinite recursion
      instantiate_adcs_quat_t(0)
    );
  } else {
    adcs_command_response = adcs_command_response_create(
      oort_agent_sdk_interface_adcs_command_response_STATUS_OK,
      "0",
      "0",
      NULL,
      NULL,
      NULL
    );
  }

  return adcs_command_response;
}


#ifdef adcs_command_response_MAIN

void test_adcs_command_response(int include_optional) {
    adcs_command_response_t* adcs_command_response_1 = instantiate_adcs_command_response(include_optional);

	cJSON* jsonadcs_command_response_1 = adcs_command_response_convertToJSON(adcs_command_response_1);
	printf("adcs_command_response :\n%s\n", cJSON_Print(jsonadcs_command_response_1));
	adcs_command_response_t* adcs_command_response_2 = adcs_command_response_parseFromJSON(jsonadcs_command_response_1);
	cJSON* jsonadcs_command_response_2 = adcs_command_response_convertToJSON(adcs_command_response_2);
	printf("repeating adcs_command_response:\n%s\n", cJSON_Print(jsonadcs_command_response_2));
}

int main() {
  test_adcs_command_response(1);
  test_adcs_command_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // adcs_command_response_MAIN
#endif // adcs_command_response_TEST
