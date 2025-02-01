#ifndef adcs_hk_TEST
#define adcs_hk_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define adcs_hk_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/adcs_hk.h"
adcs_hk_t* instantiate_adcs_hk(int include_optional);

#include "test_adcs_euler_t.c"
#include "test_adcs_quat_t.c"
#include "test_adcs_quat_t.c"
#include "test_adcs_quat_t.c"
#include "test_adcs_xyz_float_t.c"
#include "test_adcs_xyz_float_t.c"
#include "test_adcs_xyz_float_t.c"
#include "test_adcs_xyz_float_t.c"
#include "test_adcs_quat_t.c"
#include "test_adcs_xyz_float_t.c"
#include "test_adcs_xyz_float_t.c"
#include "test_adcs_xyz_float_t.c"


adcs_hk_t* instantiate_adcs_hk(int include_optional) {
  adcs_hk_t* adcs_hk = NULL;
  if (include_optional) {
    adcs_hk = adcs_hk_create(
      1.337,
      "0",
       // false, not to have infinite recursion
      instantiate_adcs_euler_t(0),
       // false, not to have infinite recursion
      instantiate_adcs_quat_t(0),
      1.337,
       // false, not to have infinite recursion
      instantiate_adcs_quat_t(0),
      1.337,
      56,
      1.337,
      56,
       // false, not to have infinite recursion
      instantiate_adcs_quat_t(0),
      1.337,
       // false, not to have infinite recursion
      instantiate_adcs_xyz_float_t(0),
      1.337,
       // false, not to have infinite recursion
      instantiate_adcs_xyz_float_t(0),
       // false, not to have infinite recursion
      instantiate_adcs_xyz_float_t(0),
      "0",
       // false, not to have infinite recursion
      instantiate_adcs_xyz_float_t(0),
       // false, not to have infinite recursion
      instantiate_adcs_quat_t(0),
      56,
      1.337,
       // false, not to have infinite recursion
      instantiate_adcs_xyz_float_t(0),
       // false, not to have infinite recursion
      instantiate_adcs_xyz_float_t(0),
       // false, not to have infinite recursion
      instantiate_adcs_xyz_float_t(0)
    );
  } else {
    adcs_hk = adcs_hk_create(
      1.337,
      "0",
      NULL,
      NULL,
      1.337,
      NULL,
      1.337,
      56,
      1.337,
      56,
      NULL,
      1.337,
      NULL,
      1.337,
      NULL,
      NULL,
      "0",
      NULL,
      NULL,
      56,
      1.337,
      NULL,
      NULL,
      NULL
    );
  }

  return adcs_hk;
}


#ifdef adcs_hk_MAIN

void test_adcs_hk(int include_optional) {
    adcs_hk_t* adcs_hk_1 = instantiate_adcs_hk(include_optional);

	cJSON* jsonadcs_hk_1 = adcs_hk_convertToJSON(adcs_hk_1);
	printf("adcs_hk :\n%s\n", cJSON_Print(jsonadcs_hk_1));
	adcs_hk_t* adcs_hk_2 = adcs_hk_parseFromJSON(jsonadcs_hk_1);
	cJSON* jsonadcs_hk_2 = adcs_hk_convertToJSON(adcs_hk_2);
	printf("repeating adcs_hk:\n%s\n", cJSON_Print(jsonadcs_hk_2));
}

int main() {
  test_adcs_hk(1);
  test_adcs_hk(0);

  printf("Hello world \n");
  return 0;
}

#endif // adcs_hk_MAIN
#endif // adcs_hk_TEST
