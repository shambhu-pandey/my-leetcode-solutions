class Solution {

 void    solve(vector<int> nums , int index,vector<int> output, vector<vector<int>> &ans){
        //base case
        if(index>=nums.size()){
            ans.push_back(output); //last tak pahuch gye hai means ab store kra lenge ans waale array me 
            return;
        }

        //exclude
        solve(nums ,index+1,output ,ans); // index ko aage badha rhe hai

        //include
        int element = nums[index];
        output.push_back(element);
        solve(nums,index+1 , output , ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;
        vector<int> output;
        int index =0;
        solve(nums , index , output , ans);
        return ans;
    }
};