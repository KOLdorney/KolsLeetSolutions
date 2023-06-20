/* Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

for this problem I actually decided to explore a little because I did not like nor understand the efficiency results of my first submission. Through that journey,
I learned that the "auto" keyword in C++ will slow down your program, but that it may be preferrable to save memory. I am starting to notice a pattern for these
basic data stucture questions: to speed up the problem get out of the computers way, to penny-pinch with memory bit-pinch by micro-managing the computer. */

//My First Solution was 98.8 percentile for memory efficiency at 7.2 mb and at 20 ms was 17.1 percentile for speed.
// where s is size of string s, and t is size of string t, the Time complexity is O(2s + t) which simplifies to O(s+t).

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        int i;

        if (s.length() != t.length()) return false;
        
        for (i = 0; i < s.length(); i++){
            if (m.find(s[i]) == m.end()) m.insert({s[i], 1});
            else m[s[i]]++;
        }

        for (i = 0; i < t.length(); i++){
            if (m.find(t[i]) ==  m.end()) return false;
            else {
                m[t[i]]--;
                if (m[t[i]] == 0) m.erase(t[i]);
            }
        }
        if (m.empty()) return true;
        else return false;
    }
};

//My Second Solution was 13.15 percentile at 7.5 mb and at 3 ms was 98.24 percentile for speed.
//Time Complexity is slightly faster than the last at O(s + t) with no constants.

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
         unordered_map<char, int>::const_iterator mi;
        int i;

        if (s.length() != t.length()) return false;
        
        for (i = 0; i < s.length(); i++){
            m[s[i]]++;
            m[t[i]]--;
        }

        for (mi = m.begin(); mi != m.end(); mi++){
            if (mi->second != 0) return false;
        } 
        return true;
    }
};
