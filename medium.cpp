// leak2.cpp
#include <iostream>
#include <vector>

using namespace std;

void fill(vector<int*>& v, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        // Allocate memory dynamically
        int* value = new int(i * 10);
        // Store pointer in vector
        v.push_back(value);
    }
}

int main() 
{

    //Allocate Vector
    vector<int*> data;
    fill(data, 5);

    cout << "Values: ";
    for (int i = 0; i < data.size(); i++) {
        cout << *data[i] << " ";
    }
    cout << endl;

    //Free allocated Memory of Vector
    data.clear();

    cout << "Done." << endl;
    return 0;
}