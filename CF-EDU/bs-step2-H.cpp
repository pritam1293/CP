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

bool isPossible(vector<long long> &freq, vector<long long> &count, vector<long long> &price, long long r, long long x) {
    long long req_b = max(0ll, freq[0] * x - count[0]);
    long long req_s = max(0ll, freq[1] * x - count[1]);
    long long req_c = max(0ll, freq[2] * x - count[2]);

    long long req_price = req_b * price[0] + req_s * price[1] + req_c * price[2];

    return r >= req_price;
}

void solve() {
    string str;
    cin>>str;
    vector<long long> count(3);//bsc
    cin>>count[0]>>count[1]>>count[2];
    vector<long long> price(3);//bsc
    cin>>price[0]>>price[1]>>price[2];
    long long r;
    cin>>r;

    int b = 0, s = 0, c = 0;
    for(char ch : str) {
        if(ch == 'B') b++;
        else if(ch == 'S') s++;
        else c++;
    }
    vector<long long> freq = {b, s, c};
    // cout<<b<<" "<<s<<" "<<c<<endl;

    long long low = 0, high = 1e15;
    long long ans = 0;
    while(low <= high) {
        long long mid = (low + high) / 2ll;

        if(isPossible(freq, count, price, r, mid)) {
            ans = mid;
            low = mid+1;
        }
        else {
            high = mid-1;
        }
    }
    cout<<ans<<endl;
}