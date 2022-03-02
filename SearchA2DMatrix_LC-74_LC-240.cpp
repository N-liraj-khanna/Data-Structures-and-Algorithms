
/****************74. Search a 2D Matrix****************/
/******************1st Approach*********************/
// Most Optimal TC => O(logN+logM) SC => O(1)
// Two Binary Search
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        if (matrix[0][0] > target)
            return false;

        int targetRowIndex;
        int start = 0, end = matrix.size() - 1;
        int mid = 0;
        while (start <= end)
        { //Do binary search for the rows to find where the target is
            mid = (start + end) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] < target && //when we find a bound between mid and mid+1 where the
                     (mid + 1 == matrix.size() || matrix[mid + 1][0] > target))
            {                         //target resides assign it to
                targetRowIndex = mid; //to our targetIndexRow and break out, One constrain
                break;                //if the target in the last row, so we check if that
            }                         //mid is at the end and the first element is greater than target
            else if (matrix[mid][0] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        targetRowIndex = mid;
        start = 0;
        end = matrix[0].size() - 1;

        while (start <= end)
        {
            mid = (end + start) / 2;
            if (matrix[targetRowIndex][mid] == target) //Do normal binary search for tht row
                return true;
            else if (start == end)
                return false;
            else if (matrix[targetRowIndex][mid] > target)
                end = mid - 1;
            else if (matrix[targetRowIndex][mid] < target)
                start = mid + 1;
        }
        return false;
    }
};
/******************2nd Approach*********************/
// Most Optimal TC => O(log(MN) SC => O(1)
//One Binary Search, Treat the whole @D array as 1D array
//With this formula ->
/******************matrix[mid/n][mid%n]********************/
//this gives the index of the current mid value in the 2D array, where n is length of column
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {

        int m = matrix.size();
        int n = matrix[0].size();

        int start = 0, end = m * n - 1, mid = 0;

        while (start <= end)
        { //Normal Binary Search

            mid = end + start / 2;
            // Note ->Understand it, V V V Important
            if (matrix[mid / n][mid % n] == target)     //Checking using this formula
                return true;                            //if equal, greater or lesser
            else if (matrix[mid / n][mid % n] > target) //Gives the index of current mid value
                end = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }
};

/******************3rd Approach*********************/
//Normal/ Decent Approach TC => O(N+logM) SC => O(1)   (Better than 4th approach)
// Linear Search And Binary Search
bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    if (matrix[0][0] > target)
        return false;

    int targetRowIndex = matrix.size() - 1;

    for (int i = 1; i < matrix.size(); i++) //Linear Search for finding the index of row
    {                                       // where the target belongs
        if (matrix[i][0] > target)
        {
            targetRowIndex = i - 1;
            break;
        }
    }

    int start = 0, end = matrix[0].size() - 1;
    int mid;

    while (start <= end) //Binary Search to find the values's index if present
    {
        mid = (end + start) / 2;
        if (matrix[targetRowIndex][mid] == target)
            return true;
        else if (start == end)
            return false;
        else if (matrix[targetRowIndex][mid] > target)
            end = mid - 1;
        else if (matrix[targetRowIndex][mid] < target)
            start = mid + 1;
    }

    return false;
}

/****************240. Search a 2D Matrix-II****************/
/******************4th Approach*********************/
//(This Works for LeetCode 74. Search a 2D Matrix Problem too!) /*****LC-74 & LC-240*****/
/****Intuitive**** NAIVE Approach TC => O(N+M) SC => O(1)*/
// Linear Search And Binary Search
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = 0;
    int col = matrix[0].size() - 1;

    while (row < matrix.size() && col >= 0)
    {                                       //since sorted in ascending, can check
        if (matrix[row][col] == target)     //from top right corner and traverse as
            return true;                    //down and left to arrive to our value
        else if (matrix[row][col] > target) //if not present it will be at the end of bottom left
            col--;
        else if (matrix[row][col] < target)
            row++;
    }
    return false;
}

/******************5th Approach*********************/
//(This Works for LeetCode 74. Search a 2D Matrix Problem too!) /*****LC-74 & LC-240*****/
//My Dumb Approach/ NAIVE Approach TC => O(MlogN) SC => O(1)*/
// Linear Search And Binary Search  (Ignore)
bool searchMatrix(vector<vector<int>> &matrix, int target)
{

    int m = matrix.size() - 1;
    int n = matrix[0].size() - 1;

    for (int i = 0; i <= m; i++)
    {

        if (matrix[i][n] >= target)
        { //Do binary seach for each row whose end value in each row is less
            //than the target value
            int start = 0, end = matrix[i].size() - 1;
            int mid = 0;

            while (start <= end)
            {
                mid = (end + start) / 2;
                if (matrix[i][mid] == target)
                    return true;
                else if (matrix[i][mid] > target)
                    end = mid - 1;
                else if (matrix[i][mid] < target)
                    start = mid + 1;
            }
        }
    }
    return false;
}