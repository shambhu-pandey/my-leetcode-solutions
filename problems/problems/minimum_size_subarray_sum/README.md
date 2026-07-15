# Minimum Size Subarray Sum

🔗 Link:
https://leetcode.com/problems/minimum-size-subarray-sum/

## Difficulty

Medium

## Tags

Array, Binary Search, Sliding Window, Prefix Sum

## Problem Description

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

&nbsp;
Example 1:


Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.


Example 2:


Input: target = 4, nums = [1,4,4]
Output: 1


Example 3:


Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0


&nbsp;
Constraints:


	1 &lt;= target &lt;= 109
	1 &lt;= nums.length &lt;= 105
	1 &lt;= nums[i] &lt;= 104


&nbsp;
Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).

## Solution

See `solution.cpp`

## Intuition

The problem asks us to find the **minimum length** of a contiguous subarray whose sum is **at least** `target`. 

A brute-force approach would check all possible subarrays, which takes $O(N^2)$ time. However, since all elements in the array are **positive**, adding more elements will always increase (or keep equal) the sum, and removing elements from the left will always decrease it. 

This monotonic nature allows us to use a dynamic window. Instead of starting over for each subarray, we can expand our window to the right to find a valid sum, and then immediately shrink it from the left to find the *smallest* possible valid window.

## Pattern

This problem perfectly fits the **Sliding Window (Variable Size)** pattern. 
* We use two pointers (`left` and `right`) to represent the boundaries of our current subarray (the "window").
* **Expand** phase: Move `right` to include more elements until the condition (`sum >= target`) is met.
* **Shrink** phase: Move `left` to contract the window from the left as long as the condition remains satisfied, updating our minimum length at each step.

## Key Trick

The key trick is the **"Acquire and Release"** mechanism inside the `while` loop:
1. **Acquire**: We keep adding elements using the `right` pointer until our window's sum is $\ge target$.
2. **Release**: The moment `sum >= target`, we don't just stop. We try to discard elements from the `left` (by subtracting `nums[left]` and incrementing `left`) to see if we can get an even smaller valid window. This ensures we find the *local minimum* window ending at `right`.

## Approach

1. **Initialize** `left = 0` (start of window), `sum = 0` (running sum), and `ans = INT_MAX` (to track the minimum length).
2. **Iterate** through the array using a `right` pointer from `0` to `n - 1`.
3. In each iteration, add `nums[right]` to `sum`.
4. Run a `while` loop with the condition `sum >= target`:
   * Calculate the current window length: `len = right - left + 1`.
   * Update the global minimum: `ans = min(ans, len)`.
   * Shrink the window: Subtract `nums[left]` from `sum` and increment `left`.
5. After the loop, check if `ans` was updated. If it is still `INT_MAX`, it means no such subarray exists; return `0`. Otherwise, return `ans`.

## Complexity

### Time: $O(N)$
Although there is a nested `while` loop inside a `for` loop, the `left` pointer only moves forward and never retreats. Each element in the array is visited at most **twice**: once by the `right` pointer (inserted into the sum) and at most once by the `left` pointer (removed from the sum). Thus, the total operations are $2N$, which simplifies to $O(N)$.

### Space: $O(1)$
We only use a few integer variables (`left`, `sum`, `ans`, `len`) to keep track of indices and the running sum. No extra data structures are used.

## Interview Tip

If an interviewer asks you this question, **always ask if the array contains negative numbers**. 
* The Sliding Window approach **only works if all numbers are positive**. 
* If there are negative numbers, the prefix sum is no longer monotonically increasing, and you would need to use a Prefix Sum + Hash Map (similar to "Subarray Sum Equals K") or a Monotonic Queue/Deque approach. Pointing this out beforehand shows excellent depth of knowledge!

## Common Mistake

* **Incorrectly analyzing time complexity**: Many candidates see a nested `while` loop inside a `for` loop and immediately say the time complexity is $O(N^2)$. Clearly explain the amortized analysis (each element is processed at most twice) to show it is $O(N)$.
* **Off-by-one error**: Forgetting the `+ 1` when calculating the window length: `right - left + 1`.
* **Not handling the edge case**: Returning `INT_MAX` instead of `0` when no valid subarray is found.

## Alternative Approach

If the interviewer asks for an alternative solution, or specifically asks for an **$O(N \log N)$** solution (as mentioned in the LeetCode follow-up):

### Binary Search on Prefix Sums
Since all elements are positive, the prefix sum array will be strictly increasing (sorted).
1. Build a prefix sum array `prefix` where `prefix[i]` is the sum of elements from index `0` to `i-1`.
2. For each index `i`, use **binary search** (`lower_bound` in C++) to find the smallest index `j` such that `prefix[j] - prefix[i] >= target`.
3. The length of this subarray is `j - i`. Keep track of the minimum length.
4. This takes $O(N \log N)$ time and $O(N)$ extra space.
