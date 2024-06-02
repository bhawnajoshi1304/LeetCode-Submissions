class Solution {
    struct info{
        char c;
        int ind;
    };
    struct comp{
        template <typename T>
        bool operator()(const T&e1, const T&e2)const{
            if (e1.c==e2.c){
                return e1.ind < e2.ind;
            }
            return e1.c > e2.c;
        }
    };
    public:
    string clearStars(string s) {
        string res = "";
        info temp;
        priority_queue<info,vector<info>,comp> pq;
        for (int i = 0;i<s.size();i++){
            if (s[i]=='*'){
                if (!pq.empty()){
                    temp = pq.top();
                    pq.pop();
                    s[temp.ind] = '*';
                }
				continue;
            }
            temp.c = s[i];
            temp.ind = i;
            pq.push(temp);
			            
        }
        for (char c: s){
            if (c!='*') { 
                res += c; 
            }
        }
        return res;
    }
};