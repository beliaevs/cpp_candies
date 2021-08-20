#include"../pretty_print/ContainerFormatter.h"

#include<iostream>
#include<ostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<deque>
#include<algorithm>
#include<string>
#include<string_view>

int main()
{
  std::vector<int> v = { 1,4,2,5,3,8,4,8,4,1,7,3,6,0,7,4,8,5,1,8,4,8,2,5 };
  std::map<int, int> m = { {1, 2}, {4, 1}, {2, 4} };
  std::unordered_map<int, int> um = { {3,1}, {7,1}, {8, 2} };
  std::cout << SeqFormatter(v) << "\n";
  
  std::sort(v.begin(), v.end());
  std::cout << SeqFormatter(v) << "\n";
  std::cout << DictFormatter(m) << "\n";
  std::cout << DictFormatter(um) << "\n";

  {
    std::deque<int> d;
    d.push_back(1);
    d.push_front(2);
    std::cout << SeqFormatter(d).setDelimiters("[[", "]]").setSep("; ") << "\n";
  }
  return 0;
}

