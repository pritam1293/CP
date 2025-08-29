#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

//next permuation - mid point breaker
void nextPermutation(vector<int>& a) {
    int n = a.size();
    int i = n-2;
    while(i >= 0 && a[i] >= a[i+1]) i--;
    if(i >= 0) {
        int j = n-1;
        while(a[i] >= a[j]) j--;
        swap(a[i], a[j]);
    }
    reverse(a.begin()+i+1, a.end());
}

//max sum subarray - Kadane's Algorithm
int maxSubArray(vector<int>& a) {
    int ans = a[0];
    int sum = a[0];
    for(int i = 1; i < a.size(); i++) {
        sum = max(a[i], sum + a[i]);
        ans = max(ans, sum);
    }
    return ans;
}

void solve() {
    
}