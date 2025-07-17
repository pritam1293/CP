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

void solve() {
    long long n;
    cin>>n;
    string output;

    cout<<"mul 9"<<endl;
    cout.flush();
    cin>>output;
    if(output == "-1") return ;

    cout<<"digit"<<endl;
    cout.flush();
    cin>>output;
    if(output == "-1") return ;

    cout<<"digit"<<endl;
    cout.flush();
    cin>>output;
    if(output == "-1") return ;

    cout<<"add "<< n - 9 <<endl;
    cout.flush();
    cin>>output;
    if(output == "-1") return ;

    cout<<"!"<<endl;
    cout.flush();
    cin>>output;
    if(output == "-1") return ;
}