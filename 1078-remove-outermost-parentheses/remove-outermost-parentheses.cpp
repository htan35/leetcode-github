class Solution {
public:
    string removeOuterParentheses(string str) {
        stack<char> st;
        string ans;

        for(int i = 0; i < str.size(); i++){
            if(str[i] == '('){
                if(!st.empty()) ans.push_back('('); // skip outermost
                st.push('(');
            }
            else { // ')'
                st.pop();
                if(!st.empty()) ans.push_back(')'); // skip outermost
            }
        }
        return ans;
    }
};