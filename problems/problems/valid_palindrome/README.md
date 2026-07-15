# 🚀 Valid Palindrome

🔗 **LeetCode Link:**  
https://leetcode.com/problems/valid-palindrome/

---

## 🎯 Difficulty

**Easy**

---

## 🏷️ Tags

Two Pointers, String

---

## 📖 Problem Description

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

 
Example 1:


Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.


Example 2:


Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.


Example 3:


Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.


 
Constraints:


	1 <= s.length <= 2 * 105
	s consists only of printable ASCII characters.



---

## 💻 My Solution

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;

        while(left<right){

            if(!isalnum(s[left])){
                left++;
            }
            else if(!isalnum(s[right])){
                right--;
            }
            else{
                if(tolower(s[left]) != tolower(s[right])){
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:22:26*
