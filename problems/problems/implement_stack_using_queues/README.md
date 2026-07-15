# Implement Stack using Queues

🔗 Link:
https://leetcode.com/problems/implement-stack-using-queues/

## Difficulty

Easy

## Tags

Stack, Design, Queue

## Problem Description

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:


	void push(int x) Pushes element x to the top of the stack.
	int pop() Removes the element on the top of the stack and returns it.
	int top() Returns the element on the top of the stack.
	boolean empty() Returns true if the stack is empty, false otherwise.


Notes:


	You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
	Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue&#39;s standard operations.


&nbsp;
Example 1:


Input
[&quot;MyStack&quot;, &quot;push&quot;, &quot;push&quot;, &quot;top&quot;, &quot;pop&quot;, &quot;empty&quot;]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False


&nbsp;
Constraints:


	1 &lt;= x &lt;= 9
	At most 100 calls will be made to push, pop, top, and empty.
	All the calls to pop and top are valid.


&nbsp;
Follow-up: Can you implement the stack using only one queue?


## Solution

See `solution.cpp`
