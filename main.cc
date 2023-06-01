#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<double> registers(n);
  for (int i = 0; i < n; i++) {
    std::cin >> registers[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (i == j or j == k or k == i) break;
        for (int cond1 = 0; cond1 < 2; cond1++) {
          for (int cond2 = 0; cond2 < 2; cond2++) {
            double tmp;
            if (cond1 == 0) {
              tmp = registers[i] + registers[j];
            } else {
              tmp = registers[i] * registers[j] / (registers[i] + registers[j]);
            }

            double r;
            if (cond2 == 0) {
              r = tmp + registers[k];
            } else {
              r = tmp * registers[k] / (tmp + registers[k]);
            }

            if (600 <= r and r <= 700) {
              std::cout << "r: " << r << "| " << i << " " << j << " " << k << " " << cond1 << " " << cond2 << std::endl;
            }
          }
        }
      }
    }
  }
}
