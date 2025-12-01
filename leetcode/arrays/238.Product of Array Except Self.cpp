#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n, 1), sfx(n, 1), ans(n);

        pref[0] = nums[0];
        sfx[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++) pref[i] *= nums[i] * pref[i - 1];
        for(int i = n - 2; i > 0; i--) sfx[i] = nums[i] * sfx[i + 1];
        for(int i = 0; i < n; i++){
            if(i == 0) ans[i] = sfx[1];
            else if(i == n - 1) ans[i] = pref[n - 2];
            else ans[i] = pref[i - 1] * sfx[i + 1];
        }

        return ans;
    }
};