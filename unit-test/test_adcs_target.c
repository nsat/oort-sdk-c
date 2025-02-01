#ifndef adcs_target_TEST
#define adcs_target_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define adcs_target_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/adcs_target.h"
adcs_target_t* instantiate_adcs_target(int include_optional);



adcs_target_t* instantiate_adcs_target(int include_optional) {
  adcs_target_t* adcs_target = NULL;
  if (include_optional) {
    adcs_target = adcs_target_create(
      1.337,
      1.337
    );
  } else {
    adcs_target = adcs_target_create(
      1.337,
      1.337
    );
  }

  return adcs_target;
}


#ifdef adcs_target_MAIN

void test_adcs_target(int include_optional) {
    adcs_target_t* adcs_target_1 = instantiate_adcs_target(include_optional);

	cJSON* jsonadcs_target_1 = adcs_target_convertToJSON(adcs_target_1);
	printf("adcs_target :\n%s\n", cJSON_Print(jsonadcs_target_1));
	adcs_target_t* adcs_target_2 = adcs_target_parseFromJSON(jsonadcs_target_1);
	cJSON* jsonadcs_target_2 = adcs_target_convertToJSON(adcs_target_2);
	printf("repeating adcs_target:\n%s\n", cJSON_Print(jsonadcs_target_2));
}

int main() {
  test_adcs_target(1);
  test_adcs_target(0);

  printf("Hello world \n");
  return 0;
}

#endif // adcs_target_MAIN
#endif // adcs_target_TEST
