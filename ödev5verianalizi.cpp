#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
   
    std::srand(std::time(0));
  
    float veriler[500];

    for (int i = 0; i < 500; i++) {
        veriler[i] = static_cast<float>(std::rand()) / (static_cast<float>(RAND_MAX / 100)); 
    }

   
    for (int i = 0; i < 500; i++) {
        std::cout << veriler[i] << std::endl;
    }

    return 0;
}

