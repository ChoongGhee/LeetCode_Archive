class Solution {
    public:
        int maxArea(vector<int>& height) {
            int l, r = height.size()-1;
            l = 0;

            int max = 0;
            while(l < r){
                int he = height[l] < height[r] ? height[l] : height[r];
                int val = he*(r-l);
                if(max < val) max = val;

                cout << max << " " << l << " " << r << endl;

                height[l] < height[r] ? l++ : r--;
            }

            return max;
        }
    };