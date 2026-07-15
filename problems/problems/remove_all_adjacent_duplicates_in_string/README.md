# 🚀 Remove All Adjacent Duplicates In String

🔗 **LeetCode Link:**  
https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

---

## 🎯 Difficulty

**Easy**

---

## 🏷️ Tags

String, Stack

---

## 📖 Problem Description

You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

 
Example 1:


Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".


Example 2:


Input: s = "azxxzy"
Output: "ay"


 
Constraints:


	1 <= s.length <= 105
	s consists of lowercase English letters.



---

## 💻 My Solution

```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        string st ="";

        for(char ch : s){

            if(!st.empty() && st.back()==ch){
                st.pop_back();
            }
            else{
                st.push_back(ch);
            }
        } 

        return st;
    }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:22:27*
