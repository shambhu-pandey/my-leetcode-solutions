# 🚀 Count Primes

🔗 **LeetCode Link:**  
https://leetcode.com/problems/count-primes/

---

## 🎯 Difficulty

**Medium**

---

## 🏷️ Tags

Array, Math, Enumeration, Number Theory

---

## 📖 Problem Description

Given an integer n, return the number of prime numbers that are strictly less than n.

 
Example 1:


Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.


Example 2:


Input: n = 0
Output: 0


Example 3:


Input: n = 1
Output: 0


 
Constraints:


	0 <= n <= 5 * 106



---

## 💻 My Solution

```cpp
class Solution {
public:
    int countPrimes(int n) {

        vector<bool> isprime(n);
        for(int i = 0;  i< n; i++){
            isprime[i] = true;
        }

        for(int i = 2; i*i<n ; i++){
            if(isprime[i]==true){
                for(int j = i*i ; j<n; j+=i){
                    isprime[j]= false;
                }
            }
        }
        int count =0;
        for(int i = 2; i<n; i++){
            if(isprime[i]==true){
                count++;
            }
        }

        return count;
    }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:22:31*
