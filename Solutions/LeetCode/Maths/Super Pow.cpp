class Solution {
public:
    const int BASE = 1337;
    int superPow(int a, vector<int>& b) {
        int ab = a % BASE;
        if(b.empty())
            return 1;
        
        int rst = 1;
        int lst = b.back();
        for(int i = 0; i < lst; i++) {
            rst = (rst * ab) % BASE;
        }
        b.pop_back();
        
        if(!b.empty()) {
            int rest = superPow(a, b);
            for(int i = 0; i < 10; i++) {
                rst = (rest * rst) % BASE;
            }
        }
        
        return rst;
        
        
    }
};