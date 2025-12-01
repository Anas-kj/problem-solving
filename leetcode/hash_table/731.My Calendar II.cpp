#include<bits/stdc++.h>
using namespace std;

class MyCalendarTwo {
public:
    map<int, int> prefix;
    MyCalendarTwo() {}

    bool book(int start, int end) {
        prefix[start]++;
        prefix[end]--;

        int prev = 0;
        for(auto &p : prefix){
            prev += p.second;
            if(prev > 2){
                //rollback
                prefix[start]--;
                prefix[end]++;

                return false;
            }
        }
        return true;
    }
};
