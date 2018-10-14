//max heap and heapsort......

#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

class heapme {
	int temp, n;
	vector<int> heap;
public:
	heapme() {
		heap.push_back(INT_MAX);
		n = 0;
	}

	void insertion(int item) {
		heap.push_back(item);
		n++;
		heapifyup(n);
	}

	void heapifyup(int k) {
		if (k>0) {
			if (heap[k] > heap[k/2]) {
				temp = heap[k];
				heap[k] = heap[k/2];
				heap[k/2] = temp;
				heapifyup(k/2);
			}
		}
		return;
	}

	int search(int item) {
		for (int i = 1; i <= n; i++) {
			if (item == heap[i])
				return i;
		}
		return 0;
	}

	void deletion(int item) {
		int pos = search(item);
		if (pos != 0) {
			heap[pos] = heap[n];
			n--;
			heapifydown(pos);
		}
		else
			cout << "\nelement not present!!!";
		return;
	}

	void heapifydown(int i) {
		int left = 2 * i, right = 2 * i + 1, ptr;
		if (left <= n) {
			if (heap[right] > heap[left] && right <= n)
				ptr = right;
			else if (heap[right] > heap[left] && right <= n)
				ptr = left;
			else
				ptr = left;

			if (heap[i] < heap[ptr]) {
				temp = heap[i];
				heap[i] = heap[ptr];
				heap[ptr] = temp;
				heapifydown(ptr);
			}
			return;
		}
	}

	void display() {
		for (int i = 1; i <= n; i++) {
			cout << heap[i] << "\t";
		}
		cout << "\n";
	}

	void heapsort(vector<int>& arr) {
		for (int i = 0; i <arr.size(); i++) {
			insertion(arr[i]);
		}
	
		int j = n;
		while (j>0) {
			arr[j - 1] = heap[1];
			deletion(heap[1]);
			j--;
		}
		
	}
};

int main() {
	int i;
	heapme h1;
	vector<int> arr;
	int ch = 1;
	while (ch == 1) {
		cout << "\nenter the element:";
		cin >> i;
		arr.push_back(i);
		cout << "\nwant to enter more:(1/0):";
		cin >> ch;
	}
	
	h1.heapsort(arr);
	for (int i = 0; i < arr.size(); i++) {
		cout << (arr[i]) << "\t";
	}
	cin >> i;
	return 0;
}