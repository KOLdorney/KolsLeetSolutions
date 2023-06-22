/* Given an array of strings strs, group the anagrams together. You can return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once. */

//Only one solution THE OPTIMAL
//At 25 ms: 98.4 percentile in speed with a complexity of O(N * k log(k)) where n is number of elements in string array and k is number of letters in the longest string
//of "strs." At 18.1 mb: 96.3 percentile in memory efficiency, with a space complexity of O(N * K).
//If you want my in-depth explanation, I posted a solution description on LeetCode:
//https://leetcode.com/problems/group-anagrams/solutions/3670729/c-98-speed-96-memory-efficiency/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> map;
        unordered_map<string, int>::iterator it;
        vector<vector<string>> ret;
        string key;
        int i;
        for(i = 0; i < strs.size(); i++){
            key = strs[i];
            sort(strs[i].begin(), strs[i].end());
            it = map.find(strs[i]);
            if (it == map.end()){
                map[strs[i]] = int(ret.size());
                ret.push_back({key});
            }
            else ret[it->second].push_back(key);
        }
        return ret;
    }
};
