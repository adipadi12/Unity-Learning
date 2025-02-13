class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n - 1, ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (arr[low] <= arr[high]) { //if sorted then for that edge case
                ans = min(ans, arr[low]);
                break;
            }

            if (arr[low] <= arr[mid]) { //if left side is sorted
                ans = min(ans, arr[low]);
                low = mid + 1;
            }

            else { //if right side is sorted
                ans = min(ans, arr[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};


#include <bits/stdc++.h>
int findKRotation(vector<int>& arr) {
    // Write your code here.    

    int n = arr.size();
    int low = 0, high = n - 1, ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[low] <= arr[high]) { //if sorted then for that edge case
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }

        if (arr[low] <= arr[mid]) { //if left side is sorted
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            low = mid + 1;
        }

        else { //if right side is sorted
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }
            high = mid - 1;
        }
    }
    return index;
}