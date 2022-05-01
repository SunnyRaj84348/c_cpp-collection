#include <iostream>
using namespace std;

void dec2bin(int dec) {
    if(dec <= 0) {
        return;
    }

    dec2bin(dec/2);
    cout << dec%2;
}

int main() {
    int num;
    cout << "Enter number: ";
    cin >> num;

    if(num == 0) {
        cout << 0;
    }
    else {
        dec2bin(num);
    }
    
    cout << " ";

    return 0; 
}