# Max Consecutive Ones

🔗 Link:
https://leetcode.com/problems/max-consecutive-ones/

## Difficulty

Easy

## Tags

Array

## Problem Description

Given a binary array nums, return the maximum number of consecutive 1&#39;s in the array.

&nbsp;
Example 1:


Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.


Example 2:


Input: nums = [1,0,1,1,0,1]
Output: 2


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 105
	nums[i] is either 0 or 1.



## Solution

See `solution.cpp`

## Intuition

The problem asks us to find the longest contiguous subarray of `1`s. 

Imagine you are watching a game and counting consecutive passes. Every time a teammate successfully passes the ball (encountering a `1`), you increase your count. If the ball is intercepted or dropped (encountering a `0`), your current streak resets to `0`. However, before you reset your counter, you make a mental note of your highest score so far. 

This approach allows us to solve the problem in a single sweep (one pass) through the array.

## Pattern

This solution uses the **Greedy / Running State Tracking** pattern. 
* We maintain a *local state* (`curr_count` representing the current running streak) and a *global state* (`maxCount` representing the best streak seen overall).
* This is a simplified version of the **Sliding Window** pattern, where the window expands when we see `1`s and shrinks/resets to size 0 immediately when we hit a `0`.

## Key Trick

The most critical part of this code is the final return statement: `return max(curr_count, maxCount);`.

In a standard stream, we only update our global maximum `maxCount` when we hit a `0`. However, if the array ends with a streak of `1`s (e.g., `[1, 1, 0, 1, 1, 1]`), we never hit a trailing `0` to trigger the `else` block. The final `max` comparison outside the loop ensures we don't forget to account for the streak ending at the very last index.

## Approach

1. **Initialize** two tracking variables: `curr_count = 0` (for the current streak) and `maxCount = 0` (for the maximum streak found).
2. **Iterate** through the array using a `for` loop:
   * If the current element is `1`, increment `curr_count` by `1`.
   * If the current element is `0`, it means the streak has broken. We update `maxCount` with the maximum of `curr_count` and `maxCount`, then reset `curr_count` to `0`.
3. **Handle Edge Cases**: After the loop finishes, return the maximum of `curr_count` and `maxCount` to handle any ongoing streak that reached the end of the array.

## Complexity

Time: **$O(N)$**  
We traverse the array of size $N$ exactly once. Each element is processed in $O(1)$ constant time.

Space: **$O(1)$**  
We only use a few integer variables (`curr_count`, `maxCount`, `i`, `n`) which consume a constant amount of memory regardless of the input size.

## Interview Tip

In interviews, always watch out for **boundary/ending conditions**. Whenever you write a loop that updates a global state based on a "reset trigger" (like hitting `0` here), ask yourself: 
* *"What happens if the array ends and the reset trigger is never hit?"*
* Handling this post-loop edge case is what separates junior developers from senior ones.

## Common Mistake

A very common bug is writing the code without the final `max(curr_count, maxCount)` return. 

If the input is `[1, 1]`, the program will:
1. See `1` $\rightarrow$ `curr_count = 1`
2. See `1` $\rightarrow$ `curr_count = 2`
3. Exit loop (since there was no `0`, `maxCount` remains `0`).

If you simply `return maxCount`, you will incorrectly return `0` instead of `2`.

## Alternative Approach

We can write cleaner, more intuitive code by updating the `maxCount` **at every step** we see a `1`, rather than waiting for a `0` to trigger the update. This completely eliminates the need for the post-loop `max()` check.

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr_count = 0;
        int maxCount = 0;
        
        for (int num : nums) {
            if (num == 1) {
                curr_count++;
                maxCount = max(maxCount, curr_count); // Update eagerly
            } else {
                curr_count = 0; // Reset quietly
            }
        }
        return maxCount;
    }
};
```
* **Trade-off**: This alternative does slightly more operations because it updates `maxCount` on every `1` (which can be redundant), but it is much less error-prone and highly readable.
