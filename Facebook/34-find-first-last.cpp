class Solution {
public:
vector<int> searchRange(vector<int>& nums, int target) {
    auto it1 = std::lower_bound(nums.begin(), nums.end(), target);
    auto it2 = std::upper_bound(nums.begin(), nums.end(), target);
    if (it1 != nums.end() && *it1 == target) 
        return {it1 - nums.begin(), it2 - nums.begin() - 1};
    return {-1, -1};
}
};