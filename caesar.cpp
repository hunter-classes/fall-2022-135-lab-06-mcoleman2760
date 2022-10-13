#include <iostream>
#include <string>


char shiftChar(char c, int rshift){
char a = c;
  
  for (int i = 0; i < rshift; i++){
    a += 1;
    if(c >= 'A' && c <= 'Z' && a > 'Z' ){
      a = 'A';  
    }
    if(c >= 'a' && c <= 'z' && a > 'z' ){
      a = 'a';  
    } 
  } 
    
    return a;

}

std::string encryptCaesar(std::string plaintext, int rshift){
  std::string d = "";
  
 for (int i = 0 ; i < plaintext.length(); i++){
   char newc = plaintext[i];
   if (isalpha(newc)){
     newc = shiftChar(newc, rshift);
   }
   
   d = d + newc;
    
    
     }
 return d;
  
}
