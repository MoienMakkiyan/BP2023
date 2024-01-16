#include <iostream>

using namespace std;

int main() {
    int n, k = 1;
    cin >> n;
    int matrix[n][n];
    for (int j = n - 1; j >= 0; j--)
        for (int i = 0; i < n; i++) {
            matrix[i][j] = k;
            k += 2;
        }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }


    return 0;
}
