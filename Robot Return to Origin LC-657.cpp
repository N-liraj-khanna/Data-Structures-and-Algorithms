//using switch cases
class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        
        for(char dir: moves){
            switch(dir){
                case 'U': y+=1;break;
                case 'D': y-=1;break;
                case 'L': x-=1;break;
                case 'R': x+=1;break;
            }
        }
        return x == 0 && y ==0;  
    }
};
//using map
class Solution {
public:
    bool judgeCircle(string moves) {
        int x=0,y=0;
        
        unordered_map<char,int> dirMap;
        
        for(char dir: moves){
            dirMap[dir]++;
        }
        
        return dirMap['U'] == dirMap['D'] && dirMap['L'] == dirMap['R'];  
    }
};