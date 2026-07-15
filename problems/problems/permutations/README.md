# Permutations

🔗 Link:
https://leetcode.com/problems/permutations/

## Difficulty

Medium

## Tags

Array, Backtracking

## Problem Description

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

&nbsp;
Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:
Input: nums = [1]
Output: [[1]]

&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 6
	-10 &lt;= nums[i] &lt;= 10
	All the integers of nums are unique.



## Solution

See `solution.cpp`

## Intuition

To generate all permutations of an array, we need to try every possible element at every possible position. 

Think of this as building a tree of choices:
1. For the first position (`index = 0`), we can choose any element from index `0` to `n-1`. We make a choice by **swapping** the element at `index` with the element at `j`.
2. Once the first position is locked in, we move to the second position (`index = 1`) and choose from the remaining elements.
3. We repeat this process recursively until we reach the end of the array, at which point we have formed a unique permutation.
4. To explore other paths, we must undo our choice—this is **backtracking** (swapping back).

---

## Pattern

This problem follows the **Backtracking (State-Space Tree Exploration)** pattern. Specifically, it uses the **In-Place Swapping** technique to generate permutations without requiring extra memory to track used elements.

---

## Key Trick

The key trick here is **swapping in-place**. 

Instead of using a separate boolean array (like `visited[]`) to keep track of which numbers have already been used, we partition the array into two parts:
* **Decided Prefix:** `nums[0 ... index-1]` (already fixed for the current permutation path).
* **Undecided Suffix:** `nums[index ... n-1]` (elements still available to be placed at the current `index`).

By swapping `nums[index]` with any `nums[j]` (where `j >= index`), we dynamically move elements into the "decided" portion.

---

## Approach

1. **Base Case:** If `index` reaches the size of the array, it means all positions have been decided. We add the current state of `nums` to our answer list and return.
2. **Recursive Step:** Loop `j` from the current `index` to the end of the array:
   * **Swap:** Swap `nums[index]` with `nums[j]` to place `nums[j]` at the current position.
   * **Recurse:** Call `solve` with `index + 1` to solve the subproblem for the remaining elements.
   * **Backtrack:** Swap `nums[index]` back with `nums[j]` to restore the original array configuration before moving to the next iteration of the loop.

---

## Complexity

Let $N$ be the number of elements in `nums`.

### Time: $O(N \cdot N!)$
There are $N!$ (N factorial) possible permutations. For each permutation, we spend $O(N)$ time to copy the array into the `ans` list at the base case. 

*(Note: In the provided code, passing `nums` by value makes an $O(N)$ copy at every single recursion step, which significantly increases the runtime constant factor. If passed by reference, the recursive tree overhead is minimized).*

### Space: $O(N)$
* **Auxiliary Space:** $O(N)$ recursion stack depth.
* **Total Space:** $O(N \cdot N!)$ if we count the space required to store the $N!$ output permutations of size $N$.

---

## Interview Tip

In interviews, if you are asked to generate permutations, always clarify:
1. **Are duplicates allowed?** (If yes, you need a different strategy, usually sorting first and skipping duplicates, like in *Permutations II*).
2. **Does the output order matter?** (The swap-based approach does not generate permutations in lexicographical/sorted order. If sorted order is required, you must sort the input first and use a `visited` array state-space approach instead).

---

## Common Mistake

### 1. Passing by Value instead of Reference
In the provided code:
```cpp
void solve(vector<int> nums , int index , vector<vector<int>>& ans)
```
`nums` is passed **by value**. This means C++ creates a brand-new copy of the vector at *every single recursive call*. 
* This makes the backtracking step (`swap(nums[index], nums[j])` after recursion) completely redundant because changes are made to a local copy anyway.
* This dramatically increases memory usage and slows down execution.

**Correction:** Pass it by reference:
```cpp
void solve(vector<int>& nums , int index , vector<vector<int>>& ans)
```

---

## Alternative Approach

### 1. Using a `visited` array (DFS State Space)
If we don't want to modify the input array using swaps, we can use a temporary path vector and a boolean array to track which elements are already used:

```cpp
void backtrack(vector<int>& nums, vector<int>& path, vector<bool>& visited, vector<vector<int>>& ans) {
    if (path.size() == nums.size()) {
        ans.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        path.push_back(nums[i]);
        backtrack(nums, path, visited, ans);
        path.pop_back(); // backtrack
        visited[i] = false; // backtrack
    }
}
```
* **Pros:** Easier to adapt to handle duplicate elements; preserves the relative order (lexicographical).
* **Cons:** Uses $O(N)$ extra memory for the `visited` array and `path` vector.

### 2. Using STL (`std::next_permutation`)
In a real-world C++ scenario (or if allowed in an interview), you can use the built-in library function:

```cpp
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end()); // Crucial step
    do {
        ans.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return ans;
}
```
