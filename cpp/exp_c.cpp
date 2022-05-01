#include <iostream>
using namespace std;

class Herewego
{
    public:
    Herewego(int a, int b)
    {
        cout<<"sum=" <<a+b<<endl;
    }
};

int main()
{
    Herewego h1(2,5);
    Herewego h2(5,5);
}