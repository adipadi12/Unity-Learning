#include <iostream>
#include <vector>
using namespace std;

//to find largest number in an array
int largestNumInArr(vector<int>& arr, int n) {
	int largest = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > largest)
		{
			largest = arr[i];
		}
	}
	return largest;
}

//to find second largest and second smallest number in array
int secondLargest(vector<int>& arr, int n) {
	int largest = arr[0];
	int s_largest = -1;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > largest) {
			s_largest = largest; //if largest isn't the largest then it becomes second largest
			largest = arr[i]; //new largest defined
		}
		else if (arr[i] < largest && arr[i] > s_largest) {
		
			s_largest = arr[i]; //in case a number is less than the largest but smaller than second largest have tp replace that
		}
	}
	return s_largest;
}

int secondSmallest(vector<int>& arr, int n) {
	int smallest = arr[0];
	int s_smallest = INT_MAX;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < smallest) {
			s_smallest = smallest;
			smallest = arr[i];
		}
		else if (arr[i] != smallest && arr[i] < s_smallest) { //checking if duplicates present or not. 
			s_smallest = arr[i]; //if number is not largest but smaller than second smallest it is then substituted
		}
	}
	return s_smallest;
}
//checking if array is sorted or not
int isSorted(vector<int>& arr, int n) {
	for (int i = 1; i < n; i++)
	{
		if (arr[i] >= arr[i - 1]) { //checking if element before is greater or equal to than element after

		}
		else
		{
			return 0;
		}
	}
	return 1;
}

//for removing duplicates from a sorted array

int removeDuplicates(vector<int>& arr, int n) {
	int index = 0;
	for (int j = 1; j < n; j++)
	{
		if (arr[index] != arr[j]) {
			arr[index + 1] = arr[j];
			index++;
		}
	}
	return index + 1;
}

int main() {
	vector<int> arr = { 1,1,2,2,4,4,4,6,6,6,6 };
	int n = arr.size();
	//cout << secondLargest(arr, n) << " " << secondSmallest(arr, n);
	//cout << isSorted(arr, n);
	cout << removeDuplicates(arr, n);
}