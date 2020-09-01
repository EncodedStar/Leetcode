/*
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

示例 1：

输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
示例 2：

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
提示：

1 <= values <= 10000
最多会对 appendTail、deleteHead 进行 10000 次调用
*/

class CQueue {
public:
    stack<int> sin, sout; 
    CQueue() {}
    void appendTail(int value) {
        sin.emplace(value);
    }
    int deleteHead() {
        ios::sync_with_stdio(false);
        if (sout.empty() && sin.empty()) return -1;
        if (sout.empty()) {
            while(!sin.empty()){
                sout.emplace(sin.top());
                sin.pop();
            }    
        } 
        int temp = sout.top();
        sout.pop();
        return temp;
    }
};

// ps： 这个我最初想的有点简单，我只是把俩个栈分开来，进的时候全部放一个栈，出的时候全部放到一个栈（每次都转移，没有考虑优化）
// 实际操作可以在出的时候判断是否为空在找进的栈转移。

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */