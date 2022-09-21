// Approach 1

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int time=0;
        vector<int> type={0,0,0};
        
        for(int i=0;i<garbage.size();i++){
            for(int j=0;j<garbage[i].size();j++){
                
                if(garbage[i][j]=='M') type[0]=i;  
                else if(garbage[i][j]=='P') type[1]=i; 
                else type[2]=i;  
                
                time++;
            }
        }
        
        for(int i: type){
            for(int j=0;j<i;j++){
                time+=travel[j];
            }
        }
        return time;
    }
};

// Prefix Sum approach
class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        
        int time=0;
        vector<int> type={0,0,0};
        
        for(int i=0;i<garbage.size();i++){
            for(int j=0;j<garbage[i].size();j++){
                
                if(garbage[i][j]=='M') type[0]=i;  
                else if(garbage[i][j]=='P') type[1]=i; 
                else type[2]=i;  
                
                time++;
            }
        }
        
        for(int i=1;i<travel.size();i++){
            travel[i]+=travel[i-1];
        }
        
        if(type[0]!=0){
           time+=travel[type[0]-1];
        }
        if(type[1]!=0){
           time+=travel[type[1]-1];
        }
        if(type[2]!=0){
           time+=travel[type[2]-1];
        }
        return time;
    }
};