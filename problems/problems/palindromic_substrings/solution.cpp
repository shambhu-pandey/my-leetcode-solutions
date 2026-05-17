// class Solution {
// public:
//     int countSubstrings(string s) {
//         int n = s.size();
//         int count=0;

//         for(int i =0; i<n;i++){
//             for(int j =i;j<n; j++){
//                 if(isPalindrome(s, i , j)){
//                     count++;   
//                 }
//             }
//         }
//         return count;
//     }

// private:
//      bool isPalindrome(string s , int left , int right){
//         while(left<right){
//             if(s[left] !=s[right]){
//                 return false;
//             }
//             left++;
//             right--;
//         }
//         return true;
//      }
// };



class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for(int i =0; i<n; i++){
            count += expand(s, i , i) ; // odd palindrome
            count += expand(s, i,i+1) ;  // even palindrome
        }

        return count;
    }

private:
      int  expand(string &s , int left , int right){
        int count=0;
        while(left >=0 && right < s.size() && s[left] == s[right]){
            count++;
            left--;
            right++;
        }
        return count;
      }
};