class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       
    //    set<int> s(nums.begin() , nums.end());

    //    int i =0;
    //    for(int x: s){
    //       nums[i] = x;
    //       i++;
    //    }

    //    return s.size();


     int count = 1;
     int n = nums.size();

     for(int j = 1; j<n; j++){
         if(nums[j] != nums[count-1]){
            count++;
            nums[count-1] = nums[j];
         }
     }
     return count;
    }
};