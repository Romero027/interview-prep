/*
For each bit position 1-32 in a 32-bit integer, we count the number of 
integers in the array which have that bit set. Then, if there are n integers 
in the array and k of them have a particular bit set and (n-k) do not, then that 
bit contributes k*(n-k) hamming distance to the total.
Runtime time: N
*/


class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int len = nums.size();
        int totalCount = 0;
        for(int i = 0; i < 32; ++i) {
            long bitCount = 0;
            for(int j = 0; j < len; ++j) {
                bitCount += (nums[j] >> i) & 1;
            }
            totalCount += bitCount * ( len - bitCount);
        }
        return totalCount;
    }
};