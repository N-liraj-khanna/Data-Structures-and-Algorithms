/*****************K Lagest Elements Main***************************/
// TC => O(n) SC => O(K)
vector<int> kLargest(int arr[], int n, int k) {
	priority_queue <int, vector<int>, greater<int>> pq;

	for (int i = 0; i < k; i++)
		pq.push(arr[i]);
	for (int i = k; i < n; i++) {
		if (pq.top() < arr[i]) {
			pq.pop();
			pq.push(arr[i]);
		}
	}
	vector<int> v(k);
	for (int i = k - 1; i >= 0; i--) {
		v[i] = pq.top();
		pq.pop();
	}
	return v;
}