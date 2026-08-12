class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int temp  = x;
        long long r = 0;
        while(temp!=0){
            r = r*10 + temp%10;
            temp = temp/10;
        }

        if(r<INT_MIN || r>INT_MAX){
            return false;
        }
        return (int)r==x;
    }
};