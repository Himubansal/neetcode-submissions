class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        if(n<2) return 0;
        int left=0,right=n-1,total=0;
        while(left<right){
            int currentHeight = min(heights[left], heights[right]);
            int currentWidth = right - left;
            total = max(total, currentHeight * currentWidth);

            if(heights[left] < heights[right]){
                left++;
            }
            else{

                right--;
            }
        }
        return total;
    }
};

