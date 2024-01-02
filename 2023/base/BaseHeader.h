#ifndef __BASE_HEADER_HPP__
#define __BASE_HEADER_HPP__

#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template <typename T>
void DebugVector(vector<T>& v) {
  for (auto& i : v) {
    cout << i << " ";
  }
  cout << endl;
}

template <typename T>
void DebugQueue(queue<T>& q) {
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;
}

#include "BaseList.h"
#include "BaseTree.h"

#endif