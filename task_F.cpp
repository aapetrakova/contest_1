#include <iostream>
#include <vector>

const int kNum1 = 123;
const int kNum2 = 45;
const int kNum3 = 10000000;
const int kNum4 = 4321;
int Partition(std::vector<int>& vec, int left, int right) {
  int pivot = vec[right];
  int p_id = left;
  for (int j = left; j <= right - 1; j++) {
    if (vec[j] <= pivot) {
      std::swap(vec[p_id], vec[j]);
      p_id++;
    }
  }
  std::swap(vec[p_id], vec[right]);
  return p_id;
};

int KTh(std::vector<int>& vec, int left, int right, int k_n) {
  if (k_n > 0 && k_n <= right - left + 1) {
    int pivot = Partition(vec, left, right);
    if (pivot - left == k_n - 1) {
      return vec[pivot];
    }
    if (pivot - left > k_n - 1) {
      return KTh(vec, left, pivot - 1, k_n);
    }
    return KTh(vec, pivot + 1, right, k_n - pivot + left - 1);
  }
  return -1;
};

void NewVec(std::vector<int>& vec, int q_of_elems) {
  for (int i = 2; i < q_of_elems; i++) {
    vec[i] = (vec[i - 1] * kNum1 + vec[i - 2] * kNum2) % (kNum3 + kNum4);
  }
};

int main() {
  int num;
  int k_num;
  int a_zero;
  int a_first;
  std::cin >> num >> k_num >> a_zero >> a_first;
  std::vector<int> subsequence(num);
  subsequence[0] = a_zero;
  subsequence[1] = a_first;
  NewVec(subsequence, num);
  std::cout << KTh(subsequence, 0, num - 1, k_num);
}
