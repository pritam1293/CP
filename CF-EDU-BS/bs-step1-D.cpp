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

int rightSearch(vector<int> &a, int val) {
    int idx = -1;
    int low = 0, high = a.size()-1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(a[mid] > val) high = mid-1;
        else{
            idx = mid;
            low = mid+1;
        }
    }
    return idx+1;
}

int leftSearch(vector<int> &a, int val) {
    int idx = a.size();
    int low = 0, high = idx-1;
    while(low <= high) {
        int mid = (low + high) / 2;

        if(a[mid] >= val) {
            high = mid-1;
            idx = mid;
        }
        else low = mid+1;
    }
    return idx+1;
}

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    int k;
    cin>>k;
    for(int i=0;i<k;i++) {
        int l,r;
        cin>>l>>r;

        int left = leftSearch(a, l);
        int right = rightSearch(a, r);
        cout<< right - left + 1 <<endl;
    }
}