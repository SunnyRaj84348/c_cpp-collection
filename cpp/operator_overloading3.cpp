#include <iostream>

using namespace std;

class A {
    int n;

public:
    friend istream& operator >>(istream&, A&);
    friend ostream& operator <<(ostream&, A&);
};

istream& operator >>(istream& input, A& obj) {
    input >> obj.n;

    return input;
}

ostream& operator <<(ostream& output, A& obj) {
    output << obj.n;

    return output;
}

int main() {
    A a, b;

    cout << "\nEnter two value: ";
    cin >> a >> b;

    cout << "\nValues = " << a <<
            " and " << b << endl;

    return 0;
}