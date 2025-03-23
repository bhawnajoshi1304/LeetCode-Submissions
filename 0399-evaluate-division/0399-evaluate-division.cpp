class Solution {
public:
    map<string,string> componentId;
    map<string, double> value;

    string findParent(string curr){
        if(componentId[curr]==curr){return curr;}

        string oldParent = componentId[curr];

        string parent = findParent(componentId[curr]);

        value[curr] *= value[oldParent];

        return componentId[curr]=parent;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;

        int sz = equations.size();

        componentId.clear();
        value.clear();

        for(int i=0;i<sz;i++){
            string var1 = equations[i][0];
            string var2 = equations[i][1];

            double ratio = 1.0 * values[i];

            // Checking if variables are present, if not, we add them
            if(componentId.find(var2)==componentId.end()){
                componentId[var2]=var2;
                value[var2] = 1.0;
            }

            if(componentId.find(var1)==componentId.end()){
                componentId[var1]=var1;
                value[var1] = 1.0;
            }

            string par2 = findParent(var2); 
            string par1 = findParent(var1);

            if(par1==par2){
                continue;
            }

            double var2Value = 1.0 * value[var2];
            double var1Value = 1.0 * value[var1];

            componentId[par2] = par1;
            value[par2] = (1.0 * var1Value * ratio)/(1.0 * var2Value);
        }

        for(auto itr:componentId){
            cout<<itr.first<<" "<<itr.second<<" "<<value[itr.first]<<"\n";
        }

        for(auto itr:queries){
            string var1 = itr[0];
            string var2 = itr[1];

            if(componentId.find(var1)==componentId.end() || componentId.find(var2)==componentId.end()){
                ans.push_back(-1.0);
                continue;
            }

            string parent1 = findParent(var1);
            string parent2 = findParent(var2);

            if(parent1 != parent2){
                ans.push_back(-1.0);
                continue;
            }

            double value1 = value[var1];
            double value2 = value[var2];

            double currAns = (1.0 * value2) / (1.0 * value1); 

            ans.push_back(currAns);     
        }

        return ans;
    }
};