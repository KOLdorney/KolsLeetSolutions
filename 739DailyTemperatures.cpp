/* Given an array of integers temperatures represents the daily temperatures,
return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature.
If there is no future day for which this is possible, keep answer[i] == 0 instead. */

//Simple Solution Today: O(n) time and O(1) space, backwards integer-based pair iteration (fast, and elegant).
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret (temperatures.size());
        int i, j;
        for (i = temperatures.size()-2; i >=0; i--){
            j = i+1;
            while(j < temperatures.size() && temperatures[i] >= temperatures[j]){
                if (ret[j] > 0) j += ret[j];
                else j = temperatures.size();
            }
            if (j < temperatures.size()) ret[i] = j - i;
        }
        return ret;
    }
};
