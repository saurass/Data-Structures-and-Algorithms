class Solution {
public:    
    string solve(vector<int> &cost, int left, map<int, string> &m) {
        if(m.find(left) != m.end())
            return m[left];
        if(left < 0)
            return "0";
        if(left == 0) {
            return "";
        }
        string vls = "";
        for(int i = 0; i < cost.size(); i++) {
            string tp = solve(cost, left - cost[i], m);
            
            if(tp != "0") {
                tp = to_string(i + 1) + tp;
                if(tp.size() > vls.size()) {
                    vls = tp;
                } else if(tp.size() == vls.size()) {
                    vls = max(tp, vls);
                }
            }
            
        }
        if(vls == "")
            vls = "0";
        m[left] = vls;
        
        return m[left];
    }
    string largestNumber(vector<int>& cost, int target) {
        map<int, string> m;
        return solve(cost, target, m);
    }
};