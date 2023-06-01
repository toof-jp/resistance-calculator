#include <iostream>
#include <vector>

int main() {
  constexpr int N = 3;
  std::vector<double> registances(N);
  for (int i = 0; i < N; i++) {
    std::cout << "R" << i << ": ";
    std::cin >> registances[i];
  }

  double lower_limit, upper_limit;
  std::cout << "lower limit: ";
  std::cin >> lower_limit;
  std::cout << "upper limit: ";
  std::cin >> upper_limit;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < N; k++) {
        if (i == j or j == k or k == i) continue;

        for (int cond1 = 0; cond1 < 2; cond1++) {
          for (int cond2 = 0; cond2 < 2; cond2++) {
            double r_temp;
            if (cond1 == 0) { // series connection
              r_temp = registances[i] + registances[j];
            } else { // parallel connection
              r_temp = registances[i] * registances[j] / (registances[i] + registances[j]);
            }

            double r;
            if (cond2 == 0) { // series connection
              r = r_temp + registances[k];
            } else { // parallel connection
              r = r_temp * registances[k] / (r_temp + registances[k]);
            }

            if (lower_limit <= r and r <= upper_limit) {
              std::cout << "R = " << r << "[ohm]\n";

              std::cout << (cond2 ? "parallel" : "series") << "(";
              std::cout << (cond1 ? "parallel" : "series") << "(";
              std::cout << "R" << i << " = " << registances[i] << "[ohm]";
              std::cout << ", ";
              std::cout << "R" << j << " = " << registances[j] << "[ohm]";
              std::cout << "), ";
              std::cout << "R" << k << " = " << registances[k] << "[ohm]";
              std::cout << ")\n\n";
            }
          }
        }
      }
    }
  }
}
