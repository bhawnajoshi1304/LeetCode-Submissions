class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for(int i=0;i<asteroids.size();i+=1){
            if(s.size()==0) s.push_back(asteroids[i]);
            else{
                bool p=true;
                if(asteroids[i]<0){
                    while(s.size()!=0){
                        if(s[s.size()-1]<0) break;
                        else{
                            int temp=s[s.size()-1]+asteroids[i];
                            if(temp==0){
                                p=false;
                                s.pop_back();
                                break;
                            }else if(temp>0){
                                p=false;
                                break;
                            }else{
                                s.pop_back();
                            }
                        }
                    }
                }
                if(p) s.push_back(asteroids[i]);
            }
        }
        return s;
    }
};