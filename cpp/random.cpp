#include <iostream>
using namespace std;

class newc
{
    public:
    int sum(int a, int b)
    {
        return a+b;
    }

    float sum(float a, float b)
    {
        return a+b;
    }

    float sum(int a, float b)
    {
        return a+b;
    }
};

int main()
{
    newc c1;
    int a,b;
    float c,d;

    cout<<"\nEnter two numbers: ";
    cin>>a>>b;
    cout<<"Sum= "<<c1.sum(a,b)<<endl;

    cout<<"\nEnter two numbers: ";
    cin>>c>>d;
    cout<<"Sum= "<<c1.sum(c,d)<<endl;

    cout<<"\nEnter two numbers: ";
    cin>>a>>d;
    cout<<"Sum= "<<c1.sum(a,d)<<endl;

    return 0;

}