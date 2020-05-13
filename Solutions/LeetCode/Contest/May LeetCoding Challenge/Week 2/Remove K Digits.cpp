class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k >= n)
            return "0";

        string ans = "";
        for(int i = 0; i < n; i++) {
            while(ans.size() != 0 and num[i] < ans[ans.size() - 1] and k) {
                k--;
                ans.pop_back();
            }
            ans += num[i];
        }
        
        while(k--)
            ans.pop_back();
        
        while(ans[0] == '0') {
            ans = ans.substr(1);
        }
        if(ans.size() == 0)
            return "0";
        return ans;        
    }
};