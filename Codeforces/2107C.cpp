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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

int inf = 1e18;

void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int> a(n);
    int maxm = 0, sum = 0;
    bool flag = true;

    for(int i=0;i<n;i++) {
        cin>>a[i];
        sum += a[i];
        if(s[i] == '0') sum = 0, flag = false;
        maxm = max(maxm, sum);
        sum = max(0ll, sum);
    }

    if(maxm > k) {
        cout<<"No"<<endl;
        return;
    }
    if(flag) {
        if(maxm == k) {
            cout<<"Yes"<<endl;
            for(auto& val : a) {
                cout<<val<<" ";
            }   
            cout<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
        return;
    }
    cout<<"Yes"<<endl;
    flag = true;
    for(int i=0;i<n;i++) {
        if(s[i] == '0') {
            if(flag) {
                //prefix-sum;
                int l = i-1;
                int sum = 0, left = 0;
                while(l >= 0) {
                    sum += a[l];
                    left = max(left, sum);
                    l--;
                }
                //suffix sum
                int r = i+1;
                sum = 0;
                int right = 0;
                while(r < n && s[r] != '0') {
                    sum += a[r];
                    right = max(right, sum);
                    r++;
                }
                cout<< k - left - right << " ";
                flag = false;
            }
            else{
                cout<< -inf <<" ";
            }
        }
        else {
            cout<<a[i]<<" ";
        }
    }
    cout<<endl;
}