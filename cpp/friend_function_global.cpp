#include <iostream>
using namespace std;

class B;

class A
{
    int n;

    public:
    A()
    {
        n=5;
    }

    friend void fun(A&, B&);
};

class B
{
    int n;

    public:
    B()
    {
        n=10;
    }

    friend void fun(A&, B&);
};

void fun(A& a, B& b)
{
    cout<<"Value of class A = "<<a.n<<endl;
    cout<<"Value of class B = " <<b.n<<endl;
}

int main()
{
    A a;
    B b;

    fun(a, b);

}