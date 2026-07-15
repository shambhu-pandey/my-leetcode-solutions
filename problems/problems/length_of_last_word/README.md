# 🚀 Length of Last Word

🔗 **LeetCode Link:**  
https://leetcode.com/problems/length-of-last-word/

---

## 🎯 Difficulty

**Easy**

---

## 🏷️ Tags

String

---

## 📖 Problem Description

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.

 
Example 1:


Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.


Example 2:


Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.


Example 3:


Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.


 
Constraints:


	1 <= s.length <= 104
	s consists of only English letters and spaces ' '.
	There will be at least one word in s.



---

## 💻 My Solution

```cpp
// Start from the end of the string
// Skip any trailing spaces
// Count characters until the next space or start of string
// Return the count
class Solution {
public:
    int lengthOfLastWord(string s) {
       int length = 0;
       int i = s.size() -1;


       while(i>=0 && s[i]==' '){
        i--;
       }
       while(i>=0 && s[i]!=' '){
        length++;
        i--;
       }

       return length;
    }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:22:10*
