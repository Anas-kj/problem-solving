#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;

        int n = temp.size();
        vector<int> next(n, 0);
        for(int i = 0; i < n; i++){
            while(!st.empty() && temp[st.top()] < temp[i]){
                next[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        return next;
    }
};