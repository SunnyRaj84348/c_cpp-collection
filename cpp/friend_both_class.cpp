#include <iostream>
using namespace std;

class B;

class A
{
    int n;
    public:
    A()
    {
        n=10;
    }

    void fun(B&);

    friend class B;
};

class B
{
    int n;

    public:
    B()
    {
        n=5;
    }

    void fun(A&);

    friend class A;
};

void A::fun(B& b)
{
    cout<<"Value of B = "<<b.n<<endl;
}

void B::fun(A& a)
{
    cout<<"Value of A = "<<a.n<<endl;
}

int main()
{
    A a;
    B b;

    a.fun(b);
    b.fun(a);
}