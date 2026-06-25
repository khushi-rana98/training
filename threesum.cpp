#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        if (i > 0 && nums[i] == nums[i-1]) continue;
        int l = i + 1, r = n - 1;
        while (l < r) {
            long long s = (long long)nums[i] + nums[l] + nums[r];
            if (s == 0) {
                res.push_back({nums[i], nums[l], nums[r]});
                while (l < r && nums[l] == nums[l+1]) ++l;
                while (l < r && nums[r] == nums[r-1]) --r;
                ++l; --r;
            } else if (s < 0) ++l; else --r;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) {
        // No input provided; show usage with example
        vector<int> ex = {-1, 0, 1, 2, -1, -4};
        auto res = threeSum(ex);
        for (auto &t : res) {
            cout << t[0] << ' ' << t[1] << ' ' << t[2] << '\n';
        }
        return 0;
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    auto res = threeSum(a);
    for (auto &t : res) {
        cout << t[0] << ' ' << t[1] << ' ' << t[2] << '\n';
    }
    return 0;
}