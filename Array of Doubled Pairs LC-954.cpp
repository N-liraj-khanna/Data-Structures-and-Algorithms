 // Just normal approach
class Solution {
public:
    
    bool canReorderDoubled(vector<int>& arr) {
        
        //sorting in absolute values
        auto cmp=[](int i, int j){ return abs(i)<abs(j); };
        sort(arr.begin(), arr.end(), cmp);
        
        int N=arr.size();
        unordered_map<int, int> map;
        
        for(int i=0;i<N;i++)
            map[arr[i]]++;
        
        for(int i=0;i<N;i++){
            if(map[arr[i]]==0)
                continue;
            
            auto it = map.find(2*arr[i]);
            if(it!=map.end() && it->second!=0){
                map[arr[i]]--;
                map[2*arr[i]]--;
            }else{
                return false;
            }
            
        }
        return true;
    }
};