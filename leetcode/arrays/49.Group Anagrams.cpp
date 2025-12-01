#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> mp;

        for(auto &s : strs){
            string ch = s;
            sort(ch.begin(), ch.end());
            mp[ch].push_back(s);
        }

        for(auto &p : mp){
            ans.push_back(p.second);
        }

        return ans;

    }
};