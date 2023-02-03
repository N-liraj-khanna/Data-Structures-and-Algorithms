// tc=o(log(n/2))+o(log(n/2))+o(log(n/2))
// sc=o(len(data stream))
class MedianFinder {
public:
    priority_queue<int> maxH;
    priority_queue<int, vector<int>, greater<int>> minH;
    MedianFinder() {}
    
    void addNum(int num) {
        maxH.push(num);
        if(!maxH.empty() && !minH.empty() && maxH.top()>minH.top()){
            minH.push(maxH.top());
            maxH.pop();
        }
        if(maxH.size()>minH.size()+1){
            minH.push(maxH.top());
            maxH.pop();
        }
        if(minH.size()>maxH.size()+1){
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        int n=maxH.size()+minH.size();
        if(n%2){
            return maxH.size()>minH.size()?maxH.top():minH.top();
        }else{
            return (double)(maxH.top()+minH.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */