class Solution {
public:
    bool validPalindrome(string s) {
        int left =0;
        int right = s.size()-1;

       
        while(left<right){
            if(s[left] != s[right]){
                // yha par fun ko string left aur right pointer bhej rhe hai pahle      left pointer ko ek delete kar ke dekh rhe hai phir ki palindrome bn ja rha hai ki nhi aur phir ek baar right pointer ko ek delete kar ke dekh rhe hai ki palindrome bn ja rha hai ki nhi   
                return isPalindrome(s , left+1 , right) ||
                        isPalindrome(s,left, right-1);
            }
            left++;
            right--;
        }
         return true;
    }
 
 // simple palindrome check karne ka logic 
    private:
     bool isPalindrome(string &s , int left , int right){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};