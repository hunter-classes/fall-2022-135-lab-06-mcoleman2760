#include <iostream>
#include <string>

int main() {
  std::string a = ""; 
  std::cout << "Input: " ;
  getline(std::cin, a);
std::cout << std::endl;   
 
  for (int i = 0 ; i < a.length(); i++){
     
     std::cout << a.substr(i , 1) <<  " " << int(a[i])<<  std::endl;
    
     }
  }
 
