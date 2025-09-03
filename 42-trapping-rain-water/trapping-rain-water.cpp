class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax = 0, rightMax = 0, index = 0;
        int maxHeight = height[0];
        int water = 0;

        // find the index of the maximum height
        for (int i = 1; i < n; i++) {
            if (height[i] > maxHeight) {
                maxHeight = height[i];
                index = i;
            }
        }

        // calculate water trapped on the left side
        for (int i = 0; i < index; i++) {
            if (leftMax > height[i])
                water += leftMax - height[i];
            else
                leftMax = height[i];
        }

        // calculate water trapped on the right side
        for (int i = n - 1; i > index; i--) {
            if (rightMax > height[i])
                water += rightMax - height[i];
            else
                rightMax = height[i];
        }

        return water;
    }
};
