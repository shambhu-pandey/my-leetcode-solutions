# 🚀 Palindromic Substrings

🔗 **LeetCode Link:**  
https://leetcode.com/problems/palindromic-substrings/

---

## 🎯 Difficulty

**Medium**

---

## 🏷️ Tags

Two Pointers, String, Dynamic Programming

---

## 📖 Problem Description

Given a string s, return the number of palindromic substrings in it.

A string is a palindrome when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

 
Example 1:


Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".


Example 2:


Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


 
Constraints:


	1 <= s.length <= 1000
	s consists of lowercase English letters.



---

## 💻 My Solution

```cpp
// class Solution {
// public:
//     int countSubstrings(string s) {
//         int n = s.size();
//         int count=0;

//         for(int i =0; i<n;i++){
//             for(int j =i;j<n; j++){
//                 if(isPalindrome(s, i , j)){
//                     count++;   
//                 }
//             }
//         }
//         return count;
//     }

// private:
//      bool isPalindrome(string s , int left , int right){
//         while(left<right){
//             if(s[left] !=s[right]){
//                 return false;
//             }
//             left++;
//             right--;
//         }
//         return true;
//      }
// };



class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for(int i =0; i<n; i++){
            count += expand(s, i , i) ; // odd palindrome
            count += expand(s, i,i+1) ;  // even palindrome
        }

        return count;
    }

private:
      int  expand(string &s , int left , int right){
        int count=0;
        while(left >=0 && right < s.size() && s[left] == s[right]){
            count++;
            left--;
            right++;
        }
        return count;
      }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:21:26*
