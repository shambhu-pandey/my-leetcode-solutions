class MyQueue {

   Stack<Integer> s1 = new Stack<>();
   Stack<Integer> s2 = new Stack<>();


    public MyQueue() {
        
    }
    
    public void push(int x) {
        // move everything from s1 to s2
        while(!s1.isEmpty()){
            s2.push(s1.pop());
        }
        // push new element to s1
        s1.push(x);
        // move everything back from s2 to s1
        while(!s2.isEmpty()){
            s1.push(s2.pop());
        }
    }
    
    public int pop() {
           return s1.pop();
    }
    
    public int peek() {
        return s1.peek();
    }
    
    public boolean empty() {
        return s1.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */