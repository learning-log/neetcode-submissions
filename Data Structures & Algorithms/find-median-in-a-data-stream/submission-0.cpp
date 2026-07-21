class MedianFinder {
public:
    priority_queue<int> pq1,pq2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq1.empty()){
            pq1.push(num);
            return;
        }
        // else{
            
        if(pq1.size()==pq2.size()){
            // int n1 = pq1.top();
            int n2 = -pq2.top();
            if(n2<num){
                pq2.pop();
                pq1.push(n2);
                pq2.push(-num);
            }
            else{
                pq1.push(num);
            }
        }
        else{
            int n1 = pq1.top();
            if(n1>num){
                pq1.pop();
                pq1.push(num);
                pq2.push(-n1);
            }
            else{
                pq2.push(-num);
            }
        }
        // }
        
    }
    
    double findMedian() {
        cout<<pq1.size()<<" "<<pq2.size()<<endl;
        if(pq1.size()==pq2.size()){
            return ((double)pq1.top()+(double)(-pq2.top()))/2;
        }
        else{
            return (double)pq1.top();
        }
    }
};
