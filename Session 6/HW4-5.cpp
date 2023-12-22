#include <iostream>
#include <cstring>

int main() {
    int n, m;
    std::cin >> n >> m;

    int truthCount[n + 1];
    int lieCount[n + 1];
    memset(truthCount, 0, sizeof(truthCount));
    memset(lieCount, 0, sizeof(lieCount));

    for (int i = 0; i < n; ++i) {
        std::string statement;
        std::cin >> statement;

        for (int j = 0; j < statement.size(); ++j) {
            if (statement[j] == '+') {
                truthCount[j + 1]++;
            } else {
                lieCount[j + 1]++;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (truthCount[i] + lieCount[i] == m || (truthCount[i] == 0 && lieCount[i] == 0)) {
            std::cout << "Not defined" << std::endl;
        } else if (truthCount[i] == m) {
            std::cout << "Truth" << std::endl;
        } else {
            std::cout << "Lie" << std::endl;
        }
    }

    return 0;
}
