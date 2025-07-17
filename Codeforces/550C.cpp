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

void solve() {
    string s;
    cin>>s;
    int n = s.size();
    int num;
    string temp;
    for(int i = 0; i < n; i++) {
        temp  = s[i];
        num = stoi(temp);
        if(num % 8 == 0) {
            cout<<"YES"<<endl;
            cout<<temp<<endl;
            return;
        }
        for(int j = i+1; j < n; j++) {
            temp = string(1, s[i]) + s[j];
            num = stoi(temp);
            if(num % 8 == 0) {
                cout<<"YES"<<endl;
                cout<<temp<<endl;
                return;
            }
            for(int k = j+1; k < n; k++) {
                temp = string(1, s[i]) + s[j] + s[k];
                num = stoi(temp);
                if(num % 8 == 0) {
                    cout<<"YES"<<endl;
                    cout<<temp<<endl;
                    return;
                }
            }
        }
    }
    cout<<"NO"<<endl;
}