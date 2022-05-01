#include <iostream>
using namespace std;

void func(string s) {
    int tot_word = 1;

    for(auto i : s)
        if(i == ' ')
            tot_word++;
        
    string arr[tot_word];

    // Sometimes hex does the job
    s += ' ';

    for(int i = 0, j = 0; i < s.size(); i++) {
        if(s[i] != ' ')
            arr[j] += s[i];
        else {
            arr[j] += arr[j][0];
            arr[j].erase(0, 1);
            
            if(arr[j][0] != '!') {
                arr[j] += "ay";

                if(j != tot_word-1)
                    arr[j] += ' ';
            }

            j++;
        }
    }

    for(auto i : arr)
        cout << i;
}

int main() {
    func("Hello There !");

    return 0;
}