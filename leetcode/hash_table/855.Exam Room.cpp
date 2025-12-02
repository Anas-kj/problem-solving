#include<bits/stdc++.h>
using namespace std;

class ExamRoom {
public:
    set<int> s;
    int n;

    ExamRoom(int n) {
        this->n = n;
    }

    int seat() {
        if(s.empty()){
            s.insert(0);
            return 0;
        }

        int max_d = *s.begin();
        int pos = 0;

        auto prev = s.begin();
        auto it = prev;
        ++it;

        for(; it != s.end(); prev++, ++it){
            int d = (*it - *prev) / 2;
            if(d > max_d){
                max_d = d;
                pos = *prev + d;
            }
        }

        int last_d = (n - 1) - *s.rbegin();
        if(last_d > max_d)
            pos = n - 1;

        s.insert(pos);
        return pos;
    }

    void leave(int p) {
        s.erase(p);
    }
};