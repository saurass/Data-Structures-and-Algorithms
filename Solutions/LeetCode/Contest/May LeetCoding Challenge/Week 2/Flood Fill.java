/*
https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3326/
*/
class Solution {
    class Pair {
        int x;
        int y;
        public Pair(int r, int c) {
            this.x = r;
            this.y = c;
        }
    }
    
    boolean isValid(int x, int y, int n, int m) {
        if(x < 0 || y < 0 || x >= n || y >= m)
            return false;
        return true;
    }
    
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int[] rs = {0, 1, -1, 0};
        int[] cs = {1, 0, 0, -1};
        
        int n = image.length, m = image[0].length;
        boolean vis[][] = new boolean[n][m];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vis[i][j] = false;
            }
        }
        
        // Perform BFS
        int sps = image[sr][sc];
        image[sr][sc] = newColor;
        Pair tp = new Pair(sr, sc);
        Queue<Pair> q = new LinkedList<>();
        q.add(tp);
        
        
        while(q.size() != 0) {
            Pair tps = q.peek();
            q.remove();
            int rr = tps.x, cc = tps.y;
            for(int i = 0; i < 4; i++ ) {
                int nrr = rr + rs[i];
                int ncc = cc + cs[i];
                
                if(isValid(nrr, ncc, n, m) == true && vis[nrr][ncc] == false && image[nrr][ncc] == sps) {
                    vis[nrr][ncc] = true;
                    image[nrr][ncc] = newColor;
                    Pair np = new Pair(nrr, ncc);
                    q.add(np);
                }
            }
        }
        
        return image;
        
    }
}