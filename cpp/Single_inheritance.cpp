#include <iostream>
using namespace std;

class A
{
    public:
    int n;

    A()
    {
        n=20;
    }
};

class B : private A
{
    public:
    void show()
    {
        cout<<"Value of base class A = "<<n<<endl;
    }
};

int main()
{
    B b;

    b.show();
}