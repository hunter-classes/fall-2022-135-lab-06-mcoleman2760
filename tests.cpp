#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

TEST_CASE("Caesar Cipher Encryption") {
CHECK(encryptCaesar("Hello, World!", 10) == ""Hello, World!"");
CHECK(fact(1) == 1);
}
