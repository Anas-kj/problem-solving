#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(int i : nums) st.insert(i);

        int ans = 0, seq = 0, prev = *st.begin() - 1;
        for(int i : st){
            if(prev + 1 == i) seq++;
            else seq = 1;

            ans = max(ans, seq);
            prev = i;
        }

        return ans;
    }
};