#include <vector>
#include <iostream>
using namespace std;

vector<int> rotateArrayLeftOnce(vector<int>& arr, int n) {
    // Write your code here.
    int temp = arr[0]; //storing the first element in temp
    for (int i = 1; i < n; i++) {
        arr[i - 1] = arr[i]; //making every other element 1 decrement
    }
    arr[n - 1] = temp; //making last element of array the first one
    return arr;
}

void rotateRightKPlaces(vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums.begin(), nums.end() - k);
    reverse(nums.end() - k, nums.end());
    reverse(nums.begin(), nums.end());

}

vector<int> shiftingArrayLeftBruteForce(vector<int>arr, int d, int n) {
    d = d % n;  //define a function and modulus of n because after d rotations array becomes the same again
    vector<int> temp(d);  //temp array to store elements to be rotated to end

    for (int i = 0; i < d; i++) {
        temp[i] = arr[i];  //adding them to temp array
    }

    for (int i = d; i < n; i++) {
        arr[i - d] = arr[i];  //shifting elements in original array by d 
    }

    for (int i = n - d; i < n; i++) {
        arr[i] = temp[i - (n - d)];  //adding elements from temp array to the original array
    }

    return arr; //return the array
}

vector<int> shiftingArrayLeftKplacesOptimal(vector<int> arr, int d) {
    reverse(arr.begin(), arr.begin() + d);   //reversing first d elements of array
    reverse(arr.begin() + d, arr.end());   //reversing d to end elements
    reverse(arr.begin(), arr.end());  //reversing the entire array post reversal

    return arr;
}

vector<int> movingZerosAtEndOfArrayBruteForce(vector<int> arr, int n) {
    vector<int> temp(n); //taking a temp array

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            temp[j] = arr[i];  //storing non zero elements in temp
            j++;
        }
    }
    int x = temp.size();
    for (int i = 0; i < x; i++) {
        arr[i] = temp[i];   //adding those elements of temp to front of original array
    }

    for (int i = x; i < n; i++) {
        arr[i] = 0;  //making the rest of the elements 0
    }

    return arr;
}


void moveZeroesAtEndOptimal(vector<int>& nums) {
    int n = nums.size();

    int j = -1;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            j = i;
            break;
        }
    }

    if (j == -1) return;

    for (int i = j + 1; i < n; i++) {
        if (nums[i] != 0) {
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            j++;
        }
    }
}

int main() {
    vector<int> arr = { 1,23,4,5,6 };
    int n = arr.size();

    arr = rotateArrayLeftOnce(arr, n);
    for (int num : arr)
    {
        cout << num << " ";
    }
}