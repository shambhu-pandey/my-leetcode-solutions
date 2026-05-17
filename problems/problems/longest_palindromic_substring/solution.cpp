class Solution {
public:
    string longestPalindrome(string s) {
      
        int n = s.size();
        string result= "";

        for(int i =0; i<n; i++){
            for(int j =i; j<n; j++){
                 if(isPalindrome(s, i , j)){
                    if(j-i+1 > result.size()){
                       result = s.substr(i , j-i+1);
                    }
                 }
            }
        }

        return result;
    }

  private:
         bool isPalindrome(string &s , int left , int right){
            while(left<right){
                if(s[left]!=s[right]){
                    return false;
                }
                left++;
                right--;
            }
            return true;
         } 
};



//order of n time complexity optimal code 

// class Solution {
// public:

//     string longestPalindrome(string s) {

//         int n = s.size();

//         int start = 0;
//         int end = 0;

//         for (int i = 0; i < n; i++) {

//             int odd = expand(s, i, i);

//             int even = expand(s, i, i + 1);

//             int len = max(odd, even);

//             if (len > (end - start)) {

//                 start = i - (len - 1) / 2;

//                 end = i + len / 2;
//             }
//         }

//         return s.substr(start, end - start + 1);
//     }

// private:

//     int expand(string &s, int left, int right) {

//         while (left >= 0 && right < s.size() &&
//                s[left] == s[right]) {

//             left--;
//             right++;
//         }

//         return right - left - 1;
//     }
// };