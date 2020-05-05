class Solution {
public:
    int distBtw(vector<int> &p1, vector<int> &p2) {
        int x1 = p1[0], x2 = p2[0];
        int y1 = p1[1], y2 = p2[1];
        int X = abs(x1 - x2), Y = abs(y1 - y2);
        X *= X;
        Y *= Y;
        return X + Y;
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int> > A;
        A.push_back(p1);
        A.push_back(p2);
        A.push_back(p3);
        A.push_back(p4);
        
        unordered_map<int, int> m;
        for(int i = 0; i < 3; i++) {
            for(int j = i + 1; j < 4; j++) {
                m[distBtw(A[i], A[j])]++;
            }
        }
        if(m.size() == 2) {
            for(auto x: m) {
                if(!(x.second == 2 or x.second == 4)) {
                    return false;
                }
            }
            return true;
        }
        
        return false;
    }
};