class Solution {
public:
    int posOfChar(string s, char ch) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ch)
                return i;
        }
        
        return -1;
    }
    
    int firstUniqChar(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<char, int> m;
        vector<int> vis(s.size(), 0);
        for(int i = 0; i < s.size(); i++) {
            if(m.find(s[i]) == m.end()) {
                m[s[i]] = i;
            }
            vis[m[s[i]]]++;
        }
        
        int ans = -1;
        for(int i = 0; i < vis.size(); i++) {
            if(vis[i] == 1) {
                ans = i;
                break;
            }
        }
        
        return ans;
    }
};