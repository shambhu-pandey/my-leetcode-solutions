# Partition Equal Subset Sum

🔗 Link:
https://leetcode.com/problems/partition-equal-subset-sum/

## Difficulty

Medium

## Tags

Array, Dynamic Programming

## Problem Description

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

&nbsp;
Example 1:


Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].


Example 2:


Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 200
	1 &lt;= nums[i] &lt;= 100



## Solution

See `solution.cpp`

## Intuition

The problem asks if we can partition an array into two subsets with equal sums. 

If we can split the array into two subsets $S_1$ and $S_2$ such that $\text{sum}(S_1) = \text{sum}(S_2)$, then:
$$\text{sum}(S_1) + \text{sum}(S_2) = \text{Total Sum}$$
$$2 \cdot \text{sum}(S_1) = \text{Total Sum}$$
$$\text{sum}(S_1) = \frac{\text{Total Sum}}{2}$$

This mathematical reduction transforms the problem into: **"Can we find a subset of elements that sums up to exactly $\frac{\text{Total Sum}}{2}$?"**

---

## Pattern

This is a classic variation of the **0/1 Knapsack Pattern**. 
* **Items**: The numbers in the array.
* **Capacity**: The target sum ($\frac{\text{Total Sum}}{2}$).
* **Decision**: For each number, we have two choices: either **include** it in our subset or **exclude** it.

---

## Key Trick

1. **Parity Check (Odd/Even Sum)**: If the total sum of the array is odd, it is mathematically impossible to split it into two equal integer subsets. We can return `false` immediately.
2. **DP Grid Formulation**: We use a 2D boolean grid `t[i][j]` where:
   * `i` represents the first `i` elements considered.
   * `j` represents the target subset sum we want to achieve.

---

## Approach

1. **Sum Calculation & Parity Check**: Sum up all elements. If the sum is odd, return `false`. Otherwise, set `target = sum / 2`.
2. **DP Initialization**: Create a 2D vector `t` of size `(n + 1) x (target + 1)` initialized to `false`.
   * **Base Case 1**: A sum of `0` is always possible (by choosing an empty subset). Thus, `t[i][0] = true` for all $i$.
   * **Base Case 2**: With `0` elements, any sum $j > 0$ is impossible. Thus, `t[0][j] = false` (already handled by default initialization).
3. **State Transition**:
   * For each element $i$ (from $1$ to $n$) and target sum $j$ (from $1$ to $target$):
     * **If we can include the current element** (`nums[i-1] <= j`):
       We can either *exclude* it (look at `t[i-1][j]`) or *include* it (look at `t[i-1][j - nums[i-1]]`).
       $$t[i][j] = t[i-1][j] \text{ OR } t[i-1][j - nums[i-1]]$$
     * **If we cannot include the current element** (`nums[i-1] > j`):
       We must *exclude* it.
       $$t[i][j] = t[i-1][j]$$
4. **Answer**: The result is stored in `t[n][target]`.

---

## Complexity

### Time: $O(N \times W)$
Where $N$ is the size of the array and $W$ is the `target` sum ($\frac{\text{Total Sum}}{2}$). We fill a grid of size $N \times W$, doing $O(1)$ work per cell.

### Space: $O(N \times W)$
Required to store the 2D DP matrix.

---

## Interview Tip

When presented with this problem in an interview, **always start by discussing the odd sum base case**. It shows the interviewer that you think about edge cases and mathematical constraints before jumping into coding. 

Additionally, be ready for the follow-up question: *"Can you optimize the space complexity?"* (See **Alternative Approach** below).

---

## Common Mistake

* **1-Based vs. 0-Based Indexing**: A very common bug in 2D DP is using `nums[i]` instead of `nums[i-1]`. Because our DP table has an extra row representing "0 elements", the element representing step $i$ in the DP table corresponds to index $i-1$ in the `nums` array.
* **Iterating Sums from `0`**: Ensure you start your target sum loop (`j`) from `1` to avoid overwriting your base cases where `t[i][0] = true`.

---

## Alternative Approach

We can optimize the space from **$O(N \times W)$** to **$O(W)$** because the current row `t[i]` only depends on the previous row `t[i-1]`. 

### Space-Optimized 1D DP Solution:
To do this in 1D, we must iterate the target sum `j` **backwards** (from `target` down to `nums[i]`). This prevents us from using the same element multiple times (which would turn it into an Unbounded Knapsack problem).

```cpp
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int num : nums) sum += num;
    if (sum % 2 != 0) return false;
    
    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true; // Sum of 0 is always possible

    for (int num : nums) {
        for (int j = target; j >= num; j--) {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    return dp[target];
}
```
**Space Complexity:** $O(W)$ which is highly optimal.
