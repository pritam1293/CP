#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve();
int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    int t=1;
    while(t--)  solve();
    cerr << "time: " << (float)clock() / CLOCKS_PER_SEC << endl; return 0;
}

string multiplyStrings(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    if (n1 == 0 || n2 == 0)
        return "0";

    // check if string are negative
    int nn = 1, mm = 1;
    if (s1[0] == '-')
        nn = -1;
    if (s2[0] == '-')
        mm = -1;

    int isNeg = nn * mm;

    // will keep the result number in 
    // vector in reverse order
    vector<int> result(n1 + n2, 0);

    // index by s1
    int i1 = 0; 

    // index by s2
    int i2 = 0; 

    // go from right to left by s1
    for (int i = n1 - 1; i >= 0; i--) {
        if (s1[i] == '-')
            continue;
        int carry = 0;
        int n1 = s1[i] - '0';
        i2 = 0;

        // go from right to left by s2
        for (int j = n2 - 1; j >= 0; j--) {
            if (s2[j] == '-')
                continue;
            int n2 = s2[j] - '0';
            
            // multiply and add this result 
            // to the existing result
            int sum = n1 * n2 + result[i1 + i2] + carry;

            // carry for next iteration
            carry = sum / 10;

            // store result
            result[i1 + i2] = sum % 10;

            i2++;
        }

        // store carry in next cell
        if (carry > 0)
            result[i1 + i2] += carry;

        i1++;
    }

    // ignore '0's from the right
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;

    // if all were '0's - means either 
    // both or one of s1 or s2 were '0'
    if (i == -1)
        return "0";

    // generate the result string
    string s = "";

    while (i >= 0)
    s += to_string(result[i--]);

    // if negative
    if (isNeg == -1)
        s = "-" + s;

    return s;
}

void solve() {
    int n,k;
    cin>>n>>k;
    vector<string> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    string ans = "1";
    for(int i=0;i<n;i++) {
        ans = multiplyStrings(ans, a[i]);
        if(ans.size() > k) {
            ans = "1";
        }
    }
    cout<<ans<<endl;
}