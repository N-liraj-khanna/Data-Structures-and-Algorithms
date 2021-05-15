//Using Set //Much Better
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        unordered_set<string> cities;
        
        for(vector<string> path: paths) 
            cities.insert(path[1]);
        for(vector<string> path: paths)
            cities.erase(path[0]);
        
        auto it = cities.begin();
        return *it;
    }
};

//Using map, Assigning value and finsing value using iterator
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        unordered_map<string,string> cities;
        
        for(vector<string> path: paths){
            cities[path[0]]=path[1];
        }
        for(vector<string> path: paths){
            if(cities.find(path[1])==cities.end())
                return path[1];
        }
        return "";
    }
};

//Normally checking if any destinationcity is in depart city
//which is not, is the one place cant be reached
//TC => O(N^2) SC => O(1) 
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        
        int flag;
        
        for(vector<string> path: paths){
            string checkCity = path[1];
            flag=1;
            for(vector<string> pathIn: paths){
                if(pathIn[0]==checkCity){
                    flag=0;
                    break;
                }
            }
            if(flag)
                return path[1];
        }
        return "";
    }
};