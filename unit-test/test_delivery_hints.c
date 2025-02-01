#ifndef delivery_hints_TEST
#define delivery_hints_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define delivery_hints_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/delivery_hints.h"
delivery_hints_t* instantiate_delivery_hints(int include_optional);



delivery_hints_t* instantiate_delivery_hints(int include_optional) {
  delivery_hints_t* delivery_hints = NULL;
  if (include_optional) {
    delivery_hints = delivery_hints_create(
      "0",
      "0"
    );
  } else {
    delivery_hints = delivery_hints_create(
      "0",
      "0"
    );
  }

  return delivery_hints;
}


#ifdef delivery_hints_MAIN

void test_delivery_hints(int include_optional) {
    delivery_hints_t* delivery_hints_1 = instantiate_delivery_hints(include_optional);

	cJSON* jsondelivery_hints_1 = delivery_hints_convertToJSON(delivery_hints_1);
	printf("delivery_hints :\n%s\n", cJSON_Print(jsondelivery_hints_1));
	delivery_hints_t* delivery_hints_2 = delivery_hints_parseFromJSON(jsondelivery_hints_1);
	cJSON* jsondelivery_hints_2 = delivery_hints_convertToJSON(delivery_hints_2);
	printf("repeating delivery_hints:\n%s\n", cJSON_Print(jsondelivery_hints_2));
}

int main() {
  test_delivery_hints(1);
  test_delivery_hints(0);

  printf("Hello world \n");
  return 0;
}

#endif // delivery_hints_MAIN
#endif // delivery_hints_TEST
