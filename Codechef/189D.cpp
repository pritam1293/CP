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

bool ac(int num, int tar) {
    if(tar == num) return true;
    if(num % 2 == 0) num--;
    return num > 2 * tar;
}

bool check(vector<int> arr) {
    int n = arr.size();
    int prev = -1;
    for(int i=0;i<n;i++) {
        if(prev >= arr[i]) return false;
        if(ac(arr[i], prev+1)) {
            arr[i] = prev + 1;
            prev++;
        }
        else prev = arr[i];
    }
    for(int i=1;i<n;i++) {
        if(arr[i-1] >= arr[i]) return false;
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
    int cnt = 0;
    for(int i=0;i<n;i++) {
        vector<int> temp;
        for(int j=i;j<n;j++) {
            temp.push_back(a[j]);
            if(check(temp)) cnt++;
        }
    }
    cout<<cnt<<endl;
}
