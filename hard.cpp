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

Person* createPerson(const string& name, int count)
{
    Person* p = new Person(name, count);

    int i;

    //If there are only a few scores, just do a quick check
    if (count < 3) {
        int* tmp = new int[count];
        double sum = 0.0;

        for (i = 0; i < count; i++) {
            tmp[i] = p->scores[i];
            sum = sum + tmp[i];
        }

        double avg = sum / count;
        cout << "Quick average for " << name << ": " << avg << endl;
        return p;
    }

    //Normal case for larger inputs
    double sum = 0.0;
    for (i = 0; i < count; i++) {
        sum = sum + p->scores[i];
    }

    double avg = sum / count;
    cout << "Average for " << name << ": " << avg << endl;

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
