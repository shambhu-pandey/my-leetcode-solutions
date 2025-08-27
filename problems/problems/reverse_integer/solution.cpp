class Solution {
public:
    int reverse(int x) {
        long long reverseNum = 0;  // use bigger type
        while (x != 0) {
            int lastDigit = x % 10;
            reverseNum = reverseNum * 10 + lastDigit;
            x /= 10;
        }
        // check if result is in 32-bit range
       if(reverseNum < INT_MIN || reverseNum >INT_MAX) return 0;
       return int(reverseNum);
    }
};
