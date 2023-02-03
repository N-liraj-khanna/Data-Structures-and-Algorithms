// inbuilt
class SeatManager {
public:
    priority_queue<int,vector<int>, greater<int>> pq;
    SeatManager(int n) {
        for(int i=1;i<=n;i++){
            pq.push(i);
        }
    }
    
    int reserve() {
        int op = pq.top();
        pq.pop();
        return op;

    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};


// implementation
class SeatManager {
public:
    vector<int> pq;

    void heapify(int i){
        int l=2*i+1;
        int r=2*i+2;
        int mini=i;
        if(l<pq.size() && pq[mini]>=pq[l]){
            mini=l;
        }
        if(r<pq.size() && pq[mini]>=pq[r]){
            mini=r;
        }
        if(mini!=i){
            swap(pq[mini],pq[i]);
            heapify(mini);
        }
    }

    SeatManager(int n) {
        for(int i=1;i<=n;i++){
            pq.push_back(i);
        }
    }
    
    int reserve() {
        int op=pq[0];
        pq.erase(pq.begin());
        heapify(0);
        return op;
    }
    
    void unreserve(int seatNumber) {
        pq.insert(pq.begin(),seatNumber);
        heapify(0);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */