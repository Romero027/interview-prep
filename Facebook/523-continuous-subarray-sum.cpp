/*
Same as continuous subarray sum,
key observation: we can get sum[i, j] from sum[0, i - 1] and sum[0, j] 
sum[i, j] % k = sum[0, i - 1] % k - sum[0, j] % k
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() < 2 ) return false;
        int sum = 0, result = 0;
        unordered_map<int, int> preSum;
         // corner case: if the very first subarray with first two numbers in array could form the result, we need to 
    // put mod value 0 and index -1 to make it as a true case
        preSum[0] = -1;
        for( int i = 0; i < nums.size(); i++ ) {
            sum += nums[i];
            if( k != 0 ) sum %= k;
            if(preSum.find(sum) != preSum.end()) {
                cout << i << " " << preSum[sum] << endl;
                if(i - preSum[sum] > 1){
                    return true;
                }
                    
            } else {
                preSum[sum] = i;
            }
        }
        return false;
    }
};
