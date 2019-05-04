#include <iostream>

using namespace std;

int main (void) {
    int n;
    int v[25], c;
    int sum = 0;

    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    for (int i=0; i<n; i++) {
        cin >> c;
        if (v[i] - c > 0) {
           sum += v[i] - c;
        }
        // sum += (v[i]-c>0) ? v[i]-c : 0;
    }

    cout << sum << endl;
}