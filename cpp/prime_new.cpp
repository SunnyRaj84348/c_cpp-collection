#include <iostream>
using namespace std;

class primeNumber {
    protected:
    bool flag = true;
    int n;

    public:
    void get();
    void find();
    void show();
};

class derived : public primeNumber {
    int n2;

    public:
    void get();
    void find();
};

void primeNumber :: get() {
    cout << "\nEnter number: ";
    cin >> n;
}

void primeNumber :: find() {
    if(n == 1 || n == 0) {
        flag = !flag;
        return;
    }

    for(int i = 2; i <= n/2; i++) {
        if(n % i == 0) {
            flag = !flag;
            break;
        }
    }
}

void primeNumber :: show() {
    if(flag)
        cout << endl << n << " is a prime number" << endl;
    else
        cout << endl << n << " is not a prime number" << endl;
}

void derived :: get() {
    cout << "\nEnter 2 numbers: ";
    cin >> n >> n2;
}

void derived :: find() {
    if(n == 0)
        n++;

    cout << "\nPrime numbers: " << endl;

    for(int i = n; i <= n2; i++) {
        if(i == 1)
            continue;

        for(int j = 2; j <= i/2; j++) {
            if(i % j == 0) {
                flag = !flag;
                break;
            }
        }

        if(flag)
            cout << i << endl;
        
        flag = true;
    }
}

int main() {
   primeNumber p;
   derived d;

/*
   p.get();
   p.find();
   p.show();
*/

   d.get();
   d.find();
}