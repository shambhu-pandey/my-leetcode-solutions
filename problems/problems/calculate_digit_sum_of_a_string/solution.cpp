class Solution {
public:
    string digitSum(string s, int k) {
        
        // jab tak string ki length k se badi hai
        while(s.size() > k) {
            
            string temp = "";
            
            // groups of size k bana rahe hain
            for(int i = 0; i < s.size(); i += k) {
                
                int sum = 0;
                
                // current group ka digit sum nikalna
                for(int j = i; j < i + k && j < s.size(); j++) {
                    sum += (s[j] - '0');
                }
                
                // sum ko string me convert karke temp me add kar do
                temp += to_string(sum);
            }
            
            // new string update
            s = temp;
        }
        
        return s;
    }
};