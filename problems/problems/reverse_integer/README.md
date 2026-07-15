# Reverse Integer

🔗 Link:
https://leetcode.com/problems/reverse-integer/

## Difficulty

Medium

## Tags

Math

## Problem Description

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

&nbsp;
Example 1:


Input: x = 123
Output: 321


Example 2:


Input: x = -123
Output: -321


Example 3:


Input: x = 120
Output: 21


&nbsp;
Constraints:


	-231 &lt;= x &lt;= 231 - 1



## Solution

See `solution.cpp`

## Intuition

The core task is to reverse the digits of a 32-bit signed integer. To reverse a number, we can repeatedly pop the last digit from the input number and push it to the back of a new reversed number. 

The primary challenge of this problem is not the reversal itself, but **handling potential overflow**. Since we are restricted to a 32-bit signed integer environment, we cannot simply use a 64-bit integer (like `long long` in C++) to store the reversed number and check if it exceeds the boundaries at the end. We must predict and prevent overflow *before* it actually occurs.

---

## Pattern

This problem falls under the **Digit Manipulation** and **Pre-emptive Overflow Checking** patterns. 
* **Digit Manipulation:** Using `% 10` to extract the last digit and `/ 10` to remove the last digit.
* **Pre-emptive Checking:** Validating that an arithmetic operation is safe *before* executing it to avoid undefined behavior or hardware overflows.

---

## Key Trick

The key trick is to inspect the state of the reversed number `rev` **before** performing the operation `rev = rev * 10 + digit`. 

A 32-bit signed integer ranges from $[-2^{31}, 2^{31} - 1]$, which is $[-2147483648, 2147483647]$.
* `INT_MAX` is $2147483647$
* `INT_MIN` is $-2147483648$

To prevent `rev * 10 + digit` from overflowing:
1. **For Positive Overflow:** 
   * If `rev > INT_MAX / 10`, multiplying by 10 will definitely overflow.
   * If `rev == INT_MAX / 10`, we can only add a digit if `digit <= 7` (since the last digit of `INT_MAX` is `7`).
2. **For Negative Underflow:** 
   * If `rev < INT_MIN / 10`, multiplying by 10 will definitely underflow.
   * If `rev == INT_MIN / 10`, we can only add a digit if `digit >= -8` (since the last digit of `INT_MIN` is `-8`).

---

## Approach

1. Initialize `rev` to `0` and a copy of the input `temp` to `x`.
2. Loop until `temp` becomes `0`:
   * Extract the last digit of `temp` using `temp % 10`.
   * Check for overflow/underflow using the conditions described in the **Key Trick**. If an overflow is imminent, immediately return `0`.
   * Update the reversed number: `rev = (rev * 10) + digit`.
   * Shrink `temp` by dividing it by `10`.
3. Return `rev`.

---

## Complexity

### Time: $\mathcal{O}(\log_{10}(x))$
The number of iterations is proportional to the number of digits in $x$. Since $x \le 2^{31} - 1$, it has at most 10 digits. Thus, the loop runs at most 10 times, making the time complexity practically $\mathcal{O}(1)$.

### Space: $\mathcal{O}(1)$
We only use a few auxiliary variables (`temp`, `rev`, and `digit`) to perform the calculation, requiring constant extra memory.

---

## Interview Tip

In an interview, **always clarify the constraints first**. Ask the interviewer: *"Am I allowed to use a 64-bit integer type like `long` or `long long` to handle overflow?"*
* If they say **yes**, use the simpler alternative approach (shown below).
* If they say **no**, this pre-emptive checking solution is exactly what they are testing you on.

---

## Common Mistake

A very common mistake in C/C++ is executing the statement `rev = rev * 10 + digit` and then checking if `rev > INT_MAX` or `rev < INT_MIN`. 

In C++, **signed integer overflow is Undefined Behavior (UB)**. The compiler is allowed to optimize away any checks that occur *after* an undefined operation has been triggered because it assumes overflow never happens. You must check *before* you overflow.

---

## Alternative Approach

If the environment **does** allow 64-bit integers, the code becomes drastically simpler because we don't need complex mathematical checks inside the loop. We can do the math in 64-bit space and check at the end:

```cpp
class Solution {
public:
    int reverse(int x) {
        long long rev = 0; // Use a 64-bit integer
        while (x != 0) {
            rev = (rev * 10) + (x % 10);
            x /= 10;
        }
        // Check if the 64-bit result fits in 32-bit limits
        if (rev > INT_MAX || rev < INT_MIN) {
            return 0;
        }
        return (int)rev;
    }
};
```
