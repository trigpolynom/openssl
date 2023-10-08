#include <stdio.h>
#include <assert.h>
#include "../include/internal/property.h"

void test_ossl_property_list_to_string() {
    OSSL_LIB_CTX *ctx = NULL;  // Assuming default context. You may need to initialize this if required.

    /* Create a property list */
    const char *property_str = "?fips=yes,input=der";
    OSSL_PROPERTY_LIST *pl = ossl_parse_property(ctx, property_str);

    /* Convert it back to string representation */
    char buffer[1024];
    size_t len = ossl_property_list_to_string(ctx, pl, buffer, sizeof(buffer));

    /* Assert the result */
    assert(len == strlen(property_str) + 1); // +1 for '\0'
    assert(strcmp(buffer, property_str) == 0);

    ossl_property_free(pl); // Clean up
    printf("Test passed!\n");
}

int main() {
    test_ossl_property_list_to_string();
    return 0;
}
