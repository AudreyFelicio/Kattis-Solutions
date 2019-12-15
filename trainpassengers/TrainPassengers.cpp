#include <bits/stdc++.h>
using namespace std;
int main() {
    ios :: sync_with_stdio;
    cin.tie(0);cout.tie(0);
    int c,n,left,entered,stay;
    long currentlyOnTrain = 0;
    bool isEmpty = true; 
    bool possible = true;
    cin >> c >> n;
    for(int i = 0; i<n; i++) {
        cin >> left >> entered >> stay;
        currentlyOnTrain = currentlyOnTrain - left + entered;
        long totalPassengers = currentlyOnTrain + stay;
        if(totalPassengers <= c && stay != 0) { //make sure as long as there is space, there is no waiting
            possible = false;
        } else if (currentlyOnTrain < 0 || currentlyOnTrain > c) { //make sure train doesn't overflow and train don't have negative passengers
            possible = false;
        } else if (currentlyOnTrain < c && stay != 0) { //make sure as long as there is space, there is no waiting
            possible = false;
        } else if (i == n-1) {
            if(totalPassengers != 0) { //make sure train is empty at last stop
                isEmpty = false;
            }
        } else if (i == 0) { //make sure train is empty at first stop
            if(left != 0) {
                possible = false;
            }
        }
    }
    if(possible && isEmpty) {
        cout << "possible" << endl;
    } else {
        cout << "impossible" << endl;
    }
}
//key takeaway from this problem : Be very careful with cases! Read and understand problem very carefully!