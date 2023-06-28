/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type. */

//The coolest solution I saw was someone using the input string as a stack (which makes sense as it is the most fundamental data structure). 

//Today was a doozie, my first solution was an inefficient recursive monstrosity, and my second was a very fast and straigtforward stack solution.
//My first solution with O(n^2) time complexity and O(n) space complexity
class Solution {
public:
    int finishCurl(const string& s, int index){
        cout << "got to curl with index: " << index << endl;
        for (; index < s.length(); index++){
            if (s[index] == '(') index = finishParen(s, index+1);
            else if (s[index] == '[') index = finishBrack(s, index+1);   
            else if (s[index] == '{') index = finishCurl(s, index+1);
            else if (s[index] == ')' || s[index] == ']') break;
            else if (s[index] == '}') return index;
            if (index == 0) break;
        }
        return 0;
    }
    int finishBrack(const string& s, int index){
        cout << "got to brack with index: " <<  index << endl;
        for (; index < s.length(); index++){
            if (s[index] == '(') index = finishParen(s, index+1);
            else if (s[index] == '[') index = finishBrack(s, index+1);   
            else if (s[index] == '{') index = finishCurl(s, index+1);
            else if (s[index] == '}' || s[index] == ')') break;
            else if (s[index] == ']') return index;
            if (index == 0) break;
        }
        return 0;
    }
    int finishParen(const string& s, int index){
        cout << "got to paren with index: " <<  index <<endl;
        for (; index < s.length(); index++){
            if (s[index] == '(') index = finishParen(s, index+1);
            else if (s[index] == '[') index = finishBrack(s, index+1);   
            else if (s[index] == '{') index = finishCurl(s, index+1);
            else if (s[index] == '}' || s[index] == ']') break;
            else if (s[index] == ')') return index;
            if (index == 0) break;
        }
        return 0;
    }

    bool isValid(string s) {
        int i, count;
        bool foundStart;
        for (i = 0; i < s.length(); i++){
            foundStart = false;
            if (s[i] == '('){
                i = finishParen(s, i+1);
                if (i) foundStart = true;
            }
            else if (s[i] == '['){
                i = finishBrack(s, i+1);
                if (i) foundStart = true;
            }
            else if (s[i] == '{'){
                i = finishCurl(s, i+1);
                if (i) foundStart = true;
            }
            if (!foundStart) return false;
        }
        return true;
    }
};

//My second solution breaks fewer standards and is much more concise.
//O(n) time complexity. O(n) space complexity.
class Solution {
public:
    bool isValid(const string& s){
        stack<char> t;
        int i;
        char c;
        for (i = 0; i < s.length(); i++){
            c = s[i];
            if (c == '(' || c == '{' || c == '[') t.push(c);
            else if (t.empty()) return false;
            else if (c == ')' && t.top() == '(') t.pop();
            else if (c == '}' && t.top() == '{') t.pop();
            else if (c == ']' && t.top() == '[') t.pop();
            else t.push(c);       
        }
        if (t.empty()) return true;
        else return false;
    }
};
