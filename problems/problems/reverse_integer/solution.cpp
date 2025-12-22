class Solution {
public:
    int reverse(int x) {
       int temp = x ;
       int rev =0;
       while(temp !=0){
        int digit   = (temp) % 10;
        if(rev > INT_MAX/10 || (rev == INT_MAX/10 && digit >7 )) return 0;
        if(rev < INT_MIN/10 || (rev ==INT_MIN/10 && digit < -8)) return 0;
        rev = (rev*10) + digit;
        temp = temp/10;
       }

       return rev ;
    }
};