#include <iostream>
#include <string>

int vigenereIndex = -1;

int key(char a){                    
    int temp = (int)a;
    if(temp >=97 && temp <= 122){
        return temp - 97;
    }
    else return -1;
}
char fromkey(int x){  
    x+=26;
    return (char)((x%26)+97);
}

int myhash(std::string codeword){
    vigenereIndex++;
    vigenereIndex%=codeword.length();
    return key(codeword[vigenereIndex]);
}

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
    else{ //punctuation
        return c;
    }
}

std::string encryptCaesar(std::string plaintext, int rshift){
    std::string output;
    for(int i=0; i < plaintext.length(); i++){
    output += shiftChar(plaintext[i], rshift);
    }
    return output;
}

std::string encryptVigenere(std::string plaintext, std::string keyword){
    std::string output;
    char tempchar;
    bool plainCASE = true;
    vigenereIndex = -1; 
    for(int j=0; j<plaintext.length(); j++){
        tempchar = tolower(plaintext[j]);
        plainCASE = (plaintext[j] == tempchar);

        if((int)tempchar >= 97 && (int)tempchar <= 122){
            if(plainCASE){
                output += fromkey(myhash(keyword)+key(tempchar));            
            }
            else{
                output += toupper(fromkey(myhash(keyword)+key(tempchar)));
            }
        }
        else{
            output += plaintext[j];
        }
    }
    return output;
}

std::string decryptCaesar(std::string ciphertext, int rshift){   
    return encryptCaesar(ciphertext, 0-rshift);
}

std::string decryptVigenere(std::string ciphertext, std::string keyword){ 
    std::string output;
    char temp;
    bool plainCASE = true;
    vigenereIndex = -1; 
    for(int j=0; j<ciphertext.length(); j++){
        
        temp = tolower(ciphertext[j]);
        plainCASE = (ciphertext[j] == temp);

        if((int)temp >= 97 && (int)temp <= 122){
            if(plainCASE){
                output += fromkey(key(temp)-myhash(keyword));            
            }
            else{
                output += toupper(fromkey(key(temp)-myhash(keyword)));
            }
        }
        else output += ciphertext[j];
    }
    return output;
}
