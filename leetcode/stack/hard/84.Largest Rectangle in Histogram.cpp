#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        st.push(-1);

        int n = h.size(), ans = 0;
        for(int i = 0; i < n; i++){
            while(st.top() != -1 && h[i] <= h[st.top()]){
                int x = h[st.top()];
                st.pop();
                int area =  x * (i - st.top() - 1);
                ans = max(ans, area);
            }

            st.push(i);
        }

        while(st.top() != -1){
            int height = h[st.top()];
            st.pop();
            int area = height * (n - st.top() - 1);
            ans = max(ans, area);
        }

        return ans;
    }
};