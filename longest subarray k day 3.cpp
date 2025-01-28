int longestSubarrayWithSumKBruteForce(vector<int> a, long long k) {
    // Write your code here
    int n = a.size();
    int len = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) { //generating all subarrays and checking if their sum is equal to k according to that ajusting len
            sum += a[j];
            if (sum == k) {
                len = max(len, j - i + 1);
            }
        }

    }
    return len;
} // o(n2) TC

int longestSubarrayWithSumKUsingHashmap(vector<int> a, long long k) {
    // Write your code here
    map<long long, int> preSumMap; //hashamp initialized
    long long sum = 0; //sum storing 
    int maxLen = 0; //maxlen
    int n = a.size();
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum == k) {
            maxLen = max(maxLen, i + 1); //iterating through the array a and adding elements to sum
            //then checking for sum == k and if it is altering value of max len by 0, i+1 i.e the current index
        }
        long long rem = sum - k; //remainder = sum - k for reverse engineering and checking for subarray with sum k
        if (preSumMap.find(rem) != preSumMap.end()) { //checking if remainder found in the map is the last one in the map or not
            int len = i - preSumMap[rem]; //making length = index - whats there on the rem index of preSumMap
            maxLen = max(maxLen, len); //altering max len then accordingly
        }
        if (preSumMap.find(sum) == preSumMap.end()) { //contingency for zeros so sum that is found if it is the last index on the hashmap
            preSumMap[sum] = i; //then altering that particular index into i
        }

    }
    return maxLen;
}

int longestSubarrayWithSumKOptimal2PointerApproach(vector<int> a, long long k) {
    int left = 0, right = 0;
    int n = a.size();
    int maxLen = 0;
    long long sum = a[0]; //initializing sum as first element of array
    while (right < n) { //2 pointer aproach
        while (sum > k && left <= right) { //while sum is greater than k remove one element from left pointer in sum
            sum -= a[left];
            left++; //and move pointer ahead by 1
        }
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1); //if sum == k  we check if maxLen can be altered. new subarrays length is found and 
            //if that is greater than prev value of maxLen we alter
        }
        right++; //move right pointer ahead first
        if (right < n) { //then if it is still bound in lenght of array
            sum += a[right]; //we add that element to sum
        }
    }
    return maxLen;
}