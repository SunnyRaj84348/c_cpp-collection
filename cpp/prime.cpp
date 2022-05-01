#include <iostream>

using namespace std;

class prime {
    int i, n, flag;

    public:
    prime() {
        flag = 0;
    }

    void in() {
        cout<<"\nEnter number: ";
        cin>>n;
    }

    void find() {
        for(i = 2; i <= n/2; i++) {
            if(n % i == 0) {
                flag = 1;
                break;
            }
        }
    }

    void show() {
        if(n == 1)
            cout<<"Undefined!"<<endl;
        else {
            if(flag == 1)
                cout<<n<<" is not a prime number"<<endl;
            else
                cout<<n<<" is a prime number"<<endl;
        }
    }
    
};

int main() {
    prime p;

    p.in();
    p.find();
    p.show();
}