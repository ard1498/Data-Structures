#include<iostream>

using namespace std;

int isavail(int i, int j, int arr[4][4], int n) {
	if (arr[i][j] == 1 && i<n && j<n && i >= 0 && j >= 0)
		return 1;
	else
		return 0;
}

int path(int sol[4][4], int i, int j, int arr[4][4], int n) {
	if (i == n - 1 && j == n - 1) {
		sol[i][j] = 1;
		return 1;
	}

	if (isavail(i, j, arr, n)==1) {
		sol[i][j] = 1;
		if (path(sol, i + 1, j, arr, n)==1)
			return 1;
		else if (path(sol, i, j + 1, arr, n)==1)
			return 1;
		else
			sol[i][j] = 0;
		//	return false;
	}

	return 0;
}

void findpath(int arr[4][4], int n) {
	int sol[4][4]={0};
	if (path(sol, 0, 0, arr, n) == 0) {
		cout << "\nno path possible.";
		return;
	}
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++)
			cout << sol[i][j] << "\t";
		cout << "\n";
	}
	return;
}

int main() {
	int n;
	cout << "\nenter the size of your matrix:";
	cin >> n;
	int arr[4][4];

	for (int k = 0; k < n; k++)
		for (int l = 0; l < n; l++)
			cin >> arr[k][l];

	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n; j++)
			cout << arr[i][j] << "\t";
		cout << "\n";
	}
	findpath(arr, n);
	return 0;
}
