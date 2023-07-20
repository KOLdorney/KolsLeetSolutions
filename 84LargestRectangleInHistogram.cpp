/*Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
  return the area of the largest rectangle in the histogram.*/

//This is a "HARD" question on LeetCode so prepare to have your brain tickled.
//I could not figure out this problem on my own I had help with the logic from NeetCode's video on this problem https://www.youtube.com/watch?v=zx5Sw9130L0&t=914s

//My final solution was 99th percentile in speed and 88th percentile in memory efficiency.
//This program is O(n) Time complexity since we go iterate through the heights vector once, and push/pop the whole stack once.
//It is also O(n) Space complexity because worst case everything in the heights vector gets pushed to the stack.
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> s;
        int LRA = 0;
        for (int i = 0; i < heights.size(); i++){
            int index = i;
            //This While loop pops any rectangles that cannot strecth any further down the histogram, because they are too tall.
            //But since we are keeping the range of index that it could strecth, we can check if it made up the max size rectangle.
            while (!s.empty() && heights[i] <= s.top().second){
                auto top = s.top();
                index = top.first;
                int height = top.second;
                int width = i - index;
                LRA = max(LRA, height * width);
                s.pop();
            }
            s.push({index , heights[i]});
        }

        //This While loop goes through the stack and calculates all the uninterupted rectangles at their starting index to the end of the histogram.
        while (!s.empty()){
            int height = s.top().second;
            int width = heights.size() - s.top().first;
            LRA = max(LRA, height * width);
            s.pop();
        }
        return LRA;
    }
};
