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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

vector<vector<int>> mergeOverlap(vector<vector<int>> &arr) {
    if (arr.empty()) {
        return {};
    }

    sort(arr.begin(),arr.end());
  
    vector<vector<int>> res;
    res.push_back(arr[0]);

    for (int i=1;i<arr.size();i++) {
        vector<int>& last = res.back();
        vector<int>& curr = arr[i];

        if (curr[0] <= last[1]) {
            last[1] = max(last[1] , curr[1]);
        }
        else {
            res.push_back(curr);
        }
    }
    return res;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> first(n+1 , -1) , last(n+1 , -1);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        
        if(first[a[i]] == -1) {
            first[a[i]] = i;
        }
        else{
            last[a[i]] = i;
        }
    }

    vector<vector<int>> arr;
    for(int i=1;i<=n;i++){
        if(last[i] != -1) {
            arr.push_back({first[i] , last[i]});
        }
    }

    vector<vector<int>> res = mergeOverlap(arr);
    int ans = 0;
    for(auto it : res){
        int st = it[0] , end = it[1];
        set<int> set;
        for(int i=st;i<=end;i++){
            set.insert(a[i]);
        }
        ans += set.size();
    }
    cout<<ans<<endl;
}
