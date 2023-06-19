//Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

/* To Solve this problem I decided to take advantage of the Set structures adantage,
namely the unique instances and the O(log(n)) time of insert and find.  */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int i;
        set<int> s;
        for (i = 0; i < nums.size(); i++){
            if (s.find(nums[i]) != s.end()) return true;
            else s.insert(nums[i]);
        }
        return false;
    }
};
