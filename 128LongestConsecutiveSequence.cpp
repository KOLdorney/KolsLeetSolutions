/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.*/

//Relative Efficiency is skewed because LeetCode did not enforce the prompt; lots of O(nlogn) submissions passed because the test cases lacked volume.
//I will just say I had one of the faster O(n) solutions I saw (because iterator types are lightning-fast and nobody knows how to use them).
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        unordered_set<int>::iterator sit, csit;
        int longest = 0;
        int count;
        for (sit = s.begin(); sit != s.end(); sit++){
            if (s.find(*sit-1) == s.end()){
                count = 1;
                csit = sit;
                while (true){
                    csit = s.find(*csit+1);
                    if (csit != s.end()) count++;
                    else break;          
                }
                if (count > longest) longest = count;
            }
        }
        return longest;
    }
};
