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
    long long n;
    cin >> n;
    string response;

    // Step 1: Make x a multiple of 9
    cout << "mul 9" << endl;
    cout.flush();
    cin >> response;
    if (response == "-1") return;

    // Step 2: Apply digit sum
    cout << "digit" << endl;
    cout.flush();
    cin >> response;
    if (response == "-1") return;

    // Step 3: Apply digit sum again to reach 9
    cout << "digit" << endl;
    cout.flush();
    cin >> response;
    if (response == "-1") return;

    // Step 4: Shift from 9 to n
    cout << "add " << (n - 9) << endl;
    cout.flush();
    cin >> response;
    if (response == "-1") return;

    // Step 5: Final confirmation
    cout << "!" << endl;
    cout.flush();
    cin >> response;
    if (response == "-1") return;
}
