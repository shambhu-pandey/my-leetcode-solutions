# Remove Duplicates from Sorted Array

🔗 Link:
https://leetcode.com/problems/remove-duplicates-from-sorted-array/

## Difficulty

Easy

## Tags

Array, Two Pointers

## Problem Description

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in&nbsp;nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements&nbsp;k.

The first&nbsp;k&nbsp;elements of&nbsp;nums&nbsp;should contain the unique numbers in sorted order. The remaining elements beyond index&nbsp;k - 1&nbsp;can be ignored.

Custom Judge:

The judge will test your solution with the following code:


int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i &lt; k; i++) {
    assert nums[i] == expectedNums[i];
}


If all assertions pass, then your solution will be accepted.

&nbsp;
Example 1:


Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).


Example 2:


Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).


&nbsp;
Constraints:


	1 &lt;= nums.length &lt;= 3 * 104
	-100 &lt;= nums[i] &lt;= 100
	nums is sorted in non-decreasing order.



## Solution

See `solution.cpp`

## Intuition

Since the input array is already sorted, all duplicate elements are guaranteed to be grouped next to each other. This means we don't need to search the entire array to find duplicates; we only need to compare each element with its immediate neighbor. 

If an element is different from its predecessor, it is a unique element and must be kept. We can overwrite the duplicates in-place by maintaining a pointer to track where the next unique element should be placed.

---

## Pattern

**Two-Pointer (Reader/Writer representation):** 
* **Reader (`i`)**: Scans through the array to find new unique elements.
* **Writer (`k`)**: Keeps track of the index where the next unique element should be written.

---

## Key Trick

Instead of comparing the current element to the last placed unique element at `nums[k-1]`, this code compares the current element `nums[i]` to its predecessor `nums[i-1]`. 

Because the array is sorted, a change in value between adjacent elements (`nums[i] != nums[i-1]`) signals the discovery of a brand-new unique value.

---

## Approach

1. **Initialization**: 
   * Since an array of size 1 or more always has at least one unique element, we can skip the first element (`nums[0]`).
   * Initialize our writer pointer `k = 1` and our reader pointer `i = 1`.
2. **Scan**: 
   * Loop `i` from `1` to `n - 1`.
   * If `nums[i] != nums[i-1]`, it means `nums[i]` is a new unique element.
3. **Write**: 
   * Copy the unique element to the writer's position: `nums[k] = nums[i]`.
   * Increment `k` to prepare for the next unique element.
4. **Return**: 
   * Return `k`, which represents both the count of unique elements and the boundary of the modified prefix.

---

## Complexity

### Time: $O(N)$
We traverse the array of size $N$ exactly once. Each element is read and processed in $O(1)$ constant time.

### Space: $O(1)$
No extra memory is allocated. All modifications are made directly to the input array in-place.

---

## Interview Tip

In interviews, **always clarify constraints first**:
1. *Can the array be empty?* 
   * If yes, the code above would fail (returning `1` for an empty array). You would need a guard clause: `if (nums.empty()) return 0;`.
2. *Are we allowed to modify the input array?* 
   * This problem explicitly requires in-place modification. Underlining the $O(1)$ space restriction shows you understand memory efficiency.

---

## Common Mistake

* **Off-by-One / Out-of-Bounds Errors**: Beginning the loop at `i = 0` and comparing `nums[i]` with `nums[i-1]` leads to an out-of-bounds memory access (`nums[-1]`).
* **Using Extra Space**: Resorting to a hash set or a temporary array to filter duplicates. While correct for removing duplicates, it violates the $O(1)$ space requirement.

---

## Alternative Approach

### 1. The C++ Standard Library Way (Idiomatic C++)
In a real-world C++ production environment, you should leverage the STL algorithm `std::unique`, which does exactly this.

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // std::unique moves duplicates to the end and returns an iterator to the new end
        auto it = std::unique(nums.begin(), nums.end());
        return std::distance(nums.begin(), it);
    }
};
```

### 2. Generalizable Two-Pointer (Comparing with `nums[k-1]`)
Instead of comparing `nums[i]` with `nums[i-1]`, we can compare it with `nums[k-1]` (the last placed unique element). This pattern is incredibly useful because it easily scales if the problem changes to "allow at most $D$ duplicates" (e.g., LeetCode 80: *Remove Duplicates from Sorted Array II*).

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for (int x : nums) {
            // For allowing at most 'D' duplicates, change '0' to 'D-1'
            if (k < 1 || x > nums[k-1]) { 
                nums[k++] = x;
            }
        }
        return k;
    }
};
```
