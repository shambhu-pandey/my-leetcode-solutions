// Start from the end of the string
// Skip any trailing spaces
// Count characters until the next space or start of string
// Return the count
class Solution {
public:
    int lengthOfLastWord(string s) {
       int length = 0;
       int i = s.size() -1;


       while(i>=0 && s[i]==' '){
        i--;
       }
       while(i>=0 && s[i]!=' '){
        length++;
        i--;
       }

       return length;
    }
};