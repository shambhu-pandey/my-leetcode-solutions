import java.util.Scanner;

class Solution {

    public void rotate(int[] nums , int k){
        k = k % nums.length;
        reverse(nums, 0, nums.length-1);
        reverse(nums , 0 , k-1);
        reverse(nums , k , nums.length-1);
    }

    public void reverse(int[] nums , int start , int end){
        while(start < end){
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        // Taking array size
        System.out.print("Enter size of array: ");
        int n = sc.nextInt();

        int[] nums = new int[n];
        System.out.println("Enter elements of array: ");
        for(int i = 0; i < n; i++){
            nums[i] = sc.nextInt();
        }

        // Taking k value
        System.out.print("Enter rotation steps (k): ");
        int k = sc.nextInt();

        // Call rotate method
        Solution obj = new Solution();
        obj.rotate(nums, k);

        // Print rotated array
        System.out.println("Rotated array: ");
        for(int num : nums){
            System.out.print(num + " ");
        }
    }
}
