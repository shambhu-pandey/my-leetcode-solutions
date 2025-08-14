

class Solution {

    int gcd(int a, int b) {
        if (b > a)
            return gcd(b, a);
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }

    int findGCD(int[] nums) {
        Arrays.sort(nums);
        int min = nums[0];
        int max = nums[nums.length - 1];
        return gcd(max, min);
    }
}