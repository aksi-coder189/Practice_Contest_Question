// 3909 : compare sums of bitonic parts
// You are given a bitonic array nums of length n.

// Split the array into two parts:

// Ascending part: from index 0 to the peak element (inclusive).
// Descending part: from the peak element to index n - 1 (inclusive).
// The peak element belongs to both parts.

// Return:

// 0 if the sum of the ascending part is greater.
// 1 if the sum of the descending part is greater.
// -1 if both sums are equal.
// Notes:

// A bitonic array is an array that is strictly increasing up to a single peak element and then strictly decreasing.
// An array is said to be strictly increasing if each element is strictly greater than its previous one (if exists).
// An array is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int peak_idx =0;

        for ( int i = 0; i < n-1; i++){
            if ( nums[i] > nums[i+1]){
                peak_idx = i;
                break;
            }
            if ( i == n-2){
                peak_idx = n-1;
            }
        }
        long long ascsum = 0;
        long long descsum = 0;

        for (int i=0; i <= peak_idx; i++){
            ascsum += nums[i];
        }
        for ( int i = peak_idx; i<n; i++){
            descsum += nums[i];
        }
        if (ascsum > descsum ) return 0;
        if (descsum > ascsum ) return 1; 
        return -1;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 5, 3, 2}; 
    cout << "Test 1: " << sol.compareBitonicSums(nums1) << endl;
    vector<int> nums2 = {1, 2, 3, 4}; 
    cout << "Test 2: " << sol.compareBitonicSums(nums2) << endl;

    return 0;
}