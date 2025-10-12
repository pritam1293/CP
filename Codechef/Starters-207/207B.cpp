#include<bits/stdc++.h>
using namespace std;
// #define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
#endif
    int t=1;
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void solve() {
    int n;
    cin>>n;
    if(n == 1) {
        int x;
        cin>>x;
        cout<<"-1"<<endl;
        cout<<"1"<<endl;
        return;
    }

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i].first;
        a[i].second = i+1;
    }
    sort(a.begin(), a.end());

    vector<vector<int>> arr;
    arr.push_back({a[0].second});
    for (int i = 1; i < n; ++i) {
        if (a[i].first == a[i - 1].first) {
            arr.back().push_back(a[i].second);
        } else {
            arr.push_back({a[i].second});
        }
    }

    bool flag = false;
    for (const auto& v : arr) {
        if (v.size() == 1) {
            flag = true;
            break;
        }
    }

    vector<int> p(n+1);

    if (!flag) {
        cout<<n<<endl;
        for (const auto& v : arr) {
            for (int i = 0; i < (int)v.size(); ++i) {
                p[v[i]] = v[(i + 1) % (int)v.size()];
            }
        }
    } 
    else {
        cout<<n-1<<endl;
        int m = arr.size();
        for (int i = 0; i < m; i++) {
            const auto& curr = arr[i];
            const auto& prev = arr[(i - 1 + m) % m];
            p[curr[0]] = prev.back();
            for (int j = 1; j < (int)curr.size(); j++) {
                p[curr[j]] = curr[j - 1];
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout<<p[i]<<" ";
    }
    cout<<endl;
}