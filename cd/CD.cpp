#include <bits/stdc++.h>
using namespace std;
int Jack[1000001]; //Jack CD catalog
int Jill[1000001]; //Jill CD catalog
int main() {
    ios::sync_with_stdio;
    cin.tie(0);cout.tie(0);
    int n,m;
    while(cin >> n >> m) {
        if(n == 0 && m == 0) {
            break;
        } else {
            for(int i = 0; i<n; i++) {
                cin >> Jack[i]; 
            }
            for(int i = 0; i<m; i++) {
                cin >> Jill[i];
            }
            int traverseJack = 0;
            int traverseJill = 0;
            int ans = 0;
            while(traverseJack < n && traverseJill < m) {
                if(Jack[traverseJack] == Jill[traverseJill]) {
                    ans += 1;
                    traverseJack += 1;
                    traverseJill += 1;
                } else if (Jack[traverseJack] > Jill[traverseJill]) {
                    traverseJill += 1;
                } else {
                    traverseJack += 1;
                }
            }
            cout << ans << endl;
        }
    }
}