#include <iostream>

using namespace std;

class A {
private:
    int arr[5];

public:
    void input() {
        for(int i = 0; i < 5; i++)
            cin >> arr[i];
    }

    void output() {
        for(int i = 0; i < 5; i++)
            cout << arr[i] << " ";
    }

    friend void sort(A& a);
};

void sort(A& a) {
    int temp, min;

    for(int i = 0; i < 4; i++) {
        min = i;

        for(int j = i+1; j < 5; j++) {
            if(a.arr[j] < a.arr[min])
                min = j;
        }

        temp = a.arr[i];
        a.arr[i] = a.arr[min];
        a.arr[min] = temp;
    }
}

int main() {
    A obj;

    cout << "\nEnter data: ";
    obj.input();

    sort(obj);

    cout << "\nSorted Array: ";
    obj.output();

    return 0;
}