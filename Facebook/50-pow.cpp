class Solution {
public:
    double myPow(double x, int n) {
            if( n == 0 || x == 1.0 ) return 1;
        long temp = n;
        if( temp < 0 ) {
            temp = -temp;
            x = 1/x;
        }
        double res = 1;
        while( temp > 0 ) {
            if( temp & 1 ) res *= x;
            x *= x;
            temp >>= 1;
        }
        return res;
    }
};


//recursive version

/*

        
double myPow(double x, int n) { 
    if(n==0) return 1;
    if(n<0){
        n = -n;
        x = 1/x;
    }
    return n%2==0 ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
}
*/