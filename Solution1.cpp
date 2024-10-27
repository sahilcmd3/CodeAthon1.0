#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Seat count
    int N;
    cin >> N;

    // Way of sitting
    string seats;
    cin >> seats;

    vector<int> occupied;

    // Positions of occupied seats
    for (int i = 0; i < N; i++) {
        if (seats[i] == 'O') {
            occupied.push_back(i);
        }
    }

    int m = occupied.size();

    // If there are no occupied seats or only one person, no movement is needed
    if (m == 0 || m == 1) {
        cout << "0\n1" << endl;
        return 0;
    }

    // Median position
    int medianIndex = m / 2;
    int medianPos = occupied[medianIndex];

    // Minimum number of movements
    int minMovements = 0;
    for (int i = 0; i < m; i++) {
        // Movement required to align to consecutive seats
        minMovements += abs(occupied[i] - (medianPos - (medianIndex - i)));
    }

    // The number of ways is always 1 since this is a specific arrangement
    int ways = 1;

    // Output the minimum movements and the number of ways
    cout << minMovements << "\n" << ways << endl;

    return 0;
}

