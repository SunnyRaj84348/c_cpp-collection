#include <iostream>

using namespace std;

class Stud {
    string nm;
    int n;
    static int marks;

public:
    void inp() {
        cin.ignore();

        cout << "\nEnter name of student: ";
        getline(cin, nm);

        cout << "Enter marks: ";
        cin >> n;

        marks += n;
    }

    static void show() {
        cout << "\nTotal marks = " << marks << endl;
    }
};

int Stud :: marks;

int main() {
    int n;
    cout << "\nEnter total no. of students: ";
    cin >> n;

    Stud* s;
    
    if( !(s = new Stud[n]) ) {
        cout << "\nOut of memory!\n";
        exit(1);
    }

    for(int i = 0; i < n; i++)
        s[i].inp();
    
    delete [] s;

    Stud :: show();

    return 0;
}