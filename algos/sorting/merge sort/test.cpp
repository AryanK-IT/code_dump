#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    // The optimal solution is to find a window of size n where
    // we can arrange the ducks consecutively with minimal moves
    long long min_moves = LLONG_MAX;
    for (int i = 0; i + n <= arr.size(); ++i) {
        // The target positions will be arr[i]+0, arr[i]+1, ..., arr[i]+n-1
        long long moves = 0;
        for (int j = 0; j < n; ++j) {
            moves += abs(arr[i + j] - (arr[i] + j));
        }
        min_moves = min(min_moves, moves);
    }

    cout << min_moves << '\n';
    return 0;
}