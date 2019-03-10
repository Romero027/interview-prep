/*
we want to find sum[i, j]
we can easily compute this from sum[0, j] and sum[0, i - 1]
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, result = 0;
        unordered_map<int, int> preSum;//key is the preSum and value is the frequency
        preSum[0] = 1;
        for( int i = 0; i < nums.size(); i++ ) {
            sum += nums[i];
            if(preSum.find(sum - k) != preSum.end()) result += preSum[sum - k];
            // it means there is some sum value v between 0 and x, which makes sum of array [x + 1 to i] == k
            // the frequency is the number of x
            preSum[sum]++;
        }
        return result;
    }
};

