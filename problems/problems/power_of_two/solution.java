// Count set bits.
// If set bits = 1 → power of two

class Solution {
    public boolean isPowerOfTwo(int n) {
        
        if(n<=0) return false;
        
        while(n%2==0){
            n=n/2;
        }
        if(n==1){
            return true;
        }
        else{
            return false;
        }


                
        // int count =0;
        // while(n>0){
        //     if(n%2==1){
        //         count++;
        //     }
        //     n= n/2;
        // }
        // if(count ==1){
        //     return true;
        // }
        // else{
        //     return false;
        // }

    }
}