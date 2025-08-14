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

vector<long long> special_palindromes;
bool is_generated = false;
void buildPermutations(string& current, map<char, int>& counts, int target_len, char middle_char) {
    if ((int)current.size() == target_len) {
        string rev_half = current;
        reverse(rev_half.begin(), rev_half.end());

        string full_str = current;
        if (middle_char != '\0') {
            full_str += middle_char;
        }
        full_str += rev_half;

        string max_ll_str = "9223372036854775807";
        if (full_str.length() > max_ll_str.length() || 
           (full_str.length() == max_ll_str.length() && full_str > max_ll_str)) {
            return; // This number is too large for a long long.
        }

        special_palindromes.push_back(stoll(full_str));
        return;
    }

    for (auto& pair : counts) {
        if (pair.second > 0) { 
            // Use it
            pair.second--;
            current += pair.first;
            
            // Recurse to build the rest of the permutation
            buildPermutations(current, counts, target_len, middle_char);
            
            // Backtrack to explore other possibilities
            current.pop_back();
            pair.second++;
        }
    }
}

void findDigitCombinations(int k, string current_digits) {
    // Base case: all digits from 1 to 9 have been considered.
    if (k > 9) {
        if (!current_digits.empty()) {
            string half = "";
            char middle_char = '\0';
            map<int, int> digit_counts;
            for (char c : current_digits) {
                digit_counts[c - '0']++;
            }

            for (auto const& [digit, count] : digit_counts) {
                half += string(count / 2, digit + '0');
                if (count % 2 != 0) {
                    // A palindrome can have at most one digit with an odd count.
                    if (middle_char != '\0') return; // Invalid combination.
                    middle_char = digit + '0';
                }
            }
            
            map<char, int> char_counts;
            for (char c : half) {
                char_counts[c]++;
            }
            string current_permutation = "";
            buildPermutations(current_permutation, char_counts, half.length(), middle_char);
        }
        return;
    }

    findDigitCombinations(k + 1, current_digits);

    if (current_digits.length() + k <= 18) {
        findDigitCombinations(k + 1, current_digits + string(k, k + '0'));
    }
}

long long specialPalindrome(long long n) {
    if (!is_generated) {
        findDigitCombinations(1, "");
        sort(special_palindromes.begin(), special_palindromes.end());
        special_palindromes.erase(unique(special_palindromes.begin(), special_palindromes.end()), special_palindromes.end());
        is_generated = true;
    }
    
    auto it = upper_bound(special_palindromes.begin(), special_palindromes.end(), n);
    
    return *it;
}

void solve() {
    long long n = 11;
    cout<<specialPalindrome(n)<<endl;
    // for(auto& e : special_palindromes) {
    //     cout<<e<<endl;
    // }
    map<int, string> mp;

    // Inserting the elements one by one
    mp.insert(make_pair(10, "geeks"));
    mp.insert(make_pair(20, "practice"));
    mp.insert(make_pair(5, "contribute"));
    auto it = mp.rbegin();
    while(it != mp.rend()) {
        cout<<it->first<<endl;
        it++;
    }
}