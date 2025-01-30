#include <iostream>
#include <vector>
using namespace std;


int bSearch(vector<int>arr, int n, int target) {
	int low = 0, high = n - 1; 
	while (low <=high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] == target) return mid;
		else if (target > arr[mid]) low = mid + 1;
		else high = mid - 1;
	}
	return -1;
}

int bSearchRecursive(vector<int> arr, int low, int high, int target) {
	if (low > high) return -1;
	int mid = (low + high) / 2;
	if (arr[mid] == target) {
		return mid;
	}
	else if (target > arr[mid]) {
		return bSearchRecursive(arr, mid + 1, high, target);
	}
	return bSearchRecursive(arr, mid - 1, high, target);
}