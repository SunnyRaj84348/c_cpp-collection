#include <iostream>
using namespace std;

class My
{
    string *p;
    public:

    My()
    {
        p = new string;
        *p = "hello";
    }

    My(string x)
    {
        p = new string;
        *p = x;
    }

    ~My() {
        delete p;
    }

    string disp()
    {
        return (*p);
    }
};

int main()
{
    My c1, c2("world");

    cout<<c1.disp()<<" "<<c2.disp();
}