class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0 || (x%10==0 && x!=0)){
            return false;
        }
        long long reversedNum =0;
        int original = x;

        while(x>0){
            int lastDigit= x%10;   // last digit nikaal liye 
            reversedNum = (reversedNum*10)+ lastDigit;
            x /=10;
        }
        return reversedNum == original;
    }
};