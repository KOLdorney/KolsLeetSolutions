/*Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 < numbers.length.
Return the indices of the two numbers, index1, and index2, added by one as an integer array [index1, index2] of length 2.
The tests are generated such that there is exactly one solution. You may not use the same element twice.
Your solution must use only constant extra space. */

// Optimal solution here is two iterators (either integer type or vector<int>::iterator type) one that starts at the beginning of the input vector and one that starts
// at the end. If the sum of the two numbers is two small increment the beginning iterator; too big, decrement the ending iterator.
// This is O(n) time comlexity and O(1) space complexity.

// My solution was 98th percentile in speed and 92nd percentile in memory efficiency.
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0, j = numbers.size()-1; i < numbers.size(), j >= 0; ){
            int sum = numbers[i] + numbers[j];
            if (sum == target) return {i+1, j+1};
            else if (sum > target) j--;
            else if (sum < target) i++;
        }
        return {0};
    }
};
