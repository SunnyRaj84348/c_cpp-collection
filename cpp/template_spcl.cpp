#include <iostream>

using namespace std;

template <typename t1>
class A {
    public:
    void print(t1 a) {
        cout<<a<<" is not char"<<endl;
    }
};

template<>
class A <char> {
    public:
    void print(char a) {
        cout<<a<<" is char"<<endl;
    }
};

int main() {
    A<int> a;
    A<float> a2;
    A<char> a3;

    a.print(5);
    a2.print(5.5);
    a3.print('B');
}