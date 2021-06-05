#include <bits/stdc++.h>
using namespace std;
#define ANY 0
#define TOP 1
#define BOTTOM 2

int topRow[205];
int bottomRow[205];

int dp[205][205][3];

int solve(int n, int k, int flag) {
    // Flag indicates which part must be blocked
    if (dp[n][k][flag] != -1) {
        return dp[n][k][flag];
    }
    int top = topRow[n - 1];
    int bottom = bottomRow[n - 1];
    if (flag == ANY) {
        int chooseTop = solve(n - 1, k - 1, BOTTOM);
        int chooseBottom = solve(n - 1, k - 1, TOP);
        int noBlock = solve(n - 1, k, ANY);
        int topValid = chooseTop == 0 ? 0 : top + chooseTop;
        int bottomValid = chooseBottom == 0 ? 0 : bottom + chooseBottom;
        int noBlockValid = noBlock == 0 ? 0 : bottom + top + noBlock;
        dp[n][k][0] = max(topValid, max(bottomValid, noBlockValid));
    } else if (flag == TOP) {
        int continueBlock = solve(n - 1, k - 1, TOP);
        int noBlock = solve(n - 1, k, ANY);
        int continueBlockValid = continueBlock == 0 ? 0 : bottom + continueBlock;
        int noBlockValid = noBlock == 0 ? 0 : bottom + top + noBlock; 
        dp[n][k][1] = max(continueBlockValid, noBlockValid);
    } else {
        int continueBlock = solve(n - 1, k - 1, BOTTOM);
        int noBlock = solve(n - 1, k, ANY);
        int continueBlockValid = continueBlock == 0 ? 0 : top + continueBlock;
        int noBlockValid = noBlock == 0 ? 0 : bottom + top + noBlock; 
        dp[n][k][2] = max(continueBlockValid, noBlockValid);
    }
    return dp[n][k][flag];
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        cin >> topRow[i] >> bottomRow[i];
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
            dp[i][j][2] = -1;
        }
    }
    for (int i = 0; i <= k; i++) {
        dp[0][i][0] = 0;
        dp[0][i][1] = 0;
        dp[0][i][2] = 0;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (j > i) {
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
                dp[i][j][2] = 0;
            }
        }
    }
    dp[1][1][0] = max(bottomRow[0], topRow[0]);
    dp[1][1][1] = bottomRow[0];
    dp[1][1][2] = topRow[0];
    for (int i = 1; i <= n; i++) {
        dp[i][0][0] = dp[i - 1][0][0] + bottomRow[i - 1] + topRow[i - 1];
        dp[i][0][1] = dp[i - 1][0][1] + bottomRow[i - 1] + topRow[i - 1];
        dp[i][0][2] = dp[i - 1][0][2] + bottomRow[i - 1] + topRow[i - 1]; 
    }
    cout << max(solve(n, k, ANY), max(solve(n, k, TOP), solve(n, k, BOTTOM))) << endl;
}