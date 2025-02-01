#ifndef send_file_response_TEST
#define send_file_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define send_file_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/send_file_response.h"
send_file_response_t* instantiate_send_file_response(int include_optional);



send_file_response_t* instantiate_send_file_response(int include_optional) {
  send_file_response_t* send_file_response = NULL;
  if (include_optional) {
    send_file_response = send_file_response_create(
      "0"
    );
  } else {
    send_file_response = send_file_response_create(
      "0"
    );
  }

  return send_file_response;
}


#ifdef send_file_response_MAIN

void test_send_file_response(int include_optional) {
    send_file_response_t* send_file_response_1 = instantiate_send_file_response(include_optional);

	cJSON* jsonsend_file_response_1 = send_file_response_convertToJSON(send_file_response_1);
	printf("send_file_response :\n%s\n", cJSON_Print(jsonsend_file_response_1));
	send_file_response_t* send_file_response_2 = send_file_response_parseFromJSON(jsonsend_file_response_1);
	cJSON* jsonsend_file_response_2 = send_file_response_convertToJSON(send_file_response_2);
	printf("repeating send_file_response:\n%s\n", cJSON_Print(jsonsend_file_response_2));
}

int main() {
  test_send_file_response(1);
  test_send_file_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // send_file_response_MAIN
#endif // send_file_response_TEST
