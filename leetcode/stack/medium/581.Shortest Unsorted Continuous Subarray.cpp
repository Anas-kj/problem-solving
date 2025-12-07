#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& v) {
        stack<int> st;

        int n = v.size();
        vector<int> next(n, -1), prev(n, -1);
        for(int i = 0; i < n; i++){
            while(!st.empty() && v[st.top()] > v[i]){
                next[st.top()] = i;
                st.pop();
            }

            st.push(i);

        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i > -1; i--){
            while(!st.empty() && v[st.top()] < v[i]){
                prev[st.top()] = i;
                st.pop();
            }

            st.push(i);

        }

        int i = 0;
        int j = n - 1;

        while(i < n && next[i] == -1) i++;
        while(j > -1 && prev[j] == -1) j--;

        return max(0, j - i + 1);
    }
};