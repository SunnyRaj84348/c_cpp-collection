#include <iostream>
#include <cstring>
using namespace std;

class A
{
    char nm[20];

    public:
    void getF()
    {
        cout<<"Enter first name: ";
        cin>>nm;
    }

    void getL()
    {
        cout<<"Enter last name: ";
        cin>>nm;
    }

    void showNm();

    A operator +(A b);
};

void A :: showNm()
{
    cout<<"Full name = "<<nm;
}

A A :: operator +(A b)
{
    A c;

    strcpy(c.nm, nm);
    strcat(c.nm, " ");
    strcat(c.nm, b.nm);

    return c;
}

int main()
{
    A a;
    A b;
    A c;

    a.getF();
    b.getL();

    c = a+b;

    c.showNm();
}