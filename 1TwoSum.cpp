/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.*/

//I once again have two solutions today, and I will call on them as the brute and the subtle.
//For my first solution, if you can believe it, is the brute. It was 5.2 percentile in speed at 1103 ms and 93.99 percentile in memory efficiency at 10 mb.
//Memory Complexity is O(1),  Time Complexity is O(n^2)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, n;
        vector<int> ret;
        for (i = 0; i < nums.size(); i++){
            for (n = 0; n < nums.size(); n++){
                if (((nums[i] + nums[n]) == target) && (i != n)){
                    ret.push_back(i);
                    ret.push_back(n);
                    return ret;
                }
            }
        }
        return ret;
    }
};

//My tinkered solution is called the subtle, It was 99.83 percentile of speed at 3 ms and 23.79 percentile of memory efficiency at 10.9 mb.
//The way I landed this solution in the top 50 speed wise, was instead of using the bracket access operator in my return statement, I saved the iterator from 
//my find statement and used a pointer
//Time Complexity O(n), Memory Complexity O(n)

#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map< int, int > bers;
        unordered_map< int, int >::iterator it;
        int i;
        for (i = 0; i < nums.size(); i++){
            it = bers.find(target - nums[i]);
            if (it == bers.end()){
                bers[nums[i]] = i;
            }
            else return {it->second, i};
        }
        return {0};
    }
};
