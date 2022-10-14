#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "caesar.h"
#include "vigenere.h"
#include "decrypt.h"


TEST_CASE("Caesar Cipher Encryption") {
CHECK(encryptCaesar("Hello, World!", 10) == "Hello, World!");
CHECK(encryptCaesar("Way to Go!", 5)== "Bfd yt Lt!");
}

TEST_CASE("Vigenere Cipher Encryption"){
CHECK(encryptVigenere("Hello, World!","cake") == "Jevpq, Wyvnd!");
CHECK(encryptVigenere("I am safe!","dog") == "O da ydtk!");  
}
TEST_CASE("Decryption"){
CHECK(decryptCaesar("Rovvy, Gybvn!", 10) == "Hello, World!")
CHECK(decryptVigenere("Jevpq, Wyvnd!", "cake") == "Hello, World!")
  }


