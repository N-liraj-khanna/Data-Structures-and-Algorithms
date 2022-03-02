// Do XOR one by one, go left first step then go down as second step,
// Alas! put it in PQ, get the kth largest element
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue <int, vector<int>, greater<int>> pq;
        int N=matrix.size(), M=matrix[0].size();
        
        for(int i=0;i<N;i++){
            for(int j=1;j<M;j++){
                matrix[i][j]=matrix[i][j-1]^matrix[i][j];
            }
        }

        for(int i=0;i<M;i++){
            for(int j=1;j<N;j++){
                matrix[j][i]=matrix[j-1][i]^matrix[j][i];
            }
        }
        
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                pq.push(matrix[i][j]);
                if(pq.size()>k){
                        pq.pop();
                }
            }
        }
                
        return pq.top();
    }
};
