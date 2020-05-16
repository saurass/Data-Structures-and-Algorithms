class Solution {
public:
    // void solve(int n, vector<string)
    int gcd(int a, int b) {
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> ans;
        set<string> ss;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                int x = j, y = i;
                while(gcd(x, y) != 1) {
                    int gc = gcd(x, y);
                    x = x / gc;
                    y = y / gc;
                }
                string st = to_string(x) + "/" + to_string(y);
                ss.insert(st);
            }
        }
        for(auto x: ss)
            ans.push_back(x);
        
        return ans;
    }
};