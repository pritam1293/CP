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
    cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

void reverse(vector<int> &a, int j) {
    int i = 0;
    while(i < j) {
        swap(a[i], a[j]);
        i++;j--;
    }
}

bool isGood(vector<int> &a, int n) {
    int prev = a[0];
    for(int i=1;i<n;i++) {
        int sum = prev + a[i];
        if(sum % 3 == 0) return false;
        prev = sum;
    }
    return true;
} 

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    if(isGood(a, n)) {
        cout<<"Yes"<<endl;
        return;
    }
    int prev = a[0];
    int sum;
    for(int i=1;i<n;i++) {
        sum = prev + a[i];
        if(sum % 3 == 0) {
            // cout<<"at->"<<i<<endl;
            sum = 0;
            for(int j = i+1; j < n; j++) {
                sum += a[j];
                // cout<<"e1-> "<<sum<<endl;
                if(sum % 3 == 1) {
                    reverse(a, j);
                    // cout<<"j->"<<j<<endl;
                    if(isGood(a, n)) {
                        cout<<"Yes"<<endl;
                        return;
                    }
                    reverse(a, j);
                    break;
                }
            }
            // for(auto it : a) {
            //     cout<<it<<" ";
            // }
            // cout<<endl;
            sum = 0;
            for(int j = i+1; j < n; j++) {
                sum += a[j];
                // cout<<"e2-> "<<sum<<endl;
                if(sum % 3 == 2) {
                    reverse(a, j);
                    if(isGood(a, n)) {
                        cout<<"Yes"<<endl;
                        return;
                    }
                    break;
                }
            }
            break;
        }
        prev = sum;
    }
    cout<<"No"<<endl;
}