class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        for(auto i:moves){
            if(i=='L') x+=1;
            if(i=='R') x-=1;
            if(i=='U') y+=1;
            if(i=='D') y-=1;
        }
        return (x==0) && (y==0);
    }
};