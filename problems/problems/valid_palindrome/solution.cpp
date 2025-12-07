class Solution {
public:
    bool isPalindrome(string s) {
        string cleaned = "";

        // for(char c : s){
        //     if(isalnum(c)){
        //       cleaned += tolower(c);
        //     }
        // }


        for(char ch: s){
            if(isalnum(ch)){
                if(ch>='a' && ch<='z'){
                    cleaned +=ch;
                }
                else if(ch>='A' && ch<='Z'){
                    char temp = ch-'A'+'a';
                    cleaned += temp;
                }
                else{
                    cleaned +=ch;
                }

            }
        }

        string reversed ="";

        for(int i = cleaned.length()-1;i>=0;i--){
            reversed += cleaned[i];
        } 

        return reversed == cleaned;
    }
};
