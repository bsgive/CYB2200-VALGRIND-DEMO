#include <iostream>

int main(){
    int *n = new int(10);

    std::cout << "Value " << *n << std::endl;
    //delete n;
    std::cout << "Value " << *n << std::endl;
    delete n;
    return 0;
}