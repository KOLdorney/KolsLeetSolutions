## Intuition
I see that the array is actually sorted just not from the 0th index,
so the fastest way to search it will be binary search. Then I realize  that since it is in ascending order my binary search will be looking left to right to handle the pivot.
## Approach
I handle the pivot case by checking for sortedness from the low element to the middle element, and if it is found to be sorted I then see if the target lies within that range, if it does, I partiotion off _everything but that range_, if not, I partition off _the low to middle range of values_. If the low to middle range is found to be unsorted, I do the same as before but with the middle to high range. This makes it so that we are only checking sorted ranges that contain the target, 

## Complexity
- Time complexity:
O(log(n))

- Space complexity:
O(1)

## Code
```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size()-1;
        while (l <= h){
            int m = (l+h)/2;
            if (nums[m] == target) return m;
            //left half is sorted.
            if (nums[l] <= nums[m]){
                if (target >= nums[l] && target <= nums[m]) h = m-1;
                else l = m+1;
            }
            //right half is sorted.
            else{
                if (target <= nums[h] && target >= nums[m]) l = m+1;
                else h = m-1;
            }
        }
        return -1;
    }
};
```
