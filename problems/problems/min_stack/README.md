# 🚀 Min Stack

🔗 **LeetCode Link:**  
https://leetcode.com/problems/min-stack/

---

## 🎯 Difficulty

**Medium**

---

## 🏷️ Tags

Stack, Design

---

## 📖 Problem Description

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:


	MinStack() initializes the stack object.
	void push(int value) pushes the element value onto the stack.
	void pop() removes the element on the top of the stack.
	int top() gets the top element of the stack.
	int getMin() retrieves the minimum element in the stack.


You must implement a solution with O(1) time complexity for each function.

 
Example 1:


Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2


 
Constraints:


	-231 <= val <= 231 - 1
	Methods pop, top and getMin operations will always be called on non-empty stacks.
	At most 3 * 104 calls will be made to push, pop, top, and getMin.



---

## 💻 My Solution

```cpp
class MinStack {
    private:
    int *st;
    int  topIndex;
    int capacity;

public:
    MinStack() {
        capacity = 1000;
         topIndex = -1;
        st = new int[capacity];
    }
    
    ~MinStack(){
        delete[] st;
    }
    void push(int val) {
        if( topIndex>=capacity-1){
            return;
        }
        st[++ topIndex]= val; 
    }
    
    void pop() {
        if( topIndex==-1){
            return;
        }
         topIndex--;
    }
    
    int  top() {
         if( topIndex == -1) return -1;
         return st[ topIndex];
    }
    
    int getMin() {
        if( topIndex== -1) return -1;

        int min = st[0];
        for(int i =1 ; i<= topIndex ; i++){
            if(st[i]<min){
                min =st[i];
            }
        }
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:20:49*
