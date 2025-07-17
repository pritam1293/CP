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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

bool possible(int n,int x,int mid,vector<int> &vit,vector<int> &am,vector<int> &cal) {
    vector<int> required(3, 0);
    vector<pair<int, int>> foods[3];

    for (int i=0;i<n;i++) {
        foods[vit[i] - 1].push_back({cal[i], am[i]});
    }
    int total = 0;

    for (int i=0;i<3;i++) {
        sort(foods[i].begin(), foods[i].end());
        
        int sum = 0;
        for (auto& food : foods[i]) {
            if (sum >= mid) break;
            sum += food.second;
            total += food.first;
        }
        
        if (sum < mid) {
            return false;
        }
    }
    if(total <= x) return true;
    return false;
}

void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> vit(n),am(n),cal(n);
    for(int i=0;i<n;i++) {
        cin>>vit[i]>>am[i]>>cal[i];
    }

    int left = 0 , right = 1e9;
    int ans = 0;

    while(left <= right) {
        int mid = (left + right) / 2;
        if(possible(n,x,mid,vit,am,cal)) {
            ans = mid;
            left = mid+1;
        }
        else {
            right = mid-1;
        }
    }
    cout<<ans<<endl;
}
