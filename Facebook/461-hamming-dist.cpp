class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0, temp = x ^ y;
        while(temp){
            count++;
            temp &= temp - 1;
        }
        return count;
    }
};