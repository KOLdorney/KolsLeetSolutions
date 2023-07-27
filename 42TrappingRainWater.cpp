//1
class Solution {
public:
    int trap(vector<int>& height) {
        int totalWater = 0, l = 0, r = height.size()-1;
        int lmax = 0, rmax = 0;
        while (l < r){
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if (lmax < rmax) {totalWater += lmax - height[l]; l++;}
            else {totalWater += rmax - height[r]; r--;}
        }
        return totalWater;
    }
};

//2
class Solution {
public:
    int trap(vector<int>& height) {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int sum=0,m=0,n=0;
        for(int i=0;i<height.size();i++) {
            m=max(m,height[i]);
            sum+=(m-height[i]);
        }
        int i=height.size()-1;
        while(height[i] != m) {
            n=max(n,height[i--]);
            sum-=(m-n);
        }
        return sum;
    }
};
