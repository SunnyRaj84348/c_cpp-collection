#include <iostream>
using namespace std;

class cl
{
   int x,y,z;
   int arr[2];

   public:
   cl(int p, int q, int r)
   {
      x=p, y=q, z=r;
   }

   void fun()
   {
      arr[0]=x;
      arr[1]=y;

      cout<<arr[z];
   }
};

int main()
{
   cl l(2,5,0);
   l.fun();

   return 0;
}