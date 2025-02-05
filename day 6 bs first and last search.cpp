------------leetcode brute force------------ -
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1, last = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        return { first, last };
    }
};

------------ - leet code using lb ub------------
#include <bits/stdc++.h>
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if ((lb == n) || (nums[lb] != target)) {
            return { -1, -1 };
        }
        return { lb, ub - 1 };
    }
};

----------------leetcode using raw binary search-------------- -
#include <bits/stdc++.h>
class Solution {
public:
    int firstElement(vector<int>& arr, int n, int x) {
        int first = -1;
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == x) {
                first = mid;
                high = mid - 1;
            }
            else if (arr[mid] < x) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return first;
    }
    int lastElement(vector<int>& arr, int n, int x) {
        int last = -1;
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] == x) {
                last = mid;
                low = mid + 1; //eliminate left search space
            }
            else if (arr[mid] < x) {
                low = mid + 1; //eliminate left search space again if element is smaller than target
            }
            else {
                high = mid - 1; //eliminate right search space when element is bgger than target
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int f = firstElement(nums, n, target);
        if (f == -1) return { -1,-1 };
        int l = lastElement(nums, n, target);
        return { f,l };
    }
};


//count element in sorted array
int firstElement(vector<int>& arr, int n, int x) {
    int first = -1;
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return first;
}

int lastElement(vector<int>& arr, int n, int x) {
    int last = -1;
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == x) {
            last = mid;
            low = mid + 1; //eliminate left search space
        }
        else if (arr[mid] < x) {
            low = mid + 1; //eliminate left search space again if element is smaller than target
        }
        else {
            high = mid - 1; //eliminate right search space when element is bgger than target
        }
    }
    return last;
}
int count(vector<int>& arr, int n, int x) {
    // Write Your Code Here
    int f = firstElement(arr, n, x);
    if (f == -1) return 0;
    int l = lastElement(arr, n, x);
    return l - f + 1;
}
