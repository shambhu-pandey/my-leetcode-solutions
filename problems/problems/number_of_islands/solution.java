class Solution {
    public int numIslands(char[][] grid) {
        if(grid== null || grid.length ==0){
            return 0;
        }

        int islandCount =0;
        int rows = grid.length;
        int cols = grid[0].length;

        for(int r = 0; r<rows;r++){
            for(int c =0; c<cols; c++){
                if(grid[r][c] =='1'){
                    islandCount++;
                    dfs(grid , r,c);
                }
            }
        }
        return islandCount;
    }
    
    private void dfs(char[][] grid, int r, int c) {
        int rows = grid.length;
        int cols = grid[0].length;

        // Base cases: 
        // 1. Out of bounds
        // 2. Cell is water ('0')
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') {
            return;
        }

        // Mark current cell as visited by setting it to '0'
        grid[r][c] = '0';

        // Visit all 4 adjacent directions
        dfs(grid, r - 1, c); // Up
        dfs(grid, r + 1, c); // Down
        dfs(grid, r, c - 1); // Left
        dfs(grid, r, c + 1); // Right
    }
}