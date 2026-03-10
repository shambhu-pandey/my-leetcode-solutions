class Solution {
   
   public static boolean isPrime(int n){

       if(n<2) return false;

       for(long i = 2; i*i <=n; i++){
           if(n% i ==0){
            return false;
           }
       }
       return true;
   }

    public int nonSpecialCount(int l, int r) {
        
        int specialCount = 0;
       
       for(int i = 2; i*i <= r ; i++){
            if(isPrime(i)){
                long square = i*i;
               if(square >= l && square <=r){
                    specialCount++;
               }
            }
        }

        int total = r-l+1;
        int nonSpecial = total- specialCount;

        return nonSpecial;
    }
}