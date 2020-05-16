class Solution {
public:
    int maxPower(string s) {
        stack<char> st;
        int ans = 1, lc = 1;
        for(int i = 0; i < s.size(); i++) {
            if(st.empty()) {
                st.push(s[i]);
                continue;
            }
            if(st.top() == s[i]) {
                lc++;
            } else {
                lc = 1;
            }
            st.push(s[i]);
            
            ans = max(ans, lc);
        }
        
        return ans;
    }
};