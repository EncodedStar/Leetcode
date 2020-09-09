/*
剑指 Offer 41. 数据流中的中位数
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，
[2,3,4] 的中位数是 3
[2,3] 的中位数是 (2 + 3) / 2 = 2.5
设计一个支持以下两种操作的数据结构：
void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
示例 1：

输入：
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
输出：[null,null,null,1.50000,null,2.00000]
示例 2：

输入：
["MedianFinder","addNum","findMedian","addNum","findMedian"]
[[],[2],[],[3],[]]
输出：[null,null,2.00000,null,2.50000]
 

限制：
最多会对 addNum、findMedia进行 50000 次调用。
*/

class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int,vector<int>,less<int>> leftQue; //大顶堆
    priority_queue<int,vector<int>,greater<int>> rightQue; //小顶堆
    MedianFinder() {
    }
    void addNum(int num) {
         //左右数量相等,则取出右边的一个对象push进入左边的大顶堆
         if(leftQue.size() == rightQue.size())
         {
            rightQue.push(num);
            leftQue.push(rightQue.top());
            rightQue.pop();   
         }
         //左边多一个,则取出左边的一个对象push进右边的小顶堆
         else if(leftQue.size() == rightQue.size()+1)
         {
            leftQue.push(num);
            rightQue.push(leftQue.top());
            leftQue.pop(); 
         }
    }
    
    double findMedian() {
        double res = 0.0;
        if(leftQue.size() == rightQue.size())
        {
            res = ((double)leftQue.top() + (double)rightQue.top())/2;
        }
        else res = leftQue.top();
        return res;
    }
};


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */