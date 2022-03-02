/**********SPIRAL MATRIX************/
//Most Optimal TC => Approx. O(M*N) SC => SC => O(1)

vector<int> spiralOrder(vector<vector<int>> &matrix)
{

    int rowBegin = 0, rowEnd = matrix.size() - 1;      //Create boundaries for rows and columns
    int colBegin = 0, colEnd = matrix[0].size() - 1;   //to reduce the given matrix by row and column  

    vector<int> res;

    while (rowBegin <= rowEnd && colBegin <= colEnd)  //Until the row & column reaches center of the matrix 
    {
        for (int i = colBegin; i <= colEnd; i++)  //printing the first row, then the second row... towards
            res.push_back(matrix[rowBegin][i]);    //the left side
        
        rowBegin++;  //move to next row from top, and other moves respectively
        
        for (int i = rowBegin; i <= rowEnd; i++)    //printing the last column, then the second last column...
            res.push_back(matrix[i][colEnd]);       // towards the down side
        
        colEnd--;  
        //Note -> Very Important to understand
        if (rowBegin <= rowEnd)   //When we reach the final or inner most elements/ or inner row to check if
        {                           //the row exist, these values will already be inserted by prev loops 
            for (int i = colEnd; i >= colBegin; i--)
                res.push_back(matrix[rowEnd][i]);    //As said this is to print from end column to start 
           
            rowEnd--;
        }
        
        if (colBegin <= colEnd)   //similarly, to ensure if the column exist to insert row
        {
            for (int i = rowEnd; i >= rowBegin; i--)    //Respectively from end row to start row
                res.push_back(matrix[i][colBegin]);
           
            colBegin++;
        }
    }
    return res;
}