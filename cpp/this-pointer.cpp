#include <iostream>
using namespace std;

class My
{
    int a;
    public:

    My();

    void prin(int);
};

My::My()
{
    a=10;
}

void My::prin(int a)
{
    cout<<"Value= "<<this->a<<endl;
}

int main()
{
    My m;
    m.prin(5);
}