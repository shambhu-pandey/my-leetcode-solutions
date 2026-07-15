# 🚀 Number of Islands

🔗 **LeetCode Link:**  
https://leetcode.com/problems/number-of-islands/

---

## 🎯 Difficulty

**Medium**

---

## 🏷️ Tags

Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix

---

## 📖 Problem Description

Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 
Example 1:


Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1


Example 2:


Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3


 
Constraints:


	m == grid.length
	n == grid[i].length
	1 <= m, n <= 300
	grid[i][j] is '0' or '1'.



---

## 💻 My Solution

```java
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
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:21:34*
