#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

long long mod = 1e9 + 7;
    
int specialTriplets(vector<int>& nums) {
    map<int, long long> curr, mp;
    for(auto& num : nums) {
        curr[num]++;
    }
    long long ans = 0;
    for(auto& num : nums) {
        curr[num]--;
        int req = num * 2;
        ans += mp[req] * curr[req];
        ans %= mod;
        mp[num]++;
    }
    return (int)ans;
}

void solve() {
    vector<int> nums = {8,4,2,8,4};
    cout<<specialTriplets(nums)<<endl;
}