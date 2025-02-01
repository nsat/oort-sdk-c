#ifndef adcs_xyz_float_t_TEST
#define adcs_xyz_float_t_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define adcs_xyz_float_t_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/adcs_xyz_float_t.h"
adcs_xyz_float_t_t* instantiate_adcs_xyz_float_t(int include_optional);



adcs_xyz_float_t_t* instantiate_adcs_xyz_float_t(int include_optional) {
  adcs_xyz_float_t_t* adcs_xyz_float_t = NULL;
  if (include_optional) {
    adcs_xyz_float_t = adcs_xyz_float_t_create(
      1.337,
      1.337,
      1.337
    );
  } else {
    adcs_xyz_float_t = adcs_xyz_float_t_create(
      1.337,
      1.337,
      1.337
    );
  }

  return adcs_xyz_float_t;
}


#ifdef adcs_xyz_float_t_MAIN

void test_adcs_xyz_float_t(int include_optional) {
    adcs_xyz_float_t_t* adcs_xyz_float_t_1 = instantiate_adcs_xyz_float_t(include_optional);

	cJSON* jsonadcs_xyz_float_t_1 = adcs_xyz_float_t_convertToJSON(adcs_xyz_float_t_1);
	printf("adcs_xyz_float_t :\n%s\n", cJSON_Print(jsonadcs_xyz_float_t_1));
	adcs_xyz_float_t_t* adcs_xyz_float_t_2 = adcs_xyz_float_t_parseFromJSON(jsonadcs_xyz_float_t_1);
	cJSON* jsonadcs_xyz_float_t_2 = adcs_xyz_float_t_convertToJSON(adcs_xyz_float_t_2);
	printf("repeating adcs_xyz_float_t:\n%s\n", cJSON_Print(jsonadcs_xyz_float_t_2));
}

int main() {
  test_adcs_xyz_float_t(1);
  test_adcs_xyz_float_t(0);

  printf("Hello world \n");
  return 0;
}

#endif // adcs_xyz_float_t_MAIN
#endif // adcs_xyz_float_t_TEST
