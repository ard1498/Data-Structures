//max t-heap
#include<iostream>
#include<vector>

using namespace std;

class theap {
	int k;
	vector<int> heap;
public:

	theap(int k) {
		this->k = k;
	}

	void insertion(int item) {
		heap.push_back(item);
		heapifyup(heap.size() - 1);
		return;
	}

	void heapifyup(int i) {
		if (i<0) {
			return;
		}
		int par = (i - 1) / k;
		if (heap[par] < heap[i]) {
			swap(heap[par], heap[i]);
			heapifyup(par);
		}
		return;
	}

	int search(int item, int index) {
		if (item > heap[index]) {
			return -1;
		}
		else if (item == heap[index]) {
			return index;
		}
		else {
			for (int i = 1; i <= k; i++) {
				if ((k*index + i) > heap.size()) {
					return -1;
				}
				if (search(item, (k*index + i)) > -1)
					return search(item, (k*index + i));
			}
			return -1;
		}
	}

	void display() {
		cout << "\n";
		for (int i = 0; i < heap.size(); i++) {
			cout << heap[i] << "\t";
		}
	}

	void deletion(int item) {
		int pos = search(item, 0);
		if (pos == -1) {
			cout << "\nitem not found.\n";
			return;
		}
		heap[pos] = heap[heap.size() - 1];
		heap.pop_back();
		heapifydown(pos);
	}

	void heapifydown(int pos) {
		if ((k*pos + 1) > heap.size()) {
			return;
		}
		int ptr = k*pos + 1;
		for (int i = 2; i <= k; i++) {
			int j = k*pos + i;
			if (j < heap.size()) {
				if (heap[j] > heap[ptr]) {
					ptr = j;
				}
			}
		}
		if (heap[ptr] > heap[pos]) {
			swap(heap[ptr], heap[pos]);
			heapifydown(ptr);
		}
		return;
	}

	void heapsort() {
		vector<int> arr;
		while (!heap.empty()) {
			arr.push_back(heap[0]);
			deletion(heap[0]);
		}
		cout << "\n";
		for (int i = 0; i<arr.size(); i++) {
			cout << arr[i] << "\t";
		}
	}

};

int main() {
	theap h1(2);

	h1.insertion(10);
	h1.insertion(7);
	h1.insertion(9);
	h1.insertion(8);
	h1.insertion(4);
	h1.insertion(5);
	h1.display();

	h1.insertion(11);
	h1.display();

	h1.insertion(6);
	h1.display();

	h1.deletion(11);
	h1.display();

	h1.heapsort();

	system("pause");
	return 0;
}