#include <iostream>
using namespace std;

class c1
{
  int n,m;
  public:

  c1(int, int);

  void showinfo();
  
};

c1::c1(int a, int b)
{
  n=a;
  m=b;
}

void c1::showinfo()
  {
    cout<<"Data= "<<n<<endl;
    cout<<"Data= "<<m<<endl;
  }

int main()
{
  c1 c(10, 50);
  c1 c2= c1(15,20);

  c.showinfo();
  c2.showinfo();
}