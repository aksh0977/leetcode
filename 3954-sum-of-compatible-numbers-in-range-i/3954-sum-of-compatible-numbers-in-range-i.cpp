class Solution {
public:
    int sumOfGoodIntegers(int n, int k) {
        int sum = 0;
        int start = 0;
        if(n-k>=0){
            start = n-k;
        }
        for(int i = start; i<=n+k; i++){
            if((n&i)==0){
                sum+=i;
            }
        }
        return sum;
    }
};