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

## Intuition

The problem asks us to find the number of contiguous subarrays where the product of all elements is strictly less than $k$. 

A naive approach would check every possible subarray, which takes $O(N^2)$ time. However, because all elements in the input array are positive integers ($\ge 1$), multiplying by more elements will **monotonically increase** (or keep equal) the product. 

This monotonicity is a classic indicator that we can use a **Sliding Window (Two Pointers)** approach. If a window $[L, R]$ has a product less than $k$, then any sub-segment ending at $R$ (i.e., $[L, R], [L+1, R], \dots, [R, R]$) will also have a product less than $k$. 

---

## Pattern

This problem falls under the **Variable-Sized Sliding Window / Two Pointers** pattern. 
* We expand the window by moving the `right` pointer to include new elements.
* We shrink the window from the `left` when the window violates our condition (i.e., `product >= k`).

---

## Key Trick

1. **The Edge Case ($k \le 1$):**
   Since the elements in `nums` are positive integers ($\ge 1$), the minimum possible product of any subarray is $1$. If $k \le 1$, it is mathematically impossible to have any subarray with a product strictly less than $k$. Handling this case upfront (`if (k <= 1) return 0;`) prevents infinite loops and division-by-zero errors during window shrinking.

2. **The Counting Formula (`right - left + 1`):**
   When we have a valid window $[L, R]$ where the product is less than $k$, how many *new* valid subarrays are introduced by introducing the element at index $R$?
   
   If our window is `[10, 5, 2]` (indices 0 to 2), the valid subarrays ending at index 2 are:
   * `[2]` (length 1)
   * `[5, 2]` (length 2)
   * `[10, 5, 2]` (length 3)
   
   The number of newly introduced subarrays is exactly equal to the length of the window: `right - left + 1`.

---

## Approach

1. **Edge Case Check**: If $k \le 1$, return `0` immediately.
2. **Initialize Pointers**: Set `left = 0`, `prod = 1`, and `count = 0`.
3. **Expand Window**: Iterate `right` from `0` to `n - 1`.
   * Multiply `nums[right]` to our running `prod`.
4. **Shrink Window**: While `prod >= k`, divide `prod` by `nums[left]` and increment `left`. This restores the valid window condition.
5. **Count Subarrays**: Add the size of the current window (`right - left + 1`) to `count`.
6. Return the total `count`.

---

## Complexity

### Time: $O(N)$
Although there is a nested `while` loop inside the `for` loop, the `left` pointer can only travel from `0` to `n-1` *at most once* across the entire execution. Each element is visited at most twice (once by `right`, once by `left`). This is called **amortized $O(1)$** time per step, resulting in an overall $O(N)$ time complexity.

### Space: $O(1)$
Only a few variables (`left`, `count`, `prod`) are used. No extra space scaling with input size is allocated.

---

## Interview Tip

In interviews, when presenting a nested loop solution like this, candidates often accidentally analyze the time complexity as $O(N^2)$ because of the nested `while` loop. 

**How to impress the interviewer:**
Explain the **amortized analysis** explicitly: 
> *"Even though there is a nested while loop, the `left` pointer only moves forward and never backtracks. Since both `left` and `right` pointers can step at most $N$ times, the total operations of pointer movements are capped at $2N$. Hence, the time complexity is strictly linear, $O(N)$."*

---

## Common Mistake

* **Forgetting the `k <= 1` check:** 
  If $k = 0$ and the array is `[1, 2, 3]`, without the guard clause, `prod >= k` will always be true ($1 \ge 0$). The `while` loop will continuously try to shrink the window, dividing `prod` and incrementing `left` past the array bounds, causing a **segmentation fault** or **out-of-bounds error**.

---

## Alternative Approach

### Logarithmic Prefix Sum + Binary Search
Since products can grow extremely large (potentially causing integer overflow in other languages if we didn't divide on the fly), we can convert the multiplication problem into an addition problem using logarithms:
$$\log(\prod x_i) = \sum \log(x_i)$$

1. Transform the array `nums` into an array of its logarithms: `logs[i] = log(nums[i])`.
2. Compute the prefix sums of this `logs` array.
3. For each starting position, use binary search (`std::upper_bound`) to find the furthest index where the sum is less than $\log(k) - \epsilon$ (to handle precision errors).

* **Time Complexity:** $O(N \log N)$
* **Space Complexity:** $O(N)$
* **Note:** This approach is mathematically elegant but slower than the Sliding Window approach and prone to floating-point precision issues. It is best kept as a talking point in an interview rather than the primary implementation.
