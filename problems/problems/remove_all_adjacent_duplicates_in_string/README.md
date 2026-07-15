# Remove All Adjacent Duplicates In String

🔗 Link:
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

## Difficulty

Easy

## Tags

String, Stack

## Problem Description

You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

&nbsp;
Example 1:


Input: s = &quot;abbaca&quot;
Output: &quot;ca&quot;
Explanation: 
For example, in &quot;abbaca&quot; we could remove &quot;bb&quot; since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is &quot;aaca&quot;, of which only &quot;aa&quot; is possible, so the final string is &quot;ca&quot;.


Example 2:


Input: s = &quot;azxxzy&quot;
Output: &quot;ay&quot;


&nbsp;
Constraints:


	1 &lt;= s.length &lt;= 105
	s consists of lowercase English letters.



## Solution

See `solution.cpp`
