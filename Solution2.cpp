#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_steal_amount(const vector<int>& hval) {
    int n = hval.size();

    // Handle edge cases
    if (n == 0) return 0;
    if (n == 1) return hval[0];
    if (n == 2) return max(hval[0], hval[1]);

    // DP array to store the maximum money that can be stolen up to each house
    vector<int> dp(n);

    // Base cases
    dp[0] = hval[0];
    dp[1] = max(hval[0], hval[1]);

    // Fill the DP array
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], hval[i] + dp[i - 2]);
    }

    return dp[n - 1];  // Return the maximum money that can be stolen
}

int main() {
    int n;
    cout << "Enter the number of houses: ";
    cin >> n;

    vector<int> hval;
    cout << "Enter the values of each house: ";
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        if (value >= 0) {  // Only add non-negative values
            hval.push_back(value);
        }
    }

    if (hval.empty()) {
        cout << "No valid house value." << endl;
    }
    else {
        cout << "Max money that can be stolen: " << max_steal_amount(hval) << endl;
    }

    return 0;
}
