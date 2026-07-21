class Solution {
public:
    bool isValid(string s) {
        stack<char> valid_parenthes;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' or s[i]=='{' or s[i]=='[')
                valid_parenthes.push(s[i]);
            else{
                if(valid_parenthes.empty()){
                    return false;
                }
                if(s[i]==')' and valid_parenthes.top()=='('){
                    valid_parenthes.pop();
                }
                else if(s[i]==']' and valid_parenthes.top()=='['){
                    valid_parenthes.pop();
                }
                else if(s[i]=='}' and valid_parenthes.top()=='{'){
                    valid_parenthes.pop();
                }
                else
                    return false;

            }
        }
        if (valid_parenthes.empty()){
            return true;
        }
        return false;
    }
};
