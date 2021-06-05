#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll players[100005];
ll umpires[100005];

int main() {
    int n;
    cin >> n;
    ll sumPlayers = 0;
    ll sumUmpires = 0;
    for (int i = 0; i < n; i++) {
        cin >> players[i] >> umpires[i];
        sumPlayers += players[i];
        sumUmpires += umpires[i];
    }
    ll squares = 0;
    ll pairs = 0;
    ll playerPairs = 0;
    for (int i = 0; i < n; i++) {
        squares += players[i] * players[i];
        pairs += players[i] * umpires[i];
        playerPairs += players[i] * players[i] * umpires[i];
    }
    ll ans = 0;
    ans += sumPlayers * sumPlayers * sumUmpires;
    ans -= squares * sumUmpires;
    ans /= 2;
    ans -= pairs * sumPlayers;
    ans += playerPairs;
    cout << ans << endl;
}
