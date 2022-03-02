/***************************HEAP SORT******************************/
//TC => O(nlogn)    SC => O(1)
//----------------------ITERATIVE APPROACH--------------------------------//

void heapify(int arr[], int n, int idx) { 
   for (int i = idx; i < n / 2; i++) {
       if (arr[i] < arr[2 * i + 1])
           swap(arr[i], arr[2 * i + 1]);
       if (2 * i + 2 < n && arr[i] < arr[2 * i + 2])
           swap(arr[i], arr[2 * i + 2]);
   }
}
//----------------------RECURSIVE APPROACH--------------------------------//
void heapify(int arr[], int n, int i) 
{
   int largest = i; 
   int l = 2 * i + 1; 
   int r = 2 * i + 2; 

   if (l < n && arr[l] > arr[largest])
       largest = l;
   if (r < n && arr[r] > arr[largest])
       largest = r;
   if (largest != i) {
       swap(arr[i], arr[largest]);
       heapify(arr, n, largest);
   }
}
//-----------------BUILD HEAP USING HEAPIFY------------------------------//
//by heapifying once will bring the max element to the top, and by swapping to the end 
//will be its position by doing so one eleemtn less will sort the values
void buildHeap(int arr[], int n) {
   for (int i = n / 2; i >= 0; i--)
       heapify(arr, n, i);
   for (int i = n-1; i > 0; i--) {
       swap(arr[0], arr[i]);
       heapify(arr,i, 0);
   }
}

