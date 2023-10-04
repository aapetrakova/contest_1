#include <stdio.h>

#include <iostream>
#include <valarray>
#include <vector>

int main() {
  int mandrakes;
  std::cin >> mandrakes;
  std::vector<double> volume(mandrakes);
  std::vector<double> prefix_log_sum(mandrakes + 1);
  for (int i = 0; i < mandrakes; i++) {
    std::cin >> volume[i];
  }
  prefix_log_sum[0] = std::log2(1);
  prefix_log_sum[1] = std::log2(volume[0]);
  for (int i = 2; i <= mandrakes; i++) {
    prefix_log_sum[i] = prefix_log_sum[i - 1] + std::log2(volume[i - 1]);
  }
  int request;
  std::cin >> request;
  int left;
  int right;
  for (int i = 0; i < request; i++) {
    std::cin >> left >> right;
    printf("%.6f", exp2((prefix_log_sum[right + 1] - prefix_log_sum[left]) /
                        (right - left + 1)));
    std::cout << std::endl;
  }
}
