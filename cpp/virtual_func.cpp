#include <iostream>
using namespace std;

class base {
public:
    virtual void func() = 0;
};

class d : public base {
public:
    void func() {
        cout<<"d"<<endl;
    }
};

class d2 : public base {
public:
    void func() {
        cout<<"d2"<<endl;
    }
};

int main() {
    d a;
    d2 b;

    base *b1 = &a;
    base *b2 = &b;

    b1->func();
    b2->func();
}