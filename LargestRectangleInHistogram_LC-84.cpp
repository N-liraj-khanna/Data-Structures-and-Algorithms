/***************Largest Area in Histogram*******************/
//OPTIMIZED => TC => O(N)  SC=>O(N)  
int largestRectangleArea(vector<int>& h) {
    int maxi = h[0];
    stack<int> indices, values;
    indices.push(0);
    values.push(h[0]);
    int i = 0, flag;
    int prevIndex=0,prevVal=0;
    for (i = 1; i < h.size(); i++) {
        prevVal = -1;
        flag = 1;
        while (!values.empty() && values.top() > h[i]) {
            int area;
            area= values.top() * (i - indices.top());  //FORMULA
            maxi = max(area, maxi);
            prevVal = values.top();
            values.pop();
            prevIndex = indices.top();
            indices.pop();
        }
        values.push(h[i]);
        if (prevVal > h[i])
            indices.push(prevIndex);
        else indices.push(i);
    }
    while (!values.empty()) {
        int area = values.top() * (i - indices.top());
        maxi = max(area, maxi);
        values.pop();
        indices.pop();
    }
    return maxi;
}    
    
//Naive Approach 
//TC => O(N^2)  SC=>O(1)  
int largestRectangleArea(vector<int>& h) {
    int maxi=-1,checkVal=0,check;
    for(int i=0;i<h.size();i++){  
        check=h[i];    
        checkVal=0;    
            for(int j=i;j<h.size();j++){
                if(check<=h[j]) checkVal+=check;  
                else break; 
            }
        for(int j=i-1;j>=0;j--){
                if(check<=h[j]) checkVal+=check;
                else break;    
        }
        if(maxi<checkVal) maxi = checkVal; 
    }
    return maxi;
}