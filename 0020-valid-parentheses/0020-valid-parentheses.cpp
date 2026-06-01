class Solution {
public:
    bool isValid(string c) {
        stack<char> s;
        for (auto i : c) {
            if (i == '('|| i == '{' || i == '[')
            s.push(i);
            else if(i==')' && !s.empty() && s.top() == '(') s.pop();
            else if(i=='}' && !s.empty() && s.top() == '{') s.pop();
            else if(i==']' && !s.empty() && s.top() == '[') s.pop();
            else return false; 
        }
        return s.empty();
    }
};