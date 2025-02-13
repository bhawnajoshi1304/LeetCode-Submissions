class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        int n=words.size();
        vector<string>ans;
        queue<int>index;
        int size=0;
        for(int i=0;i<n;i++)
        {
            if(size+words[i].length()+index.size()<= maxWidth)
            {
               index.push(i);
               size+=words[i].length();
            }
            else
            {
                int totspace=maxWidth-(size);
                int same_space=totspace;
                int extra_space=0;
                if(index.size()>1){
                 same_space=totspace/(index.size()-1);
                 extra_space=totspace % (index.size()-1);
                }
                string temp="";
                if(index.size()!=0){
                temp+=words[index.front()];
                index.pop();
                }
                while(index.size()>1)
                {
                    int ind=index.front();
                    index.pop();
                    temp.append(same_space,' ');
                    if(extra_space>0)
                    {
                        temp+=" ";
                        extra_space--;
                    }
                    temp+=words[ind];
                }
                temp.append(same_space,' ');
                if(!index.empty()){
                temp+=words[index.front()];
                index.pop();
                }
                ans.push_back(temp);
                
                index.push(i);
                size=words[i].length();
            }
        }
        int tot_space=maxWidth-(size);
         string temp="";
        if(!index.empty()){ 
        temp+=words[index.front()];
        index.pop();
        if(index.empty())
        temp.append(tot_space,' ');
        else{
        while(!index.empty())
        {
           temp+=" "+words[index.front()];
           index.pop();
           tot_space--;
        }
        temp.append(tot_space,' ');
        }
        
        ans.push_back(temp);
        }
        
        return ans;
    }
};