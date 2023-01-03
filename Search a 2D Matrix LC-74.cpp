// TC-> O(log(MN))
// SC->O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size();
        int start=0,end=m*n-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(matrix[mid/n][mid%n]==target) return true;
            else if(matrix[mid/n][mid%n]<target){
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return false;
    }
};

// TC-> O(log(MN))
// SC->O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=0, j=matrix[0].size()-1;
        while(j>=0 && i<matrix.size()){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};


// TC-> O(MlogN)
// SC->O(1)

class Solution {
public:
    bool binarySearch(vector<int>& m, int target){
        int start=0,end=m.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;

            if(m[mid]==target){
                return true;
            }else if(m[mid]>target){
                end=mid-1;
            }else if(m[mid]<target){
                start=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto it: matrix){
            if(binarySearch(it,target)) return true;
        }
        return false;
    }
};