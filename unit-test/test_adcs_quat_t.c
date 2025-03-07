#ifndef adcs_quat_t_TEST
#define adcs_quat_t_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define adcs_quat_t_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/adcs_quat_t.h"
adcs_quat_t_t* instantiate_adcs_quat_t(int include_optional);



adcs_quat_t_t* instantiate_adcs_quat_t(int include_optional) {
  adcs_quat_t_t* adcs_quat_t = NULL;
  if (include_optional) {
    adcs_quat_t = adcs_quat_t_create(
      1.337,
      1.337,
      1.337,
      1.337
    );
  } else {
    adcs_quat_t = adcs_quat_t_create(
      1.337,
      1.337,
      1.337,
      1.337
    );
  }

  return adcs_quat_t;
}


#ifdef adcs_quat_t_MAIN

void test_adcs_quat_t(int include_optional) {
    adcs_quat_t_t* adcs_quat_t_1 = instantiate_adcs_quat_t(include_optional);

	cJSON* jsonadcs_quat_t_1 = adcs_quat_t_convertToJSON(adcs_quat_t_1);
	printf("adcs_quat_t :\n%s\n", cJSON_Print(jsonadcs_quat_t_1));
	adcs_quat_t_t* adcs_quat_t_2 = adcs_quat_t_parseFromJSON(jsonadcs_quat_t_1);
	cJSON* jsonadcs_quat_t_2 = adcs_quat_t_convertToJSON(adcs_quat_t_2);
	printf("repeating adcs_quat_t:\n%s\n", cJSON_Print(jsonadcs_quat_t_2));
}

int main() {
  test_adcs_quat_t(1);
  test_adcs_quat_t(0);

  printf("Hello world \n");
  return 0;
}

#endif // adcs_quat_t_MAIN
#endif // adcs_quat_t_TEST
