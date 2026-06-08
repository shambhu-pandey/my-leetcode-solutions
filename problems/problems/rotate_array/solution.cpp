class Solution {
public:

    void reverse(vector<int>&nums , int start ,int end){
        while(start<end){
            swap(nums[start] , nums[end]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        reverse(nums, 0, n-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
    }
};


// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int n = nums.size();

//         k= k%n;

//         vector<int>rotate;

//         for(int i = n-k;i<n;i++){
//             rotate.push_back(nums[i]);
//         }
//         for(int i = 0;i<n-k;i++){
//             rotate.push_back(nums[i]);
//         

//         for(int i =0;i<n;i++){
//             nums[i] = rotate[i];
//         }
//     }
// };