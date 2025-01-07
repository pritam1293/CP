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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    map<int,int> mp;//frequency of each number
    for(int i=0;i<n;i++) {
        cin>>a[i];
        mp[a[i]]++;
    }
    int unique = mp.size();
    int freq = -1;//highest frequency
    int val;//which number has the highest frequency
    for(auto it : mp) {
        if(it.second > freq) {
            val = it.first;
            freq = it.second;
        }
    }
    priority_queue<int,vector<int>,greater<int>> pq;
    /*pq for other frequencies of the numbers and a boolean is taken for not to
    take the highest frequency value in the pq*/

    for(auto it : mp) {
        if(it.first == val) {
            // one = true;
            continue;
        } 
        pq.push(it.second);
    }
    /*
    the idea is to convert the numbers to the "val"
    (the number which has highest frequecny)as much as i can, and 
    by doing this, it reduce the no. of unique numbers in the
    array and the final ans will be the no. of unique numbers present in the array. 
    */
    while(k > 0 && !pq.empty()) {
        if( k >= pq.top()) {
            k -= pq.top();
            pq.pop();
            unique--;
        }
    }
    cout<<unique<<endl;
    // cout<<val<<endl;
}
