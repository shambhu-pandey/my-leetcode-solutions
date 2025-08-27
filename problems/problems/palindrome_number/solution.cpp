class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0) return false; //  negative num is not a palindrome
        long original = x;
        long  reverseNum = 0;
        while(x>0){
            long lastdigit = x%10 ;
            reverseNum = reverseNum*10+lastdigit;
            x = x/10;
        }

      return reverseNum == original;
    }
};