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

## Intuition

The problem asks us to compress an array of characters in-place. The core intuition is to process the array in groups of consecutive repeating characters. For each group, we need to keep track of the character and count how many times it repeats. 

Since the compressed version of any group is guaranteed to be shorter than or equal to the original group (e.g., `"aaaa"` of length 4 becomes `"a4"` of length 2; `"a"` of length 1 stays `"a"` of length 1), we can overwrite the original array from left to right as we compute the compressed representation.

---

## Pattern

This solution uses the **Two-Pointer (Read/Write)** pattern:
1. **Read Pointer (`i`):** Scans the original array to identify groups of identical characters and measure their lengths.
2. **Write Pointer (`idx`):** Keeps track of where the compressed characters and digits should be written back into the array.

Because the write pointer `idx` never overtakes the read pointer `i`, we can safely modify the array in-place without destroying data we still need to read.

---

## Key Trick

* **Safe In-Place Overwriting:** The write index `idx` is always $\le$ the read index `i`. This mathematically guarantees we will never overwrite a character that we haven't processed yet.
* **Digit Separation:** When the count of a character is $\ge 10$, it cannot be written as a single integer. Converting the integer `count` to a string (`to_string(count)`) allows us to iterate through and write its individual digits sequentially (e.g., `12` becomes `'1'` and `'2'`).

---

## Approach

1. Initialize `idx = 0` to track the write position.
2. Iterate through the array using a loop variable `i` from $0$ to $n-1$:
   * Store the current character `ch = chars[i]`.
   * Use a nested `while` loop to count consecutive occurrences of `ch`, incrementing `i` for each match.
   * Write `ch` at `chars[idx++]`.
   * If the count is greater than 1, convert the count to a string and write each digit character-by-character to `chars[idx++]`.
   * Since the inner loop increments `i` past the end of the current group, decrement `i` (`i--`) at the end of the outer loop to compensate for the outer loop's automatic `i++`.
3. Resize the vector to `idx` to discard any leftover characters from the original uncompressed string.
4. Return `idx` as the new size.

---

## Complexity

### Time: $O(N)$
* Each character in the array is visited at most twice: once by the inner `while` loop to count duplicates, and once (indirectly) when the outer loop skips over them. 
* Converting the count to a string takes $O(\log_{10}(\text{count}))$ time, which is extremely small (at most $4$ operations since $N \le 2000$).

### Space: $O(1)$ (Auxiliary)
* The compression is performed in-place. 
* The only extra space used is for storing the string representation of the count (at most 4 characters), which requires $O(1)$ auxiliary memory.

---

## Interview Tip

When an interviewer asks you to modify an array "in-place," always think about using **Two Pointers**. 
* Start by explaining *why* it is safe to overwrite the array: *"Because the compressed string is always shorter than or equal to the uncompressed string, the write pointer will never outrun the read pointer."* Proving this fact first shows strong analytical thinking.

---

## Common Mistake

* **The Overshoot Bug:** In the provided code, the inner loop terminates when `chars[i] != ch`. At this point, `i` is already pointing to the *next* new character. If you forget to decrement `i` (`i--`) before the outer loop's next iteration, the outer loop's `i++` will skip the first character of the next group entirely.
* **Ignoring Multi-digit Counts:** Assuming the count will always be a single digit. If a character appears 12 times, writing it as `chars[idx++] = count + '0'` will write a non-digit ASCII character instead of `'1'` and `'2'`.

---

## Alternative Approach

Instead of using `i--` to correct the overshoot of the outer `for` loop (which is often prone to off-by-one errors), we can structure the traversal using a single `while` loop. This makes the pointer logic much cleaner and less error-prone:

```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;
        int read = 0;

        while (read < n) {
            char currentChar = chars[read];
            int count = 0;

            // Count occurrences of the current character
            while (read < n && chars[read] == currentChar) {
                read++;
                count++;
            }

            // Write the character
            chars[write++] = currentChar;

            // Write the count if it's greater than 1
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[write++] = c;
                }
            }
        }
        
        chars.resize(write);
        return write;
    }
};
```
