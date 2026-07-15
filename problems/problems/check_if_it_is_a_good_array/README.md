# Check If It Is a Good Array

🔗 Link:
https://leetcode.com/problems/check-if-it-is-a-good-array/

## Difficulty

Hard

## Tags

Array, Math, Number Theory

## Problem Description

Given an array nums of&nbsp;positive integers. Your task is to select some subset of nums, multiply each element by an integer and add all these numbers.&nbsp;The array is said to be&nbsp;good&nbsp;if you can obtain a sum of&nbsp;1&nbsp;from the array by any possible subset and multiplicand.

Return&nbsp;True&nbsp;if the array is good&nbsp;otherwise&nbsp;return&nbsp;False.

&nbsp;
Example 1:


Input: nums = [12,5,7,23]
Output: true
Explanation: Pick numbers 5 and 7.
5*3 + 7*(-2) = 1


Example 2:


Input: nums = [29,6,10]
Output: true
Explanation: Pick numbers 29, 6 and 10.
29*1 + 6*(-3) + 10*(-1) = 1


Example 3:


Input: nums = [3,6]
Output: false


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 10^5
	1 &lt;= nums[i] &lt;= 10^9



## Solution

See `solution.cpp`
