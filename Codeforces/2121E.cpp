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

// bool isConsecutive(char a, char b) {
//     if(abs(a-b) == 1) return true;
//     if(b == '0' && a == '9') return true;
//     return false;
// }

void solve() {
    int a, b;
    cin>>a>>b;
    int diff = b-a;
    string s = to_string(a);
    string t = to_string(b);
    string d = to_string(diff);
    while(d.size() < s.size()) d = "0" + d;
    cout<<"d: "<<d<<endl;
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    int cnt = 0;
    for(int i=0;i<d.size();i++) {
        if(d[i] == '0') {
            if(s[i] == t[i]) {
                cnt += 2;
            }
            else {
                cnt++;
            }
        } 
        else if(d[i] == '1') {
            cnt++;
            break;
        }
        else break;
    }
    cout<<cnt<<endl;
}