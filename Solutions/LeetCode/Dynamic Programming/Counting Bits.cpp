class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> D(num + 1, 0);
        if(num == 0)
            return D;
        D[1] = 1;
        if(num == 1)
            return D;
        
        D[2] = 1;
        if(num == 2)
            return D;
        
        for(int i = 3; i <= num; i++) {
            if(i % 2 == 1)
                D[i] = D[i - 1] + 1;
            else
                D[i] = D[i >> 1];
        }
        
        return D;
    }
};