#include <iostream>
#include <vector>
using namespace std;

int alternatingSum(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i % 2 == 0) {
            sum += nums[i];
        }
        else {
            sum -= nums[i];
        }
    }
    return sum;
}

int main() {
    vector<int> nums0 = {1, 3, 5, 7};
    vector<int> nums1 = {100};
    cout << alternatingSum(nums0) << '\n';
    cout << alternatingSum(nums1) << '\n';
    return 0;
}
