#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
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

void checkHouse(map<int,vector<int>> &house , map<int,vector<pair<int,int>>> &dirn) {
    
}


void solve() {
    int n,m,Sx,Sy;
    cin>>n>>m>>Sx>>Sy;
    map<int,vector<int>> hx;
    map<int,vector<int>> hy;

    for(int i=0;i<n;i++) {
        int x,y;
        cin>>x>>y;
        hx[x].push_back(y);
        hy[y].push_back(x);
    }

    map<int,vector<pair<int,int>>> dirx;//x constant
    map<int,vector<pair<int,int>>> diry;//y constant

    for(int i=0;i<m;i++) {
        char d;
        int c;
        cin>>d>>c;

        if(d == 'U') {
            dirx[Sx].push_back({Sy , Sy+c});
            Sy += c;
        }
        else if(d == 'D') {
            dirx[Sx].push_back({Sy-c , Sy});
            Sy -= c;
        }
        else if(d == 'L') {
            diry[Sy].push_back({Sx-c , Sx});
            Sx -= c;
        }
        else{
            diry[Sy].push_back({Sx , Sx+c});
            Sx += c;
        }
    }

    cout<<Sx<<" "<<Sy<<" ";

    set<pair<int,int>> vis;

    for(auto it : hx) {
        int xc = it.first;
        vector<int> yc = it.second;
        sort(yc.begin(),yc.end());

        vector<pair<int,int>> dir = dirx[xc];
        sort(dir.begin(),dir.end());

        for(int i=0,j=0;i<dir.size() && j < yc.size();i++) {//i= dir && j = y_cod


            while(j < yc.size() && dir[i].first > yc[j]) j++;

            while(j < yc.size() && dir[i].first <= yc[j] && dir[i].second >= yc[j]) {

                vis.insert({xc , yc[j]});
                j++;
            }
        }
    }

    for(auto it : hy) {
        int yc = it.first;
        vector<int> xc = it.second;
        sort(xc.begin(),xc.end());

        vector<pair<int,int>> dir = diry[yc];
        sort(dir.begin(),dir.end());

        for(int i=0,j=0;i<dir.size() && j < xc.size();i++) {//i= dir && j = y_cod


            while(j < xc.size() && dir[i].first > xc[j]) j++;

            while(j < xc.size() && dir[i].first <= xc[j] && dir[i].second >= xc[j]) {

                vis.insert({xc[j] , yc});
                j++;
            }
        }
    }

    cout<<vis.size()<<endl;

}
