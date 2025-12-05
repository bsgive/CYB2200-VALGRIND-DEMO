#include <iostream>
using namespace std;
int main() 
{
    int* x = new int(10);         
    int* arr = new int[50];       

    cout << "Value: " << *x << "\n";
    arr[0] = 1;
    cout << "First element of arr: " << arr[0] << "\n";

    cout << "Program finished.\n";
    return 0;
}