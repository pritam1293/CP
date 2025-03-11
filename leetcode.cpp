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

    static bool compare(vector<long long> &a, vector<long long> &b) {
        return a[0] < b[0];
    }

    void balance(long long &val, multiset<long long> &sml, multiset<long long> &lar, long long &sum, int &k) {
        if(lar.size() < k || val >= *lar.begin()) {
            sum += val;
            lar.insert(val);
            if(lar.size() > k) {
                auto it = lar.begin();
                sum -= *it;
                sml.insert(*it);
                lar.erase(it);
            }
        }
        else {
            sml.insert(val);
        }
    }

vector<long long> findMaxSum(vector<int>& a, vector<int>& b, int k) {
        int n = (int)a.size();
        vector<long long> ans(n, 0);

        vector<vector<long long>> arr(n);
        for (int i=0;i<n;i++) {
            arr[i] = {(long long)a[i], (long long)b[i], (long long)i};
        }

        sort(arr.begin(), arr.end(),compare);

        vector<vector<long long>> queries(n);
        for (int i=0;i<n;i++) {
            queries[i] = {(long long)a[i], (long long)i};
        }

        sort(queries.begin(), queries.end(),compare);

        multiset<long long> sml, lar;//small, large
        long long sum = 0;

        int i = 0;
        for (auto q : queries) {
            long long val = q[0];
            long long idx = q[1];

            while (i < n && arr[i][0] < val) {
                balance(arr[i][1],sml,lar,sum,k);
                i++;
            }

            ans[idx] = sum;
        }
        return ans;
}

void solve() {
    vector<int> a = {4,2,1,5,3};
    vector<int> b = {10,20,30,40,50};
    for(auto it : findMaxSum(a,b,2)){
        cout<<it<<" ";
    }
}
