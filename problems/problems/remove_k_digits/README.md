# Remove K Digits

🔗 Link:
https://leetcode.com/problems/remove-k-digits/

## Difficulty

Medium

## Tags

String, Stack, Greedy, Monotonic Stack

## Problem Description

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

&nbsp;
Example 1:


Input: num = &quot;1432219&quot;, k = 3
Output: &quot;1219&quot;
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.


Example 2:


Input: num = &quot;10200&quot;, k = 1
Output: &quot;200&quot;
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.


Example 3:


Input: num = &quot;10&quot;, k = 2
Output: &quot;0&quot;
Explanation: Remove all the digits from the number and it is left with nothing which is 0.


&nbsp;
Constraints:


	1 &lt;= k &lt;= num.length &lt;= 105
	num consists of only digits.
	num does not have any leading zeros except for the zero itself.



## Solution

See `solution.cpp`
