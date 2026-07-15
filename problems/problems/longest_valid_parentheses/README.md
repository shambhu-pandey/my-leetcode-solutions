# 🚀 Longest Valid Parentheses

🔗 **LeetCode Link:**  
https://leetcode.com/problems/longest-valid-parentheses/

---

## 🎯 Difficulty

**Hard**

---

## 🏷️ Tags

String, Dynamic Programming, Stack

---

## 📖 Problem Description

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

 
Example 1:


Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".


Example 2:


Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".


Example 3:


Input: s = ""
Output: 0


 
Constraints:


	0 <= s.length <= 3 * 104
	s[i] is '(', or ')'.



---

## 💻 My Solution

```java
class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> st = new Stack<>();
        st.push(-1);
        int maxLen = 0;

        for(int i =0; i<s.length();i++){
            if(s.charAt(i)=='('){
                st.push(i);
            }
            else{
                st.pop();

                if(st.isEmpty()){
                    st.push(i);
                }
                else{
                    maxLen = Math.max(maxLen , i-st.peek());
                }
            }
        }
        return maxLen;
    }
}
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:22:22*
