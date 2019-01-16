#ifndef __BASE_HEADER_HPP__
#define __BASE_HEADER_HPP__

#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#include "BaseList.hpp"
#include "BaseTree.hpp"


template <typename T>
void DebugVector(vector<T>& v)
{
  for(auto & i : v)
  {
    cout << i << " ";
  }
  cout << endl;
}

#endif