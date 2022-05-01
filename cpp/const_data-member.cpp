#include <iostream>
using namespace std;

class A
{
    const int n;

    public:

    A() : n(20) {};

    void func()
    {
        cout<<n<<endl;
    }
};

int main()
{
    A a;
    a.func();

    return 0;
}