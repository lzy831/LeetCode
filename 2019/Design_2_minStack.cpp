// 最小栈
// 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

// push(x) -- 将元素 x 推入栈中。
// pop() -- 删除栈顶的元素。
// top() -- 获取栈顶元素。
// getMin() -- 检索栈中的最小元素。
// 示例:

// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> 返回 -3.
// minStack.pop();
// minStack.top();      --> 返回 0.
// minStack.getMin();   --> 返回 -2.



#include "BaseHeader.hpp"

class MinStack
{
public:
  /** initialize your data structure here. */
  MinStack()
  {

  }

  void push(int x)
  {
    s1.push(x);

    if(s2.empty())
    {
      s2.push(x);
    }
    else
    {
      if(x < s2.top())
      {
        s2.push(x);
      }
      else
      {
        s2.push(s2.top());
      }
    }

  }

  void pop()
  {
    s1.pop();
    s2.pop();
  }

  int top()
  {
    return s1.top();
  }

  int getMin()
  {
    return s2.top();
  }

private:
  stack<int> s1;
  stack<int> s2;
};

int main(int argc, char const* argv[])
{
  MinStack s;
  s.push(5);
  cout << s.getMin() << endl;
  s.push(4);
  cout << s.getMin() << endl;
  s.push(3);
  cout << s.getMin() << endl;
  s.push(2);
  cout << s.getMin() << endl;
  s.push(8);
  cout << s.getMin() << endl;
  s.pop();
  cout << s.getMin() << endl;
  s.pop();
  cout << s.getMin() << endl;
  return 0;
}