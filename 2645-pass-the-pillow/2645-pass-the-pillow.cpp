class Solution {
public:
    int passThePillow(int n, int time) {
        if(time%(2*(n-1))>=n-1)
        return n-(time%(n-1));
        else 
        return time%(n-1)+1;
    }
};


// if time=n-1 -> n
//    time=2*(n-1) ->1