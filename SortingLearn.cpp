#include <iostream>
#include <vector>
using namespace std;

void selection_sort(vector<int>& arr, int n) {
	for (int i = 0; i <= n-2; i++) // taking n-2 because we have to swap till index n-2
	{
		int mini = i;
		for (int j = i; j <= n - 1; j++)
		{
			if (arr[j] < arr[mini]) { //checking if values are smaller so swap is needed or not
				mini = j;
			}
		}
		int temp = arr[mini]; //adding a 3rd variable for swapping functionality
		arr[mini] = arr[i];
		arr[i] = temp;
	}
}

int main() {
	int n;
	cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	selection_sort(arr, n); //sorting the array after receiving input and printing it out
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}