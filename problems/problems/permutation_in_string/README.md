# 🚀 Permutation in String

🔗 **LeetCode Link:**  
https://leetcode.com/problems/permutation-in-string/

---

## 🎯 Difficulty

**Medium**

---

## 🏷️ Tags

Hash Table, Two Pointers, String, Sliding Window

---

## 📖 Problem Description

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

 
Example 1:


Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").


Example 2:


Input: s1 = "ab", s2 = "eidboaoo"
Output: false


 
Constraints:


	1 <= s1.length, s2.length <= 104
	s1 and s2 consist of lowercase English letters.



---

## 💻 My Solution

```cpp
class Solution {
public:
    bool isfreqsame(int freq1[] , int freq2[]){
        for(int i =0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};

        for(int i =0;i<s1.length();i++){
            int indx =  s1[i]-'a';
            freq[indx]++;
        } 

        int windowsize =  s1.length();

        for(int i =0; i<s2.length() ; i++){
            int windIdx = 0 , idx =i;
            int windowFreq[26]= {0};

           while(windIdx < windowsize && idx <s2.length()){
            int indx = s2[idx]-'a';
            windowFreq[indx]++;
            windIdx++;
            idx++;
           }

           if(isfreqsame(freq, windowFreq)){
            return true;
           }
        }
        
        return false;
    }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:21:23*
