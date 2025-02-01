#ifndef send_options_TEST
#define send_options_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_options_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_options.h"
send_options_t* instantiate_send_options(int include_optional);

#include "test_ttl_params.c"


send_options_t* instantiate_send_options(int include_optional) {
  send_options_t* send_options = NULL;
  if (include_optional) {
    send_options = send_options_create(
       // false, not to have infinite recursion
      instantiate_ttl_params(0),
      1,
      list_createList(),
      list_createList()
    );
  } else {
    send_options = send_options_create(
      NULL,
      1,
      list_createList(),
      list_createList()
    );
  }

  return send_options;
}


#ifdef send_options_MAIN

void test_send_options(int include_optional) {
    send_options_t* send_options_1 = instantiate_send_options(include_optional);

	cJSON* jsonsend_options_1 = send_options_convertToJSON(send_options_1);
	printf("send_options :\n%s\n", cJSON_Print(jsonsend_options_1));
	send_options_t* send_options_2 = send_options_parseFromJSON(jsonsend_options_1);
	cJSON* jsonsend_options_2 = send_options_convertToJSON(send_options_2);
	printf("repeating send_options:\n%s\n", cJSON_Print(jsonsend_options_2));
}

int main() {
  test_send_options(1);
  test_send_options(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_options_MAIN
#endif // send_options_TEST
