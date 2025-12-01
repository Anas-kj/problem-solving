#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        set<pair<int, int>> st;
        vector<int> ans;

        for(int &x : nums) mp[x]++;

        for(auto &p : mp) st.insert({p.second, p.first});

        auto it = st.rbegin();
        while(k-- && it != st.rend()){
            ans.push_back(it->second);
            it++;
        }

        return ans;
    }
};