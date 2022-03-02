/*****************Merge two binary Max heaps Optimal**********************/ 
/***************************Merge Heaps, Not Sort************************/
//TC => O(N logN) SC => O(1)
void heapify(int medium[], int idx, int n) {

   int large = idx;
   int l = 2 * idx + 1;
   int r = 2 * idx + 2;

   if (l < n && medium[large] < medium[l])
       large = l;
   if (r < n && medium[large] < medium[r])
       large = r;

   if (idx != large) {
       swap(medium[large], medium[idx]);
       heapify(medium, large, n);
   }
}

void arrToHeap(int medium[], int n) {
   for (int i = n / 2; i >= 0; i--) {
       heapify(medium, i, n);
   }
}

void mergeHeaps(int medium[], int a[], int b[], int n, int m) {
//Medium is the array which stores merged values of a and b array
   for (int i = 0; i < n; i++)
       medium[i] = a[i];
   for (int i = 0; i < m; i++)
       medium[n + i] = b[i];
   arrToHeap(medium, n + m);
}
