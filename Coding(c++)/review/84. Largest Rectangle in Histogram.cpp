class Solution {
public:
    
    /*
    how many bars to the left (including the bar at index i) are equal or higher than bar[i], 
    right[i] is that to the right of bar[i], so the the square of the max rectangle 
    containing bar[i] is simply height[i] * (left[i] + right[i] - 1)
    */
    
    int largestRectangleArea(vector<int>& heights) {
        int N = heights.size();
        std::vector<int> left(N, 1);
        std::vector<int> right(N, 1);
        
        // Compute #bars equal or higher than bar[i] at left
        for (int i=0; i<N; i++) {
            int j = i - 1;
            while (j >= 0) {
                if (heights[j] >= heights[i]) {
                    left[i] += left[j];
                    j -= left[j];
                }
                else
                    break;
            }
        }
        // Compute #bars equal or higher than bar[i] at right
        for (int i=N-1; i>=0; i--) {
            int j = i+1;
            while (j < N) {
                if (heights[j] >= heights[i]) {
                    right[i] += right[j];
                    j += right[j];
                }
                else
                    break;
            }
        }
        // Compute area for each i
        int ans = 0;
        for (int i=0; i<N; i++) {
            int h = heights[i];
            int w = left[i] + right[i] - 1;
            ans = std::max(ans, h*w);
        }
        return ans;
    }
};
