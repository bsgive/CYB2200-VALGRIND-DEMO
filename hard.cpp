#include <iostream>
#include <string>

using namespace std;

struct Person {

    string name;
    int* scores;
    int count;

    Person(const string& n, int c)
    {
        name = n;
        count = c;
        scores = new int[count];

        for (int i = 0; i < count; i++) 
        {
            scores[i] = i * 5;
        }
    }
    ~Person()
    {
        delete[] scores;
    }
};

Person* AddSum(const string& name, int count)
{
    Person* p = new Person(name, count);

    int i;
    int* tmp = new int[count];

    //If there are only a few scores, just do a quick check
    if (count < 3) {
        int sum = 0;

        for (i = count; i > 0; i--) {
            sum = sum + i;
        }

        cout << "Quick sum for " << name << ": " << sum << endl;
        return p;
    }

    //Normal case for larger inputs
    int sum = 0;
    for (i = count; i > 0; i--) {
        tmp[i - 1] = i;
        sum = sum + i;
    }

    cout << "Sum for " << name << ": " << sum << endl;
    delete[] tmp;
    return p;
}

int main() 
{
    Person* a = AddSum("Alice", 2);
    Person* b = AddSum("Bob", 5);

    cout << "Person A: " << a->name << ", score0 = " << a->scores[0] << endl;
    cout << "Person B: " << b->name << ", score0 = " << b->scores[0] << endl;

    delete a;
    delete b;

    return 0;
}
