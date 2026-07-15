# Palindromic Substrings

🔗 Link:
https://leetcode.com/problems/palindromic-substrings/

## Difficulty

Medium

## Tags

Two Pointers, String, Dynamic Programming

## Problem Description

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

&nbsp;
Example 1:


Input: s = &quot;abc&quot;
Output: 3
Explanation: Three palindromic strings: &quot;a&quot;, &quot;b&quot;, &quot;c&quot;.


Example 2:


Input: s = &quot;aaa&quot;
Output: 6
Explanation: Six palindromic strings: &quot;a&quot;, &quot;a&quot;, &quot;a&quot;, &quot;aa&quot;, &quot;aa&quot;, &quot;aaa&quot;.


&nbsp;
Constraints:


	1 &lt;= s.length &lt;= 1000
	s consists of lowercase English letters.



## Solution

See `solution.cpp`

## Intuition

A palindrome reads the same backward as forward. The naive (brute-force) way to count palindromes is to check every possible substring, which is highly repetitive and inefficient ($O(N^3)$ time complexity).

To optimize, we can invert our perspective: instead of picking a substring and checking if it is a palindrome from the **outside-in**, we can choose a center and expand **inside-out**. 

If a substring is a palindrome (e.g., `"aba"`), then expanding it by one character on both sides (e.g., `"xabay"`) only requires checking if the two new boundary characters are equal (`'x' == 'y'`). If they match, the new string is also a palindrome. This avoids redundant checks.

---

## Pattern

**Expand Around Center (Two Pointers)**. 
This is a standard pattern for palindromic substring problems. It leverages the symmetric nature of palindromes by positioning pointers at a potential center and moving them outwards.

---

## Key Trick

A palindrome can have one of two types of centers:
1. **Odd-length palindromes** (e.g., `"aba"`): centered at a single character (`'b'`).
2. **Even-length palindromes** (e.g., `"abba"`): centered between two characters (`'b'` and `'b'`).

By initiating expansions from both `(i, i)` (odd) and `(i, i + 1)` (even) for every index `i`, we systematically discover all possible palindromic substrings.

---

## Approach

1. **Initialize** a global `count = 0` to track the total number of palindromic substrings.
2. **Iterate** through the string with a loop variable `i` from `0` to `n - 1`. Each index `i` is treated as a potential center.
3. For each index `i`, perform two expansions:
   * **Odd expansion**: Call `expand(s, i, i)`.
   * **Even expansion**: Call `expand(s, i, i + 1)`.
4. Inside the `expand` helper function:
   * Use a `left` and `right` pointer.
   * While `left` and `right` are within bounds and `s[left] == s[right]`:
     * Increment `count` (we found a valid palindromic substring).
     * Move `left` one step left (`left--`) and `right` one step right (`right++`).
5. Return the total accumulated `count`.

---

## Complexity

### Time: $O(N^2)$
There are $2N - 1$ possible centers (each single character and each gap between characters). From each center, the maximum expansion possible is $O(N/2)$. Therefore, the worst-case time complexity is $O(N^2)$, which occurs for highly symmetric strings like `"aaaa"`.

### Space: $O(1)$
We only use a few constant-size pointers (`left`, `right`, `count`, `i`). Passing the string `s` by reference (`string &s`) ensures no extra copies of the string are made in memory.

---

## Interview Tip

When an interviewer asks you a palindrome question, always ask yourself: **"Should I build from the inside-out or validate from the outside-in?"**
* **Outside-in** (classic two-pointer) is perfect for *validating* if a single, specific string is a palindrome.
* **Inside-out** (Expand Around Center) is perfect for *finding or counting* palindromes across a large string because it reuses previous validation work.

---

## Common Mistake

* **Passing the string by value**: In C++, writing `int expand(string s, ...)` instead of `int expand(string &s, ...)` will copy the entire string on every single function call. This turns your $O(N^2)$ time solution into $O(N^3)$ and will likely result in a **TLE (Time Limit Exceeded)** error.
* **Out-of-bounds errors**: Forgetting to check if `left >= 0` and `right < s.size()` before verifying `s[left] == s[right]`.

---

## Alternative Approach

### 1. Dynamic Programming ($O(N^2)$ Time, $O(N^2)$ Space)
We can maintain a 2D boolean table `dp[i][j]` where `dp[i][j] = true` if the substring `s[i...j]` is a palindrome.
* **Transition**: `dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1]`.
* *Drawback*: While it has the same time complexity as the expansion method, it requires $O(N^2)$ auxiliary space.

### 2. Manacher's Algorithm ($O(N)$ Time, $O(N)$ Space)
Manacher's Algorithm is a highly optimized linear-time algorithm designed specifically to find all palindromes in a string. It works by keeping track of the mirror properties of palindromes to skip redundant expansion steps.
* *Drawback*: Extremely complex to implement under interview time constraints. It is best to mention it to the interviewer to showcase advanced knowledge, but stick to the **Expand Around Center** approach for coding.
