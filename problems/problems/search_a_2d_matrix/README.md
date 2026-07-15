# 🚀 Search a 2D Matrix

🔗 **LeetCode Link:**  
https://leetcode.com/problems/search-a-2d-matrix/

---

## 🎯 Difficulty

**Medium**

---

## 🏷️ Tags

Array, Binary Search, Matrix

---

## 📖 Problem Description

You are given an m x n integer matrix matrix with the following two properties:


	Each row is sorted in non-decreasing order.
	The first integer of each row is greater than the last integer of the previous row.


Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.

 
Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true


Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false


 
Constraints:


	m == matrix.length
	n == matrix[i].length
	1 <= m, n <= 100
	-104 <= matrix[i][j], target <= 104



---

## 💻 My Solution

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row =matrix.size();
        int col = matrix[0].size();  // ek pahla row pakad liya uska size then total no of col

        int start =0;
        int end = row*col -1; 
        int mid =  start + (end-start)/2;

        while(start<=end){
           int element = matrix[mid/col][mid%col];

           if(element == target){
            return 1;
           }

           else if(element < target){
            start = mid+1;
           }
           else{
            end = mid-1;
           }

           mid = start + (end-start)/2;
        }
        return 0;
    }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:21:29*
