#ifndef ttl_params_TEST
#define ttl_params_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define ttl_params_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/ttl_params.h"
ttl_params_t* instantiate_ttl_params(int include_optional);



ttl_params_t* instantiate_ttl_params(int include_optional) {
  ttl_params_t* ttl_params = NULL;
  if (include_optional) {
    ttl_params = ttl_params_create(
      56,
      56,
      56
    );
  } else {
    ttl_params = ttl_params_create(
      56,
      56,
      56
    );
  }

  return ttl_params;
}


#ifdef ttl_params_MAIN

void test_ttl_params(int include_optional) {
    ttl_params_t* ttl_params_1 = instantiate_ttl_params(include_optional);

	cJSON* jsonttl_params_1 = ttl_params_convertToJSON(ttl_params_1);
	printf("ttl_params :\n%s\n", cJSON_Print(jsonttl_params_1));
	ttl_params_t* ttl_params_2 = ttl_params_parseFromJSON(jsonttl_params_1);
	cJSON* jsonttl_params_2 = ttl_params_convertToJSON(ttl_params_2);
	printf("repeating ttl_params:\n%s\n", cJSON_Print(jsonttl_params_2));
}

int main() {
  test_ttl_params(1);
  test_ttl_params(0);

  printf("Hello world \n");
  return 0;
}

#endif // ttl_params_MAIN
#endif // ttl_params_TEST
