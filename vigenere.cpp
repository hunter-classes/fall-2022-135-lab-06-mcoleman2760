#include <iostream>
#include <string>

int key(char a){                    
    int temp = (int)a;
    if(temp >= 97 && temp <= 122){
        return temp - 97;
    }
    else {
      return -1;
        };
}
char fromkey(int b){               
     b = b + 26;
    return (char)((b%26)+97);
}

int myhash(std::string code){
    int static  i = -1;
    i++;
    i%=code.length();
    return key(code[i]);
}


  

std::string encryptVigenere(std::string plaintext, std::string keyword) {

    
 std::string encrypt;
 char tempchar;
  
    bool plainCASE = true; 
    for(int j=0; j<plaintext.length(); j++){
        tempchar = tolower(plaintext[j]);
        plainCASE = (plaintext[j] == tempchar);

        if((int)tempchar >= 97 && (int)tempchar <= 122){
            if(plainCASE){
                encrypt += fromkey(myhash(keyword)+key(tempchar));            
            }
            else{
                encrypt += toupper(fromkey(myhash(keyword)+key(tempchar)));
            }

      }
        else{
            encrypt += plaintext[j];
        }
    }
    return encrypt;
}
