class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        set<string> ans, a;
        string tmp="";
        char val;
        for(int i=0;i<s1.size();i+=1){
            val=s1[i];
            if(val == ' '){
                if(ans.find(tmp)==ans.end() && a.find(tmp)==a.end()){
                    ans.insert(tmp);}
                else {
                    ans.erase(tmp);
                    a.insert(tmp);
                    }
                tmp="";
            }else{
                tmp+=val;
            }
        }
        if(tmp != ""){
            if(ans.find(tmp)==ans.end() && a.find(tmp)==a.end()){
                    ans.insert(tmp);}
                else {
                    ans.erase(tmp);
                    a.insert(tmp);
                    }
            tmp = "";
        }
        for(int i=0;i<s2.size();i+=1){
            val=s2[i];
            if(val == ' '){
                if(ans.find(tmp)==ans.end() && a.find(tmp)==a.end()){
                    ans.insert(tmp);}
                else {
                    ans.erase(tmp);
                    a.insert(tmp);
                    }
                tmp="";
            }else{
                tmp+=val;
            }
        }
        if(tmp != ""){
            if(ans.find(tmp)==ans.end() && a.find(tmp)==a.end()){
                    ans.insert(tmp);}
                else {
                    ans.erase(tmp);
                    a.insert(tmp);
                    }
            tmp = "";
        }
        vector<string> aa;
        for(auto i:ans){
            aa.push_back(i);
        }
        return aa;
    }
};