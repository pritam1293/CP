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

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;

    int zero = 0, one = 0;
    for(int i=0;i<n-1;i++) {
        if(s.substr(i,2) == "11") one++;
        else if(s.substr(i,2) == "00") zero++;
    }

    if(one == 0 && zero == 0) {
        cout<<"Yes"<<endl;
    }
    else if(one >= 2 || zero >= 2) {
        cout<<"No"<<endl;
    }
    else{
        if(one  == 1 && zero == 1) {
            cout<<"Yes"<<endl;
        }
        else if(one == 1) {
            if(s[0] == '0' || s[n-1] == '0'){
                cout<<"Yes"<<endl;
            }
            else {
                cout<<"No"<<endl;
            }
        }
        else{
            if(s[0] == '1' || s[n-1] == '1') {
                cout<<"Yes"<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
        }
    }
}
