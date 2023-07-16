// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// "well-formed" meaning the open parenthesis are either closed immediately or at the end of another well-formed parenthesis string.

// Just by reading that definition of the problem your recursion spidey senses should be going off the charts. And recursion is by far my most shallowly understood
// concept in computer science. So today after a few weeks, I splurged and did 3 solutions.

// My first Solution was 5th percentile in both speed and memory efficiency. I wastefully used an old backtracking algorithm to enumerate all possible strings
// given the length of the strings and the number of ones in the string (all the non-ones were to be zeros). Obviously, that recursive function is not a tight fit for
// this use-case. Nevertheless, I decided to use my solution for "20ValidParenthess" as a helper to filter out all the invalid solutions from the overly atomic 
// function. The final program was an ugly, unsatisfying testament to how much even a short hiatus from this craft can clog your logic cogs (say that 5 times fast).
// So I will not include it here.

//My second solution, a patchwork of the glorious resources available on the internet, was an underwhelming 10th percentile in both time and memory,
//despite being somewhat intuitive:

//The reason for this is the non-exclusive conditions in the recursive statement, giving us some BPU (Branch Prediction Unit) penalties.
//The third solution further below was a response to this weakness.
class Solution {
public:
    vector<string> ret;
    vector<string> generateParenthesis(int n) {
        enumerateParenthesis( n , 0 , "");
        return ret;
    }
    void enumerateParenthesis(int l, int r, string s){
        if (l == 0 && r == 0){
            ret.push_back(s);
            return;
        }
        if (r > 0){
            enumerateParenthesis(l, r-1, s+')');
        }
        if (l > 0){
            enumerateParenthesis(l-1, r+1, s+'(');
        }
    }
};

//So now we understand the problem and have an intuitive skeleton. Time for a sprinkle of *elegance*.
//This solution was tied for first place in speed with 0 ms (there were only eight test cases), and was 35th percentile in memory efficiency.
class Solution {
public:
    vector<string> ret;
    vector<string> generateParenthesis(int n) {
        enumerateParenthesis( n-1 , n , "(");
        return ret;
    }
    void enumerateParenthesis(int l, int r, string s){
        if (l == 0 && r == 0){
            ret.push_back(s);
            return;
        }
        else if (l == r) enumerateParenthesis(l-1, r, s+'(');
        else if (l == 0) enumerateParenthesis(l, r-1, s+')');
        else if (r == 0) enumerateParenthesis(l-1, r, s+'(');
        else{
            enumerateParenthesis(l-1, r, s+'(');
            enumerateParenthesis(l, r-1, s+')');
        }
    }
};

