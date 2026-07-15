# Subarray Product Less Than K

🔗 Link:
https://leetcode.com/problems/subarray-product-less-than-k/

## Difficulty

Medium

## Tags

Array, Binary Search, Sliding Window, Prefix Sum

## Problem Description

Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

&nbsp;
Example 1:


Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.


Example 2:


Input: nums = [1,2,3], k = 0
Output: 0


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 3 * 104
	1 &lt;= nums[i] &lt;= 1000
	0 &lt;= k &lt;= 106



## Solution

See `solution.cpp`
