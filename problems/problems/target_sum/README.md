# Target Sum

🔗 Link:
https://leetcode.com/problems/target-sum/

## Difficulty

Medium

## Tags

Array, Dynamic Programming, Backtracking

## Problem Description

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols &#39;+&#39; and &#39;-&#39; before each integer in nums and then concatenate all the integers.


	For example, if nums = [2, 1], you can add a &#39;+&#39; before 2 and a &#39;-&#39; before 1 and concatenate them to build the expression &quot;+2-1&quot;.


Return the number of different expressions that you can build, which evaluates to target.

&nbsp;
Example 1:


Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3


Example 2:


Input: nums = [1], target = 1
Output: 1


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 20
	0 &lt;= nums[i] &lt;= 1000
	0 &lt;= sum(nums[i]) &lt;= 1000
	-1000 &lt;= target &lt;= 1000



## Solution

See `solution.cpp`

## Intuition

The problem asks us to assign a `+` or `-` sign to each integer in an array to make their sum equal to `target`. 

If we partition the array into two subsets:
1. $S_1$: The subset of elements assigned a `+` sign.
2. $S_2$: The subset of elements assigned a `-` sign.

We can write two equations:
1. $sum(S_1) - sum(S_2) = target$
2. $sum(S_1) + sum(S_2) = sum(nums)$

Adding these two equations together gives:
$$2 \cdot sum(S_1) = target + sum(nums)$$
$$sum(S_1) = \frac{target + sum(nums)}{2}$$

Thus, the problem of assigning signs simplifies to finding the **number of subsets $S_1$ whose sum is exactly equal to $\frac{target + sum(nums)}{2}$**.

---

## Pattern

This problem belongs to the **0/1 Knapsack / Subset Sum** pattern. Instead of finding if a subset sum exists (boolean DP), we count the total number of ways to form a specific subset sum.

---

## Key Trick

1. **Mathematical Reduction**: Transforming a $2^N$ search space (assigning signs) into a classic Subset Sum DP problem with target $s1 = (target + sum)/2$.
2. **Parity Check**: Since the elements are integers, $(target + sum)$ must be even. If $(target + sum) \pmod 2 \neq 0$, it is mathematically impossible to split the array, so we return `0` immediately.
3. **Bound Check**: If the absolute value of `target` is greater than the total sum of elements, it is impossible to reach the target; we return `0`.

---

## Approach

1. **Calculate Total Sum**: Traverse `nums` to find the total sum.
2. **Early Pruning**: Check if `(target + sum)` is odd or if `abs(target) > sum`. If either is true, return `0`.
3. **Target Transformation**: Calculate the target subset sum: `s1 = (target + sum) / 2`.
4. **DP Table Initialization**: 
   * Create a 2D table `t` of size `(n + 1) x (s1 + 1)` initialized to `0`.
   * Base Case: `t[0][0] = 1` (there is exactly 1 way to make a sum of `0` using `0` elements: the empty subset).
5. **Iterative DP Fill**:
   * For each element `nums[i-1]` and each target `j` from `0` to `s1`:
     * If the element is smaller than or equal to the current sum `j`, we have two choices: include it or exclude it.
       `t[i][j] = t[i-1][j - nums[i-1]] + t[i-1][j]`
     * Otherwise, we can only exclude it.
       `t[i][j] = t[i-1][j]`
6. **Return**: The value at `t[n][s1]`.

---

## Complexity

### Time: $O(N \cdot S)$
Where $N$ is the size of the array `nums` and $S$ is the target subset sum `s1`. The nested loops run exactly $N \times S$ times.

### Space: $O(N \cdot S)$
Due to the 2D grid of size $(N+1) \times (S+1)$ used to store the DP states.

---

## Interview Tip

When explaining this in an interview, do not jump straight to the DP table. 
1. Start with the **Backtracking (Brute Force)** approach ($O(2^N)$) to show you understand the decision tree.
2. Introduce the **Algebraic Reduction** to show how the problem simplifies to Subset Sum.
3. Highlight how you handle edge cases (like negative targets and odd sums) before writing code. This shows attention to defensive programming.

---

## Common Mistake

### Handling Zeros
Many DP implementations of Subset Sum initialize the first column `t[i][0] = 1` and start the inner loop `j` from `1`. **This fails if `nums` contains zeros.**
If an element is `0`, it can either be assigned a `+` or `-` sign, doubling the number of valid subsets. 

By starting the inner loop at `j = 0` (as done in this code: `for(int j=0; j<=target; j++)`), the algorithm correctly handles zeros:
`t[i][j] = t[i-1][j-0] + t[i-1][j]` correctly doubles the combinations when `nums[i-1] == 0`.

---

## Alternative Approach

### Space-Optimized 1D DP
Since the state `t[i][j]` only depends on the previous row `t[i-1]`, we can optimize the space complexity to $O(S)$ by using a 1D array and iterating **backwards** (from `s1` down to `0`) to avoid using updated values from the current iteration.

```cpp
int countSubset(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1; // Base case

    for (int num : nums) {
        for (int j = target; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }
    return dp[target];
}
```
**Space Complexity of this alternative**: $O(S)$ — highly recommended to show as an optimization during interviews!
