#include <iostream>
using namespace std;

class A
{
    int n;

    public:
    A()
    {
        n=10;
    }

    A(int n)
    {
        this->n=n;
    }

    int operator ==(A& b)
    {
        if(n==b.n)
        return 1;
        else
        return 0;
    }
};

class B : public A
{
    public:
    B(A& a, A& b)
    {
        if(a==b)
        printf("Equal");
        else
        printf("Not equal");
    }
};

int main()
{
    A a;
    A b(20);
    B c(a,b);
}