//The key observation is that the quotient of a division is just the number of times
// that we can subtract the divisor from the dividend without making it negative.
//Runtime: worest case require 

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        while (dvd >= dvs) {
            long temp = dvs, m = 1;
            while (dvd >= (temp << 1)) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }
};