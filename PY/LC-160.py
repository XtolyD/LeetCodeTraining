from typing import Optional

# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        if not headA or not headB:
            return None
        a, b = headA, headB
        while a != b:
            a = a.next if a else headB
            b = b.next if b else headA
        return a


if __name__ == "__main__":
    # Create a linked list
    headA = ListNode(4)
    headA.next = ListNode(1)
    headA.next.next = ListNode(8)
    headA.next.next.next = ListNode(4)
    headA.next.next.next.next = ListNode(5)
    
    headB = ListNode(5)
    headB.next = ListNode(0)
    headB.next.next = ListNode(1)
    headB.next.next.next = headA.next.next  # Intersection node

    print(Solution().getIntersectionNode(headA, headB).val)  # Output: 8
    # Explanation: The intersection node is located at position 2 where 8 is connected to 1.
    # 4 -> 1 -> 8 -> 4 -> 5
    # 5 -> 0 -> 1 -> 8 -> 4 -> 5
    # The intersection node is 8.