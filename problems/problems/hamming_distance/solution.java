// Hamming Distance Kya Hoti Hai
// Definition:
// 👉 Do numbers ke binary representation me kitni positions different hain, 
// wahi Hamming Distance hai.
// Simple words:
// Jitne bits alag honge → utni Hamming Distance

// but hmlog thoda dusra method lga rhe hai xor wala 
// Steps yaad rakho:

// 1️⃣ XOR karo
// 2️⃣ 1s count karo

// Bas yehi Hamming Distance hai.
class Solution {
    public int hammingDistance(int x, int y) {
        
        int xor = x^y;
        int count =0;

        while(xor>0){
            if(xor%2==1){
                count++;
            }
            xor = xor/2;
        }
        return count;
    }
}
