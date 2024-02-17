class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
        for (int i = 0; i < heights.size() - 1; ++i) {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0) {
                heap.push(diff);
                if (heap.size() > ladders) {
                    bricks -= heap.top();
                    heap.pop();
                }
                if (bricks < 0) {
                    return i;
                }
            }
        }
        return heights.size() - 1;
    }
};