class ListNode {
  constructor(public val?: number, public next?: ListNode | null) {
    this.val = val || 0;
    this.next = next || null;
  }
}

function createLinkedList(list: number[]) {
  let head: ListNode;

  if (!list.length) {
    return null;
  }

  list.forEach(val => {
    if (!head) {
      return (head = new ListNode(val));
    }

    let tail = head;

    while (tail.next) {
      tail = tail.next;
    }

    tail.next = new ListNode(val);
  });

  return head;
}

// Middle of the Linked List
// If there are two middle nodes, return the second middle node
// Input: [1, 2, 3, 4, 5] --> Output: [3, 4, 5] (One middle node 3)
// Input: [1, 2, 3, 4, 5, 6] --> Output: [4, 5, 6] (Two middle nodes 3 & 4)
// Time Complexity O(n)
// Space Complexity O(1)

export default function middleNode(list: number[]): ListNode | null {
  let head = createLinkedList(list);

  let mid = head;
  let end = head;

  while (end && end.next) {
    mid = mid.next;
    end = end.next.next;
  }

  return mid;
}
