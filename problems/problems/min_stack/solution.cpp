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