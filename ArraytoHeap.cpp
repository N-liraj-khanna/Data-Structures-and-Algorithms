/***************************Normal Array to Heap*******************************/
void toHeap(vector<int>& v) {
   int idx = v.size() / 2-1;
   for (int i = idx; i >= 0; i--) {
       MaxHeapify(v, i);
   }
}

void MaxHeapify(vector<int>& v,int idx) {
   for (int i = idx;  i < v.size() / 2; i++) {

       int left = 2 * i + 1, right = 2 * i + 2;

       if (v[i] < max(v[left], v[right])) {
           if (v[i] < v[left])
               swap(v[i], v[left]);
           if (right < v.size() && v[i] < v[right])
               swap(v[i], v[right]);
       }

   }
}

void MinHeapify(vector<int>& v, int idx) {
   for (int i = idx; i < v.size() / 2; i++) {

       int left = 2 * i + 1, right = 2 * i + 2;

       if (v[i] > max(v[left], v[right])) {
           if (v[i] > v[left])
               swap(v[i], v[left]);
           if (right < v.size() && v[i] > v[right])
               swap(v[i], v[right]);
       }

   }
}