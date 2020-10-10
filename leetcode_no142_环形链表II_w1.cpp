/* ------------------------------------------------------------------|
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。

进阶：

你是否可以不用额外空间解决此题？
 

示例 1：



输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。
示例 2：



输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。
示例 3：



输入：head = [1], pos = -1
输出：返回 null
解释：链表中没有环。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/linked-list-cycle-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。|
------------------------------------------------------------------*/

/*	快慢指针法
*
*	执行用时：4 ms, 在所有 C++ 提交中击败了99.85%的用户
*	内存消耗：7.4 MB, 在所有 C++ 提交中击败了57.31%的用户
*/

#include <iostream>
#include <string> 
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode* head) {
	if (head == NULL || head->next == NULL) {
		return nullptr;
	}

	ListNode* slow = head;
	ListNode* fast = head->next;

	while (slow != fast) {
		if (fast->next == NULL || fast->next->next == NULL) {
			return nullptr;
		}
		else {
			slow = slow->next;
			fast = fast->next->next;
		}
	}
	//假设从head到环路入口的距离为x1
	//环路入口到两指针相遇的距离为x2
	//则slowLen = x1 + x2
	//fastLen = (x1 - 1) + x2 + n * cycle,因为初始fast比slow快一个节点
	//由于fast的速度是slow的两倍
	//所以2 * ( x1 + x2) = fastLen
	//所以x1 = cycle - (x2 + 1)
	//由于(x2 + 1)，所以fast要在相遇点再向后移动一次
	slow = head;
	fast = fast->next;

	//判断是否相遇
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	//返回相遇节点
	return slow;
}