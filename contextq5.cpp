// 3912 : valid elements in an array
// You are given an integer array nums.

// An element nums[i] is considered valid if it satisfies at least one of the following conditions:

// It is strictly greater than every element to its left.
// It is strictly greater than every element to its right.
// The first and last elements are always valid.

// Return an array of all valid elements in the same order as they appear in nums.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n =  nums.size();
        if ( n==0) return {};

        vector<bool> isvalid(n, false);
        isvalid[0]=true;
        isvalid[n-1]=true;

        int lmax=nums[0];
        for (int i=1; i<n; i++){
            if (nums[i]>lmax){
                isvalid[i]=true;
            }
            lmax=max(lmax, nums[i]);
        }
        int rmax=nums[n-1];
        for (int i = n-2; i>=0; i--){
            if (nums[i]>rmax){
                isvalid[i] = true;
            }
            rmax=max(rmax, nums[i]);
        }
        vector<int> res;
        for(int i=0; i<n; i++){
            if (isvalid[i]){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 1, 4, 2, 5};

    vector<int> result = sol.findValidElements(nums);

    cout << "Valid elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}