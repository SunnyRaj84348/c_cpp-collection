#include <iostream>
using namespace std;

class fibo {
    int n, n1, n2, temp;

    public:
    fibo() : n1(0), n2(1) {}

    void read() {
        cout << "\nEnter n number of terms: ";
        cin >> n;
    }

    void show() {
        for(int i = 1; i <= n; i++) {
            cout << n1 << ' ';
            
            temp = n1 + n2;
            n2 = n1;
            n1 = temp;
        }

        cout << endl;    
    }
};

int main() {
    fibo f;

    f.read();
    f.show();

    return 0;
}