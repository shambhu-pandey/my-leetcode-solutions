class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp;
        int n = nums.size();
         k = k%n;


         // store last k elements
        for(int i = n-k;i<n;i++){
              temp.push_back(nums[i]);
        }

           // shift remaining elements to the right
        for(int i = n-1 ; i>=k; i--){
            nums[i]=nums[i-k]; 
        }
           
        // place temp elements at start
        for(int i = 0 ; i<k; i++){
            nums[i]=temp[i]; 
        }
    }
};