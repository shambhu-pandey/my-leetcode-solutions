class Solution {
    private:
    void solve(string digits, int index ,string output ,vector<string>&ans , string mapping[]){
        if(index>=digits.length()){
           ans.push_back(output);
           return;
        }
    
        //include
        int number = digits[index]-'0';  // character dega toh usko int me convert karne ke liye minus 0 string kar denge toh jo bhi charcter me string diya rhega usko integer me convert kar deta hau 
        string values = mapping[number];  // jo bhi values aya uske corresponding values ko mapping kra de rhe hai 

        for(int i =0; i<values.length(); i++){  // loop chala diye pure mapping tak like agar 2 hai toh a, b, c tak 
            output.push_back(values[i]); // phir a ko le liye 
            solve(digits , index+1 , output , ans , mapping); // a ke saath waale ke liye jaise 3 hai toh def means ad , ae , phir af ,

            //backtrack
            output.pop_back();   // ab a waale ko hta de rhe taaki agla baar b ke saath corresponding element map kre like bd , be , bf
        }
       
        
        
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string output ="";
        int index =0;
        string mapping[10] = {"","", "abc", "def" , "ghi", "jkl","mno","pqrs","tuv", "wxyz"};
        solve(digits , index, output , ans ,mapping);
        return ans;
    }
};