#include<bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        int n = pos.size();

        vector<pair<int, double>> cars;
        for(int i = 0; i < n; i++)
            cars.push_back({pos[i], (double) (target - pos[i]) / speed[i]});

        sort(cars.begin(), cars.end(), greater<pair<int, double>>());

        stack<double> st;
        for(auto &car : cars){

            if(st.empty() || car.second > st.top())
                st.push(car.second);
        }

        return st.size();
    }
};