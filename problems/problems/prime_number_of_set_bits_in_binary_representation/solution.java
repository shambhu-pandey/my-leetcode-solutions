// 1️⃣ Convert number to binary
// 2️⃣ Count set bits (number of 1s)
// 3️⃣ Check if that count is prime
// If prime → increase count.
class Solution {
   
   public static int countBits(int n){
    int count=0;
         while(n>0){
            if(n%2 ==1){
                count++;
            }
            n = n/2;
         }
         return count;
   }

   public static boolean isPrime(int n){
    if(n<2) return false;

    for(int i = 2; i*i<=n ; i++){
        if(n%i==0){
            return false;
        }
    }

    return true;
   }

    public int countPrimeSetBits(int left, int right) {
        
        int result = 0;

        for(int i = left; i<= right; i++){
            int bits = countBits(i);

            if(isPrime(bits)){
                result++;
            }
        }

        return result;
    }
}