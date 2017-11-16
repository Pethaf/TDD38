#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

int main()
{
  int N, T;
  std::cin >> N >> T;
  std::vector<int> input_values(N);
  copy_n(istream_iterator<int>{cin}, N, begin(input_values));
  std::vector<int> sums(N);
  partial_sum(begin(input_values), end(input_values), begin(sums));
  for_each(istream_iterator<int>{cin}, istream_iterator<int>{},
            [=](int t){cout << sums[t-1] << endl; });
}
