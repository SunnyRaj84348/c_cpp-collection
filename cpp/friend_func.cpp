#include <iostream> 
  
class A { 
    int a; 
  
public: 
    A() { a = 0; } 
  
    // global friend function 
    friend void showA(A&);

    void func()
    {
        std::cout<<"Original value= "<<a<<std::endl;
    }
}; 
  
void showA(A& x)
{ 
    // Since showA() is a friend, it can access 
    // private members of A
    x.a=10;
    std::cout << "A::a=" << x.a<<std::endl; 
} 
  
int main() 
{ 
    A a; 
    showA(a);
    a.func();
    return 0; 
}