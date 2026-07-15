# String Compression

🔗 Link:
https://leetcode.com/problems/string-compression/

## Difficulty

Medium

## Tags

Two Pointers, String

## Problem Description

Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:


	If the group&#39;s length is 1, append the character to s.
	Otherwise, append the character followed by the group&#39;s length.


The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.

Note: The characters in the array beyond the returned length do not matter and should be ignored.

&nbsp;
Example 1:


Input: chars = [&quot;a&quot;,&quot;a&quot;,&quot;b&quot;,&quot;b&quot;,&quot;c&quot;,&quot;c&quot;,&quot;c&quot;]
Output: 6
Explanation: The groups are &quot;aa&quot;, &quot;bb&quot;, and &quot;ccc&quot;. This compresses to &quot;a2b2c3&quot;.
After modifying the input array in-place, the first 6 characters of chars should be [&quot;a&quot;,&quot;2&quot;,&quot;b&quot;,&quot;2&quot;,&quot;c&quot;,&quot;3&quot;].


Example 2:


Input: chars = [&quot;a&quot;]
Output: 1
Explanation: The only group is &quot;a&quot;, which remains uncompressed since it is a single character.
After modifying the input array in-place, the first character of chars should be [&quot;a&quot;].


Example 3:


Input: chars = [&quot;a&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;]
Output: 4
Explanation: The groups are &quot;a&quot; and &quot;bbbbbbbbbbbb&quot;. This compresses to &quot;ab12&quot;.
After modifying the input array in-place, the first 4 characters of chars should be [&quot;a&quot;,&quot;b&quot;,&quot;1&quot;,&quot;2&quot;].


&nbsp;
Constraints:


	1 &lt;= chars.length &lt;= 2000
	chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.



## Solution

See `solution.cpp`
