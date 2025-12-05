#include <iostream>
#include <vector>

using namespace std;

void fill(vector<int*>& v, int n) 
{
    for (int i = 0; i < n; i++) 
    {
        int* value = new int(i * 10);
        v.push_back(value);
    }
}

int main() 
{
    vector<int*> data;
    fill(data, 5);

    cout << "Values: ";
    for (int i = 0; i < data.size(); i++) {
        cout << *data[i] << " ";
    }
    cout << endl;
    
    data.clear();

    cout << "Done." << endl;
    return 0;
}