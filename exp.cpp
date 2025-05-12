#include<bits/stdc++.h>
using namespace std;
void solve();
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    deque<pair<int,int>> suffix = {{0,0}};//v
    deque<pair<int,int>> prefix = {{0,0}};//v1

    int l = 0, ans = INT_MAX;
    for(int r = 0; r < n; r++) {
        suffix.push_back({a[r],__gcd(a[r], suffix.back().second)});
        if(__gcd(prefix.back().second, suffix.back().second) == 1) {
            ans = min(ans, r-l+1);
            if(prefix.size() == 1) {
                while(suffix.size() > 1) {
                    prefix.push_back({suffix.back().first, __gcd(prefix.back().second, suffix.back().first)});
                    suffix.pop_back();
                }
            }

            while(prefix.size() > 1 && __gcd(prefix.back().second, suffix.back().second) == 1) {
                prefix.pop_back();
                l++;
                if(prefix.size() == 1) {
                    while(suffix.size() > 1) {
                        prefix.push_back({suffix.back().first, __gcd(prefix.back().second, suffix.back().first)});
                        suffix.pop_back();
                    }
                }

                if(__gcd(suffix.back().second, prefix.back().second) == 1) {
                    ans = min(ans, r-l+1);
                }
            }
        }
    }
    cout<<(ans == INT_MAX ? -1 : ans)<<endl;
}