class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        for(int i = 0; i < magazine.length(); i++) {
            ransomNote = ransomNote.replaceFirst(String.valueOf(magazine.charAt(i)), "");
        }
        ransomNote = ransomNote.trim();
        return ransomNote.length() == 0;
    }
}