// 3908 : valid digit number
// You are given an integer n and a digit x.

// A number is considered valid if:

// It contains at least one occurrence of digit x, and
// It does not start with digit x.
// Return true if n is valid, otherwise return false


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n);
        char target = x+'0';

        if (s[0] == target) return false;

        for (int i = 0; i<s.length(); i++){
            if (s[i] == target ) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;

    int n1 = 123, x1 = 3;
    int n2 = 123, x2 = 1;
    int n3 = 567, x3 = 8;

    cout << "Test Case 1 (n=123, x=3): " << (sol.validDigit(n1, x1) ? "True" : "False") << endl;
    cout << "Test Case 2 (n=123, x=1): " << (sol.validDigit(n2, x2) ? "True" : "False") << endl; 
    cout << "Test Case 3 (n=567, x=8): " << (sol.validDigit(n3, x3) ? "True" : "False") << endl; 

    return 0;
}