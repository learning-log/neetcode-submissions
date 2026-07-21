class MinStack {
public:
    stack<int> nst;
    stack<int> minst;
    MinStack() {
        // stack<int> nst;
        // stack<int> minst;
    }
    
    void push(int val) {
        if(minst.empty()){
            minst.push(val);
        }
        else if(minst.top()>=val){
            minst.push(val);
        }
        nst.push(val);
    }
    
    void pop() {

        if(minst.top()==nst.top()){
            minst.pop();
            nst.pop();
        }
        else{
            nst.pop();
        }
        
    }
    
    int top() {
        return nst.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
