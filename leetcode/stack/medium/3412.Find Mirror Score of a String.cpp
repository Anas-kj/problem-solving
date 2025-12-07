#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    ll calculateScore(string s) {
        vector<stack<int>> v(26);
        ll ans = 0;

        for(int i = 0; i < s.size(); i++){
            int ord = s[i] - 'a';
            int mir = 25 - ord;
            if(v[mir].size()){
                ans += i - v[mir].top();
                v[mir].pop();
            }
            else v[ord].push(i);
        }
        return ans;
    }
};