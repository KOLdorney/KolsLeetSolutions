/* Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.
 Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)*/

//I had no clue how to due this one, so after reading about prefix sum, and watching some videos I tinkered down to this solution,
//which I will title as "El Loro"
//96 percentile in speed with a runtime of 19 ms. 96 percentile in memory efficiency, using 23.9 mb.
//Time Complexity is O(n), Space Complexity is O(1) within the context of the prompt.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t sz = nums.size();
        vector<int> ret (sz);
        int i;
        int p = 1;
        ret[0] = 1;
        for (i = 1; i < sz; i++){
            ret[i] = ret[i-1] * nums[i-1];
        }
        for (i = sz - 1; i >= 1; i--){
            p = p *nums[i];
            ret[i-1] = ret[i-1] * p;
        }
    return ret;
    }
};
