/* Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets. */

// The way we solve this problem is by determining the first integer in the triplet, then applying the same algorithm we used in the "167TwoSumII" problem.
// this will be a doubly nested loop coming after we sort the input vector.
// So, the optimal solution is O(n^2) time complexity and O(1) memory efficiency.

//My only solution (I had proceeding solutions that were faster, but in order to make them faster I had to mangle readability and overall Industry standards.)
//beat 89 percent of solutions in speed and was in the top bracket with memory efficiency.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) r--;
                else if (sum < 0) l++;
                else{
                    ret.push_back({nums[i], nums[l], nums[r]});
                    l += 1;
                    while (nums[l] == nums[l-1] && l < r) l += 1;
                }        
            }
        }
        return ret;
    }
};
