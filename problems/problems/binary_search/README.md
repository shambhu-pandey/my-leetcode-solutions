# Binary Search

🔗 Link:
https://leetcode.com/problems/binary-search/

## Difficulty

Easy

## Tags

Array, Binary Search

## Problem Description

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

&nbsp;
Example 1:


Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4


Example 2:


Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 104
	-104 &lt; nums[i], target &lt; 104
	All the integers in nums are unique.
	nums is sorted in ascending order.



## Solution

See `solution.cpp`

## Intuition

The core intuition behind Binary Search is "divide and conquer." Instead of scanning a sorted array linearly from start to finish (which takes $O(N)$ time), we can leverage the sorted property to discard half of the remaining search space at each step. 

Think of looking up a word in a physical dictionary: you don't start at page one; you open it to the middle. If the word you want comes alphabetically after the middle page, you completely ignore the first half of the book and repeat the process on the second half.

## Pattern

This problem utilizes the **Two-Pointer (Binary Search)** pattern over a sorted search space. 
* **When to use:** Whenever you need to find an element, a boundary, or an optimal value in a **sorted sequence** or monotonic search space.
* **Key characteristic:** The search space is halved ($N \rightarrow N/2 \rightarrow N/4 \rightarrow \dots$) at each decision step, yielding logarithmic time complexity.

## Key Trick

### Preventing Integer Overflow
The standard formula for finding the midpoint is:
$$\text{mid} = \frac{\text{start} + \text{end}}{2}$$

However, if `start` and `end` are very large (close to $2^{31} - 1$), adding them together can exceed the maximum limit of a 32-bit signed integer, causing **integer overflow** and resulting in undefined behavior or a negative index.

To prevent this, we calculate the midpoint as:
$$\text{mid} = \text{start} + \frac{\text{end} - \text{start}}{2}$$

This mathematically equivalent expression ensures we never sum two large integers directly.

## Approach

1. **Initialize Boundaries:** Create two pointers, `start` at index `0` and `end` at index `nums.size() - 1`. This defines our search range as the inclusive interval `[start, end]`.
2. **Loop Condition:** Run a loop as long as `start <= end`. The equality `<=` is crucial because the target could be at the very last remaining element where `start == end`.
3. **Midpoint Calculation:** Compute the `mid` index using the overflow-safe formula.
4. **Three-way Comparison:**
   * If `nums[mid] == target`, we have found the element. Return `mid`.
   * If `target > nums[mid]`, the target must lie in the right half. Shift the left boundary: `start = mid + 1`.
   * If `target < nums[mid]`, the target must lie in the left half. Shift the right boundary: `end = mid - 1`.
5. **No Match Found:** If the loop terminates without returning, the target is not in the array. Return `-1`.

*(Note on the provided code: The line `mid = start +(end-start)/2;` at the very end of the `while` loop is **redundant** and acts as dead code, because `mid` is immediately recalculated at the top of the loop in the next iteration. Removing it cleans up the code without changing its correctness).*

## Complexity

### Time: $O(\log N)$
At each step, the algorithm discards half of the array. The maximum number of steps required to reduce the search space to a single element is $\log_2(N)$.

### Space: $O(1)$
The algorithm operates in place, utilizing only a few pointer variables (`start`, `end`, `mid`), requiring constant auxiliary space.

---

## Interview Tip

In interviews, always state your boundary assumptions clearly. 
* If you use an **inclusive boundary** `[start, end]`, your loop condition must be `while (start <= end)`, and your updates must skip the midpoint: `mid + 1` and `mid - 1`.
* If you use a **half-open boundary** `[start, end)`, your loop condition must be `while (start < end)`, and your right boundary update becomes `end = mid`.
Consistency between your loop condition and boundary updates is what prevents dreaded infinite loops.

---

## Common Mistake

1. **Infinite Loops (Off-by-One errors):** 
   Using `start = mid` or `end = mid` instead of `mid + 1` or `mid - 1` can lead to infinite loops. For example, if `start = 0` and `end = 1`, `mid` will calculate to `0`. If `nums[0]` is not the target and you set `start = mid`, the loop will repeat indefinitely with `start = 0` and `end = 1`.
2. **Redundant Statements:**
   As seen in the provided code, recalculating `mid` at the end of the loop block is unnecessary and shows a minor lack of code optimization awareness to a keen interviewer.

---

## Alternative Approach

### Recursive Binary Search
While iterative search is preferred in production because it avoids call-stack overhead, you may be asked to implement the recursive version to demonstrate your understanding of recursion.

```cpp
class Solution {
private:
    int binarySearch(vector<int>& nums, int start, int end, int target) {
        if (start > end) return -1; // Base case: Target not found
        
        int mid = start + (end - start) / 2;
        
        if (nums[mid] == target) return mid;
        
        if (target > nums[mid]) {
            return binarySearch(nums, mid + 1, end, target);
        } else {
            return binarySearch(nums, start, mid - 1, target);
        }
    }
public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};
```
* **Time Complexity:** $O(\log N)$
* **Space Complexity:** $O(\log N)$ (due to the recursive call stack)
