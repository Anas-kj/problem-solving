#include<bits/stdc++.h>
using namespace std;

#define pp pair<int, int>

class MyCalendar {
public:
    set<pp> st;
    MyCalendar() {

    }

    bool book(int start, int end) {
        if(!st.empty()){
            auto it = st.lower_bound({start, 0});

            if(it != st.end() && it->first < end)
                return false;

            if(it != st.begin()){
                auto p = prev(it);
                if(p->second > start)
                    return false;
            }
        }

        st.insert({start, end});
        return true;
    }
};