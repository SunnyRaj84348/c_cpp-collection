#include <iostream>
using namespace std;

class A
{
    int n;

    public:
    A();

    void fun();

    friend class B;
};

class B
{
    int n;

    public:
    void fun(A&);
};    

A::A()
{
    n=5;
}

void B::fun(A& a)
{
    a.n=10;
}

void A::fun()
{
    cout<<"\nNew value of class A = "<< n << endl;
}


int main()
{
    A a;
    B b;

    b.fun(a);
    a.fun();
}