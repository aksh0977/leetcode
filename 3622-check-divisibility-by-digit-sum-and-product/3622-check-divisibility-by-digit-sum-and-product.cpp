class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;
        int og = n;
        while(n!=0){
            int dig = n%10;
            sum += dig;
            prod *= dig;
            n = n/10;
        }
        int op  = prod+sum;
        return og%op ?  false :  true;
    }
};