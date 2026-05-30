class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        vector<vector<int>> a;
        for (int i = 0; i < 2 * n; i += 1) {
            if (i == 0) {
                ans.push_back("(");
                a.push_back({1, 1});
            } else {
                int k = ans.size();
                for (int j = 0; j < k; j += 1) {
                    if (a[j][0] < n) {
                        if (a[j][1] > 0) {
                            ans.push_back(ans[j] + ')');
                            a.push_back({a[j][0], a[j][1] - 1});
                        }
                        ans[j] += '(';
                        a[j][0] += 1;
                        a[j][1] += 1;
                    } else {
                        if (a[j][1] > 0) {
                            ans[j] += ')';
                            a[j][1] -= 1;
                        }
                    }
                }
            }
        }
        /*
          (
          ((  ()
          ((( (() ()(
          ((() (()( (()) ()(( ()()
          ((()) (()() (())( ()(() ()()(
          ((())) (()()) (())() ()(()) ()()()
 */
        return ans;
    }
};