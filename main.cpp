#include  <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <stack>

using namespace std;
inline void cpu_relax() {
#if defined(__aarch64__)
  asm volatile("yield" ::: "memory");
#else
  asm volatile("rep; nop" ::: "memory");
#endif
}
struct A {
  enum type {
    AAAA,
    BBBB,
  };
};

class Soulution {
 public:
  std::vector<std::vector<int>> res;
  std::vector<int> path;

  std::vector<std::vector<int>> premute (std::vector<int>& nums) {
    res.clear();
    path.clear();
    std::vector<bool> used(nums.size(), false);
    backtrack(nums, used);
    return res;

  }

  void backtrack(std::vector<int>& nums, std::vector<bool>& used) {
    if (path.size() == nums.size()) {
      res.push_back(path);
      return;
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (used[i] == true) continue;
      used[i] = true;
      path.push_back(nums[i]);
      backtrack(nums, used);
      path.pop_back();
      used[i] = false;
    }
  }

};


class Solution2 {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    do {
      res.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    return res;
  }
};

class Soulution3 {
 public:
  bool isValid(std::string s) {
    int n = s.size();
    if (n % 2 == 1) {
      return false;
    }
    std::unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    std::stack<char> stk;

    for (char ch : s) {
      if (pairs.count(ch)) {
        if (stk.empty() || stk.top() != pairs[ch]) {
          return false;
        }
        stk.pop();
      } else {
        stk.push(ch);
      }
    }
    return stk.empty();
  }
};

class Soulution4 {
 public:
  int removeDuplicates(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    int fast = 1, slow = 1;

    while (fast < n) {
      if (nums[fast] != nums[fast -1]) {
        nums[slow] = nums[fast];
        ++slow;
      }
      ++fast;
    }
    return slow;
  }
};
#include <mutex>
#include <shared_mutex>
#include <memory>


















































enum  ThreshHold : ::uint32_t {
  NUMBER_1 = 0,
  NUMBER_2 = 0 << 1,
};

static constexpr ::uint32_t t1= 0;
static constexpr size_t t2= 0;

#define FUCK_THRESH std::uint32_t(0)

int main() {
  ::uint32_t my_value = 0;

  if (my_value == ThreshHold::NUMBER_1) {
    std::cout << "fuck yes" << std::endl;
  }

  if (my_value == t1) {
    std::cout << "fuck yes too" << std::endl;
  }

  if (my_value == static_cast<::uint32_t>(t2)) {
    std::cout << "fuck yes three" << std::endl;
  }

  if (my_value == (std::uint32_t)t2) {
    std::cout << "fuck yes four" << std::endl;
  }

  return 0;
}
