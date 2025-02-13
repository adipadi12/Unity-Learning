int search(vector<int>& arr, int n, int target)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) return mid;

        //left sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= target && target <= arr[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        //right sorted
        else {
            if (arr[mid] <= target && target <= arr[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

    }
    return -1;
}

bool searchInARotatedSortedArrayII(vector<int>& arr, int target) {
    // Write your code here.
    int n = arr.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) return true;

        //edge case 
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low++;
            high--;
            continue;
        }

        //left sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= target && target <= arr[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        //right sorted
        else {
            if (arr[mid] <= target && target <= arr[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

    }
    return false;
}

bool searchInARotatedSortedArrayII(vector<int>& A, int key) {
    // Write your code here.
    int n = A.size();
    int l = 0, h = n - 1;
    while (l <= h) {
        int mid = (l + h) / 2;
        if (A[mid] == key) {
            return true;
        }

        if (A[l] == A[mid] && A[mid] == A[h]) {
            l = l + 1;
            h = h - 1;
            continue;
        }
        if (A[l] <= A[mid]) {
            if (key >= A[l] && key <= A[mid]) {
                h = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        else {
            if (key >= A[mid] && key <= A[h]) {
                l = mid + 1;
            }
            else {
                h = mid - 1;
            }
        }
    }


    return false;
}
