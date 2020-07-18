#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int v = 0;
        auto it0 = std::adjacent_find(prices.begin(), prices.end(), std::less<int>());
        if (it0 == prices.end()) return 0;
        auto p0 = *it0;
        while (true) {
            auto it1 = std::adjacent_find(prices.begin(), prices.end(), std::greater<int>());
            if (it1 == prices.end()) {
                return v;
            }
        }
        return v;
    }
};

int main() {
    Solution sol;
    vector<int> v = {7,1,5,3,6,4};
    auto n = sol.maxProfit(v);

    return 0;
}
