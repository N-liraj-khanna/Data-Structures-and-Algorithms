class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        double avg=0;
        for(int i=1;i<salary.size()-1;i++){
            avg+=salary[i];
        }
        return avg/(salary.size()-2);
    }
};