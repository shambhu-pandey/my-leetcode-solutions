# Calculate Digit Sum of a String

🔗 Link:
https://leetcode.com/problems/calculate-digit-sum-of-a-string/

## Difficulty

Easy

## Tags

String, Simulation

## Problem Description

You are given a string s consisting of digits and an integer k.

A round can be completed if the length of s is greater than k. In one round, do the following:


	Divide s into consecutive groups of size k such that the first k characters are in the first group, the next k characters are in the second group, and so on. Note that the size of the last group can be smaller than k.
	Replace each group of s with a string representing the sum of all its digits. For example, &quot;346&quot; is replaced with &quot;13&quot; because 3 + 4 + 6 = 13.
	Merge consecutive groups together to form a new string. If the length of the string is greater than k, repeat from step 1.


Return s after all rounds have been completed.

&nbsp;
Example 1:


Input: s = &quot;11111222223&quot;, k = 3
Output: &quot;135&quot;
Explanation: 
- For the first round, we divide s into groups of size 3: &quot;111&quot;, &quot;112&quot;, &quot;222&quot;, and &quot;23&quot;.
  ​​​​​Then we calculate the digit sum of each group: 1 + 1 + 1 = 3, 1 + 1 + 2 = 4, 2 + 2 + 2 = 6, and 2 + 3 = 5. 
&nbsp; So, s becomes &quot;3&quot; + &quot;4&quot; + &quot;6&quot; + &quot;5&quot; = &quot;3465&quot; after the first round.
- For the second round, we divide s into &quot;346&quot; and &quot;5&quot;.
&nbsp; Then we calculate the digit sum of each group: 3 + 4 + 6 = 13, 5 = 5. 
&nbsp; So, s becomes &quot;13&quot; + &quot;5&quot; = &quot;135&quot; after second round. 
Now, s.length &lt;= k, so we return &quot;135&quot; as the answer.


Example 2:


Input: s = &quot;00000000&quot;, k = 3
Output: &quot;000&quot;
Explanation: 
We divide s into &quot;000&quot;, &quot;000&quot;, and &quot;00&quot;.
Then we calculate the digit sum of each group: 0 + 0 + 0 = 0, 0 + 0 + 0 = 0, and 0 + 0 = 0. 
s becomes &quot;0&quot; + &quot;0&quot; + &quot;0&quot; = &quot;000&quot;, whose length is equal to k, so we return &quot;000&quot;.


&nbsp;
Constraints:


	1 &lt;= s.length &lt;= 100
	2 &lt;= k &lt;= 100
	s consists of digits only.



## Solution

See `solution.cpp`

## Intuition

The problem asks us to repeatedly compress a string of digits until its length is less than or equal to $k$. The compression rule is simple: split the string into consecutive groups of size $k$, calculate the sum of the digits in each group, convert these sums back to strings, and merge them. 

Since this process relies on step-by-step execution of a set of rules, this is a classic **simulation problem**. The string size shrinks rapidly in each iteration, which guarantees that the process will terminate quickly.

---

## Pattern

This problem falls under the **Simulation and String Chunking** pattern. 
* **Simulation:** Emulating the exact steps described in the problem statement.
* **Two-Pointer/Chunking Loop:** Iterating through a linear data structure in chunks of a fixed size $k$ rather than element-by-element (`i += k`).

---

## Key Trick

1. **ASCII to Integer Conversion:** To get the integer value of a character digit, subtract `'0'` from it:
   $$\text{digit} = s[j] - '0'$$
2. **Boundary Safeguard:** When splitting the string into blocks of size $k$, the last block might have fewer than $k$ characters. The inner loop condition `j < i + k && j < s.size()` elegantly handles this edge case without causing an out-of-bounds error.

---

## Approach

1. **Loop Condition:** We run a `while` loop that continues as long as the length of $s$ is greater than $k$.
2. **Chunk Processing:** Inside the loop, we initialize an empty string `temp` to store the newly formed string for the current round.
3. **Iterating in Strides of $k$:** We iterate through $s$ using a pointer $i$ that increments by $k$ in each step (`i += k`).
4. **Summing Digits:** For each chunk starting at $i$, an inner loop sums up to $k$ characters starting from $j = i$ to $j < i + k$, ensuring $j$ never exceeds the bounds of string $s$.
5. **Reconstruction:** We convert the calculated sum to a string using `to_string(sum)` and append it to `temp`.
6. **State Update:** Once the outer loop finishes processing the entire string $s$, we update $s = temp$ and repeat the process.

---

## Complexity

### Time: $O(N)$
In each round, we traverse the current string of length $L$ to compute the digit sums. 
* In the first round, we do $O(N)$ work.
* In each subsequent round, the length of the string reduces significantly. Specifically, a group of $k$ characters is replaced by the string representation of their sum (which has a length of at most $\log_{10}(9k)$). Since $k \ge 2$, the length of the string shrinks geometrically.
* The sum of a geometric series dominated by the first term $N$ is $O(N)$.

### Space: $O(N)$
We need auxiliary space for the `temp` string to store the intermediate merged results. In the worst case (the first iteration), `temp` will take up to $O(N)$ space.

---

## Interview Tip

* **Clarify Constraints first:** In interviews, always look at the constraints. Here, the maximum length of $s$ is $100$. This small constraint tells you that a straightforward simulation is highly optimal and there is no need for over-engineering with complex data structures.
* **Explain the $s[i] - '0'$ idiom:** Interviewers love when you explain *why* something works. Briefly mention that in C++, characters are represented by ASCII values sequentially (e.g., `'0'` is 48, `'1'` is 49), so subtracting `'0'` yields the exact integer value.

---

## Common Mistake

* **Out of Bounds in the Last Chunk:** A frequent bug is running the inner loop exactly $k$ times (`j < i + k`) without checking if `j` has crossed the string boundary (`j < s.size()`). This leads to a Segmentation Fault or undefined behavior.
* **Integer Overflow via Direct Conversion:** Trying to convert the entire string $s$ into an integer first (e.g., using `std::stoi`) will result in an overflow because $s$ can be up to 100 digits long, which exceeds standard 64-bit integer limits (`long long`). Always process it as a string.

---

## Alternative Approach

Instead of an iterative `while` loop, this problem can be elegantly solved using **Recursion**. Since the problem asks us to repeat the same operation on a progressively smaller string until a base condition is met ($s.\text{size}() \le k$), it naturally maps to a recursive structure.

### Recursive Implementation (C++):
```cpp
class Solution {
public:
    string digitSum(string s, int k) {
        // Base Case
        if (s.size() <= k) return s;
        
        string next_s = "";
        for (int i = 0; i < s.size(); i += k) {
            int sum = 0;
            for (int j = i; j < i + k && j < s.size(); ++j) {
                sum += (s[j] - '0');
            }
            next_s += to_string(sum);
        }
        
        // Recursive Step
        return digitSum(next_s, k);
    }
};
```
* **Pros:** Highly readable and mathematically intuitive.
* **Cons:** Uses $O(\log N)$ implicit call stack space, though practically negligible for $N = 100$.
