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
    // cin>>t;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

bool compare(pair<int,string> a , pair<int,string> b) {
    if(a.first != b.first) {
        return a > b;
    }
    return a.second < b.second;
}

void solve() {
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    map<char,int> m;
    m['A'] = a;
    m['B'] = b;
    m['C'] = c;
    m['D'] = d;
    m['E'] = e;

    vector<string> seq = {"ABCDE","BCDE","ACDE","ABDE","ABCE","ABCD","CDE","BDE","ADE",
    "BCE","ACE","BCD","ABE","ACD","ABD","ABC","DE","CE","BE","CD","AE","BD","AD","BC",
    "AC","AB","E","D","C","B","A",};

    vector<pair<int,string>> ans(31);
    int cnt = 0;
    for(int i=0;i<31;i++) {
        ans[i].second = seq[i];
        for(char c : seq[i]) {
            ans[i].first += m[c];
            cnt++;
        }
    }
    sort(ans.begin(),ans.end(),compare);

    cout<<cnt<<endl;
    for(int i=0;i<31;i++) {
        cout<<ans[i].second<<endl;
    }
}
