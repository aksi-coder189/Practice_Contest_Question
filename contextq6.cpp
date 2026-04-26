// 3913 : sort vowels by frequency
// You are given a string s consisting of lowercase English characters.

// Rearrange only the vowels in the string so that they appear in non-increasing order of their frequency.

// If multiple vowels have the same frequency, order them by the position of their first occurrence in s.

// Return the modified string.

// Vowels are 'a', 'e', 'i', 'o', and 'u'.

// The frequency of a letter is the number of times it occurs in the string.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char, int> freq;
        unordered_map<char, int> foccur;
        string vow = "aeiou";

        for (int i = 0; i < s.length(); i++ ){
            if (vow.find(s[i]) != string::npos){
                freq[s[i]]++;
                if (foccur.find(s[i]) == foccur.end()){
                    foccur[s[i]] = i;
                }
            }
        }

        vector<char> extvow;
        for (char c : s){
            if (vow.find(c) != string::npos){
                extvow.push_back(c);
            }
        }

        sort(extvow.begin(), extvow.end(), [&](char a, char b){
            if (freq[a] != freq[b]){
                return freq[a] > freq[b];
            }
            return foccur[a] < foccur[b];
        });

        int idx = 0;
        for (int i = 0; i < s.length(); i++){
            if (vow.find(s[i]) != string::npos){
                s[i] = extvow[idx++];
            }
        }
        return s;
    }
};

int main() {
    Solution sol;

    string s = "leetcode";

    string result = sol.sortVowels(s);

    cout << "Sorted vowels string: " << result << endl;

    return 0;
}