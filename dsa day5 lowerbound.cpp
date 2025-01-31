#include <iostream>
#include <vector>
using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int low = 0, high = n - 1;
	int ans = n;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] >= x) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}

int findFloorGFG(vector<int>& arr, int k) {

	// Your code here
	int n = arr.size();
	int lb = lower_bound(arr.begin(), arr.end(), k) - arr.begin();
	// If the first element is greater than k, no floor exists
	if (lb == 0 && arr[lb] > k) return -1;

	// If lb is within bounds and exactly equal to k
	if (lb < n && arr[lb] == k) return lb;

	// Otherwise, return the previous index as floor
	return lb - 1;
}

int upperBound(vector<int>& arr, int x, int n) {
	// Write your code here.
	int low = 0, high = n - 1;
	int ans = n;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] > x) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}

int searchInsert(vector<int>& arr, int x)
{
	// Write your code here.
	int n = arr.size();
	int low = 0, high = n - 1;
	int ans = n;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] >= x) {
			ans = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return ans;
}

pair<int, int> getFloorAndCeil(vector<int>& arr, int n, int x) {
	// Write your code here.

	int low = 0, high = n - 1;
	int floor = -1, ceil = -1;

	//for floor
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] <= x) {
			floor = arr[mid];
			low = mid + 1;
		}
		else high = mid - 1;
	}

	low = 0, high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] >= x) {
			ceil = arr[mid];
			high = mid - 1;
		}
		else low = mid + 1;
	}

	return { floor, ceil };
}