#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream file("file.txt", ios::trunc | ios::in | ios::out);

    char s;

    cout << "\nReading mode started";
    cout << " (Press 1 to stop)" << endl;

    try {
        while(file) {
            cin.get(s);

            if(s == '1')
                break;

            if(s == '@')
                throw 1;
            
            file.put(s);
        }

        //cin.ignore();
        file.seekg(0);

        cout << "\nWriting texts from file" << endl;

        while(file) {
            file.get(s);

            cout << s;
        }

        file.close();
    }
    catch(int n) {
        cout << "\n@ symbol not allowed!";
        file.close();
    }
}