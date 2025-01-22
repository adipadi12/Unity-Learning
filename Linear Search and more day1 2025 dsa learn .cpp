#include <iostream>
using namespace std;
#include <vector>
#include <Bits.h>

void linear_search() {
	vector<int> arr = { 9, 6, 7, 23, 6 };
	int num = 23;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == num) {
			cout << i;
		}
	}
	cout << -1;
}

vector < int > unionOf2SortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    int n1 = a.size();
    int n2 = b.size();
    int i = 0; //for traversing through a
    int j = 0; //for traversing through b
    vector<int> unionArr;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            if (unionArr.size() == 0 ||
                unionArr.back() != a[i]) { // if size of union array is 0 i.e.
                // beginning of iteration or
// last element is not same as the element that is about to be
// pushed in the union array
                unionArr.push_back(a[i]);
            }
            i++; //incrementing i pointer
        }
        else {
            if (unionArr.size() == 0 || unionArr.back() != b[j]) {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    while (j < n2) {
        if (unionArr.size() == 0 || unionArr.back() != b[j]) {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    while (i < n1) {
        if (unionArr.size() == 0 ||
            unionArr.back() != a[i]) { // if size of union array is 0 i.e.
            // beginning of iteration or
// last element is not same as the element that is about to be
// pushed in the union array
            unionArr.push_back(a[i]);
        }
        i++;
    }

    return unionArr;
}


vector<int> find2SortedArrayIntersection(vector<int>& A, int n, vector<int>& B, int m)
{
    // Write your code here.
    int i = 0;
    int j = 0; //2 pointer optimal solution
    vector<int> ans;
    while (i < n && j < m) {  //iterating through both arrays
        if (A[i] < B[j]) {
            i++;
        }
        else if (B[j] < A[i]) { //ruling out all inequalities
            j++;
        }
        else { //when equal
            ans.push_back(A[i]); //push from 1st array
            i++;
            j++;
        }
    }
    return ans;
}

int main() {
	//linear_search();

}