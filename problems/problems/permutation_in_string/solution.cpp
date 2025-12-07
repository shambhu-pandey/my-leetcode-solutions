class Solution {
public:
    bool isfreqsame(int freq1[] , int freq2[]){
        for(int i =0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};

        for(int i =0;i<s1.length();i++){
            int indx =  s1[i]-'a';
            freq[indx]++;
        } 

        int windowsize =  s1.length();

        for(int i =0; i<s2.length() ; i++){
            int windIdx = 0 , idx =i;
            int windowFreq[26]= {0};

           while(windIdx < windowsize && idx <s2.length()){
            int indx = s2[idx]-'a';
            windowFreq[indx]++;
            windIdx++;
            idx++;
           }

           if(isfreqsame(freq, windowFreq)){
            return true;
           }
        }
        
        return false;
    }
};