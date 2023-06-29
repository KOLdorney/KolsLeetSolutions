/*Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function. 
CONSTRAINTS:
-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 10^4 calls will be made to push, pop, top, and getMin. */

//My solution is O(1) and uses a stack to keep track of the minimum. I was sort of frazzled by the concept of this problem,
//Because I think allowing use of the STL makes it a trivial problem. All the top answers in efficiency just used a vector,
//or a stack for both tracking the minimum, AND THE ACTUAL STACK FUNCTIONS. But rest assured, mine is a real implimentation.
class snode{
    friend class MinStack;
    protected:
        int data;
        snode *next;
};
class MinStack {
private:
    snode *Top;
    stack<int> minhist;
public:
    MinStack() {
        Top = NULL;
    }
    void push(int val) {
        if (minhist.empty() || val <= minhist.top()) minhist.push(val);
        snode *n = new snode;
        n->data = val;
        n->next = Top;
        Top = n;
    }
    void pop() {
        cout << "got pop" << endl;
        snode *old = Top;
        if (old->data == minhist.top()) minhist.pop();
        Top = Top->next;
        delete old;
    }
    int top() {
        return Top->data;
    }
    int getMin() {
        return minhist.top();
    }
};
