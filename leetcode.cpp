#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n = 1;
    vector<vector<int>> ref = {{0}};
    for(int k=1;k<=n;k++) {
        int size = pow(2,k);

        vector<vector<int>> curr(size, vector<int>(size));
        for(int row = 0;row < size/2; row++) {
            for(int col = size/2; col < size; col++) {
                curr[row][col] = ref[row][col - (size/2)] ;
            }
        }

        for(int row = size/2; row < size; row++) {
            for(int col = size/2; col < size; col++) {
                curr[row][col] = ref[row - (size/2)][col - (size/2)] + size * pow(2, k-2);
            }
        }

        for(int row = size/2; row < size; row++) {
            for(int col = 0; col < size/2; col++) {
                curr[row][col] = ref[row - (size/2)][col] + 2 * size * pow(2, k-2);
            }
        }

        for(int row = 0;row < size/2; row++) {
            for(int col = 0; col < size/2; col++) {
                curr[row][col] = ref[row][col] + 3 * size * pow(2, k-2);
            }
        }
        
        ref = curr;
    }

    for(auto& arr : ref) {
        for(auto& val : arr) {
            cout<<val<<" ";
        }
        cout<<endl;
    }
}
