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

bool isPalindrome(string s, int i, int j) {
    while(i <= j) {
        if(s[i] != s[j]) return false;
        i++;j--;
    }
    return true;
}

// int rec(int i, string &s, vector<int> &dp) {
//     if(i == s.size()) return 0;
//     if(dp[i] != -1) return dp[i];

//     int cost = INT_MAX;
//     for(int j=i;j<s.size();j++) {
//         if(isPalindrome(s, i , j)) {
//             cost = min(cost, 1 + rec(j+1, s, dp));
//         }
//     }
//     return dp[i] = cost;
// }

int minCut(string &s) {
    int n = s.size();
    vector<int> dp(n+1, 0);
    for(int i=n-1;i>=0;i--) {
        int cost = INT_MAX;
        for(int j=i;j<n;j++) {
            if(isPalindrome(s, i, j)) {
                cost = min(cost, 1 + dp[j+1]);
            }
        }
        dp[i] = cost;
    }
    return dp[0] - 1;
}

void solve() {
    string s = "bababcbadcede";
    cout<<s.size()<<endl;
    cout<<minCut(s)<<endl;
}
