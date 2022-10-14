#include <iostream>
#include <string>


char shiftChar(char c, int rshift){
char temp = tolower(c);
    int raw = ((int)temp - 97 + rshift);
    raw += 26;
    raw =  raw % 26;
    raw += 97;
    temp = (char)raw;

    if((int)c >= 65 && (int)c <= 90){ 
        temp = toupper(temp);
        return temp;
    }

    if((int)c >= 97 && (int)c <= 122){ 
        return temp;
    }
    else{
        return c;
    }
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
