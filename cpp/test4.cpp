#include <iostream>
using namespace std;

int main() {
    string name, name2, lname;

    cout << "Enter name: ";
    getline(cin, name);

    name2 = name[0];

    for(int i = 0; i < name.size(); i++) {
        if(name[i] == ' ') {
            name2 += '.';
            name2 += name[i+1];
            
            lname = "";
            continue;
        }

        lname += name[i];
    }
    
    name2[name2.size()-1] = ' ';
    name2 += lname;

    cout << name2 << endl;

    return 0;
}