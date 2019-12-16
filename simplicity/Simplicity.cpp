#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio;
    cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    int ans = 0;
    int minimum = 101;
    int simplicity = 0;
    int numberOfCharacters[26];
    //initialize array
    for(int i = 0; i<26; i++) {
        numberOfCharacters[i] = 0;
    }
    //insert array with amount of characters
    for(int i = 0; i<s.length(); i++) {
        int character = (int)s.at(i) - 'a';
        numberOfCharacters[character] += 1;
    }
    //count original simplicity number
    for(int i = 0; i<26; i++) {
        if(numberOfCharacters[i] != 0) {
            simplicity += 1;
        }
    }
    //reduce simplicity
    while(simplicity > 2) {
        //find minimum number of characters
        for(int i = 0; i<26; i++) {
            if(numberOfCharacters[i] != 0) {
                minimum = min(minimum, numberOfCharacters[i]);
            }   
        }
        //remove characters from string
        for(int i = 0; i<26; i++) {
            if(numberOfCharacters[i] == minimum && simplicity > 2) {
                ans += numberOfCharacters[i];
                simplicity -= 1;
                numberOfCharacters[i] = 0;
            }
        }
        minimum = 101; //reset minimum   
    }
    cout << ans << endl;
}