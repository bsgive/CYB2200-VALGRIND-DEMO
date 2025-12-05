// leak3_subtle.cpp
#include <iostream>
#include <string>

using namespace std;

struct Person {

    string name;
    int* scores;
    int count;

    Person(const string& n, int c) {
        name = n;
        count = c;
        scores = new int[count];

        for (int i = 0; i < count; i++) {
            scores[i] = i * 5;
        }
    }

    Person() 
    {
        delete[] scores;
    }
};

Person* createPerson(const string& name, int count) 
{
    Person* p = new Person(name, count);

    if (count < 3) {
        int* tmp = new int[10];
        tmp[0] = 42;

        if (tmp[0] > 0) {
            return p;
        }

        delete[] tmp;
    }

    return p;
}

int main() 
{
    Person* a = createPerson("Alice", 2);
    Person* b = createPerson("Bob", 5);

    cout << "Person A: " << a->name << ", score0 = " << a->scores[0] << endl;
    cout << "Person B: " << b->name << ", score0 = " << b->scores[0] << endl;

    delete a;
    delete b;

    return 0;
}
