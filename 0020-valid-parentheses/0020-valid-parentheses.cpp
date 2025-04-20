class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(char c : s){
            if(c == ')'){
                if(st.empty() || st.top() != '(') return false;
                else st.pop();
            }
            else if(c == ']'){
                if(st.empty() || st.top() != '[') return false;
                else st.pop();
            }
            else if(c =='}'){
                if(st.empty() || st.top() != '{') return false;
                else st.pop();
            }
            else st.push(c);

        }
        
        return st.size() == 0 ? true : false;
    }
};