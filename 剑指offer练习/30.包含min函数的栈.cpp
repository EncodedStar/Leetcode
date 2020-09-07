/*
剑指 Offer 30. 包含min函数的栈
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

 
示例:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();   --> 返回 0.
minStack.min();   --> 返回 -2.
 
提示：
各函数的调用总次数不超过 20000 次
*/


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) { 
        if (m_Stack_end == -1 || m_min >= x) {
            m_min = x;
            m_MinStack_end++;
            m_MinStack[m_MinStack_end] = m_min;
        }
        m_Stack_end++;
        m_Stack[m_Stack_end] = x;
    }
    
    void pop() {
      if (m_Stack_end == -1) return ;
      if (m_Stack[m_Stack_end] == m_min) {
          m_MinStack_end--;
          if (m_MinStack_end != -1) 
            m_min = m_MinStack[m_MinStack_end];
      }
      m_Stack_end--;
    }
    
    int top() {
      if (m_Stack_end == -1) return 0;
      return m_Stack[m_Stack_end];
    }
    
    int min() {
      if (m_MinStack_end == -1) return 0;
      return m_MinStack[m_MinStack_end];
    }

    int m_MinStack[20001];
    int m_MinStack_end = -1;
    int m_Stack[20001];
    int m_Stack_end = -1;
    int m_min = 0;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */