#include <iostream>
using namespace std;
#include <vector>

int missingNumberBruteForce(vector<int>& a, int N) {
    // Write your code here.
    for (int i = 1; i <= N; i++) { //iterating counting wise till N
        int flag = 0; //setting flag for each number iteration while iterating through array
        for (int j = 0; j < N - 1; j++) { //iterating through the array
            if (a[j] == i) { //checking if array index value same as counting iteration till N
                flag = 1; //storing as non missing
                break;
            }
        }
        if (flag == 0) {
            cout << i; //missing element returned from i where flag = 0
        }
    }
    return 0;
}

int missingNumberBetterUsingHashmap(vector<int>& a, int N) {
    // Write your code here.
    int hash[N + 1] = { 0 };
    for (int i = 0; i < N - 1; i++) {
        hash[a[i]] = 1;
    }
    for (int i = 1; i < N; i++) {
        if (hash[i] == 0) {
            return i;
        }
    }
}

int missingNumberOptimalSum(vector<int>& a, int N) {
    // Write your code here.
    int sum = (N * (N + 1)) / 2; //sum of numbers formula
    int sum2 = 0; //another int as sum2
    for (int i = 0; i < N - 1; i++) {
        sum2 += a[i]; //iterating through the array and adding the elements to sum2

    }
    return (sum - sum2); //subtracting sum and sum2 we get the missing value
}

int consecutiveOnes(vector<int>& arr) {
    //Write your code here.
    int maxi = 0;
    int cnt = 0; //max and count 2 ints
    for (int i = 0; i < arr.size(); i++) { //traversing through array
        if (arr[i] == 1) { //checking if arr[i] = 1
            cnt++; //incrementing counter
            maxi = max(maxi, cnt); //making maxi the maximum from the counter and prev value of maxi to keep it updated every for loop
        }
        else {
            cnt = 0; //if match not found reset counter to 0
        }

    }
    return maxi; //maxi returned as answer
}

int missingNumberOptimalXOR(vector<int>& a, int N) {
    // Write your code here.
    int xor1 = 0;
    int xor2 = 0; //making 2 xor ints
    for (int i = 0; i < N - 1; i++) { //traversing through array
        xor2 = xor2 ^ a[i]; //xoring through traversing through array iteration
        xor1 = xor1 ^ (i + 1); //xoring through counting iteration
    }
    xor1 = xor1 ^ N; // for making complexity O(N)
    return xor1 ^ xor2; //xoring xor 1 and xor2 gives the missing element in return
}


int getSingleElementBruteForce(vector<int>& arr) {
    // Write your code here.	
    for (int i = 0; i < arr.size(); i++) { //iterating through loop
        int num = arr[i]; //num being an element of the array
        int count = 0; //count being occurences
        for (int j = 0; j < arr.size(); j++) { //iterating through array to check equals
            if (arr[j] == num) { //checking if array in sub loop same as num
                count++; //increasing count if the number we're checking for and the value in array is same
            }
        }
        if (count == 1) {//post that loop we check the counts of num the one that has 1 is the only occurence
            return num;
        }
    }
}

int getSingleElementBetterHashmap(vector<int>& arr) {
    // Write your code here.	
    int maxi = arr[0];
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }
    int hash[maxi + 1] = { 0 };
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] == 1) {
            return arr[i];
        }
    }
}

#include<vector>
#include <unordered_map>
int getSingleElementBetterUnorderedMap(vector<int>& arr) {
    // Write your code here.	
    int n = arr.size();

    unordered_map<long, int> mpp;
    for (int num : arr) { //adding array values to map
        mpp[num]++;
    }
    for (auto it : mpp) {
        if (it.second == 1) { //checking for count of the same
            return it.first; //returning the number if count is only once
        }
    }
    return -1;
}

int getSingleElementOptimal(vector<int>& arr) {
    // Write your code here.	

    int xor1 = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        xor1 = xor1 ^ arr[i]; //xoring through all members in the array everything becomes 0 except the one occurence eg; 0^2^0
    }
    return xor1;
}

int main() {
    vector<int> arr = { 1,2,3,4,5,6,8 };
    int N = 8;
    missingNumberBruteForce(arr, N);
}