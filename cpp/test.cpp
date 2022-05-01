#include <iostream>
using namespace std;

class New {
    int *arr;

public:
    New(int size) {
        arr = new int[size];
    }

    ~New() {
        delete[] arr;
    }

    void input(int size) {
        for(int i = 0; i < size; i++)
            cin >> arr[i];
    }

    void search(int size, int key) {
        bool flag = false;

        for(int i = 0; i < size; i++) {
            if(arr[i] == key) {
                cout << "\nElement founded at index " << i << endl;
                flag = true;
                break;
            }
        }

        if(!flag)
            cout << "\nElement not founded!" << endl;
    }
};

int main() {
    int size, key;

    cout << "\nEnter no. of element to create: ";
    cin >> size;

    New obj(size);

    cout << "\nEnter array data: ";
    obj.input(size);

    cout << "\nEnter element to search: ";
    cin >> key;

    obj.search(size, key);

    return 0;
}