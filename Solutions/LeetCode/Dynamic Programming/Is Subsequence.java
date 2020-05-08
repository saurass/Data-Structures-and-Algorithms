class Solution {
    public boolean isSubsequence(String s, String t) {
        if(s.length() == 0)
            return true;
        char current_ch = s.charAt(0);
        int current_pos = 0;
        
        for(int i = 0; i < t.length(); i++) {
            if(t.charAt(i) == current_ch) {
                current_pos++;
                if(current_pos == s.length())
                    return true;
                current_ch = s.charAt(current_pos);
            }
        }
        
        return false;
        
    }
}