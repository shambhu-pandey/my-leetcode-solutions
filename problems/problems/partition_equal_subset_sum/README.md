# 🚀 Partition Equal Subset Sum

🔗 **LeetCode Link:**  
https://leetcode.com/problems/partition-equal-subset-sum/

---

## 🎯 Difficulty

**Medium**

---

## 🏷️ Tags

Array, Dynamic Programming

---

## 📖 Problem Description

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

 
Example 1:


Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].


Example 2:


Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.


 
Constraints:


	1 <= nums.length <= 200
	1 <= nums[i] <= 100



---

## 💻 My Solution

```cpp
class Solution {
public:
   
     // Subset Sum DP
   bool sumSubset(vector<int>& nums ,int sum){
     int n = nums.size();

     // DP matrix
     vector<vector<bool>> t(n+1 , vector<bool>(sum+1 , false ));

     // Sum 0 is always possible
     for(int i =0; i<=n;i++){
        t[i][0]=true; 
     }
     // With 0 elements, positive sum impossible
     for(int j =1; j<=sum; j++){
        t[0][j]= false;
     }

     // Fill DP table
     for( int i =1; i<=n;i++){
        for(int j = 1; j<=sum; j++){
            // Include or exclude current element
            if(nums[i-1]<=j){
                t[i][j] = (t[i-1][j-nums[i-1]] || t[i-1][j]);
            }
            // Cannot include current element
            else{
               t[i][j] = t[i-1][j];
            }
        }
     }
     return t[n][sum];
   }
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        int n = nums.size();
        // Find total sum
        for(int i =  0; i<n; i++){
            sum = sum+nums[i];
        }
         // Odd sum cannot be partitioned equally
        if(sum%2!=0){
            return false;
        }
         // Check subset sum of sum/2
         return sumSubset(nums,sum/2);
    }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:21:04*
