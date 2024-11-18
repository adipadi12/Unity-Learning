#include <iostream>
#include <vector>
using namespace std;

int partition_index(vector<int>& arr, int low, int high) {
	int pivot = arr[low];
	int i = low;
	int j = high;
	while (i < j)
	{
		while (arr[i] <= pivot && i <= high - 1) {
			i++;
		}
		while (arr[j] > pivot && j >= low + 1) {
			j--;
		}
		if (i < j) {
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	int temp1 = arr[j];
	arr[j] = arr[low];
	arr[low] = temp1;
	return j;
}

void qs(vector<int>& arr, int low, int high) {
	if (low < high)
	{
		int partition = partition_index(arr, low, high);
		qs(arr, low, partition - 1);
		qs(arr, partition + 1, high);
	}
	
}
int main() {
	vector<int> arr = { 5, 2, 34, 67, 89, 12, 23, 41 };
	qs(arr, 0, arr.size() - 1);

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}