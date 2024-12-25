class ListNode {
  constructor(public val: number = 0, public next: ListNode = null) {}
}

// Sort linked list using insertion sort
// Time Complexity O(n^2)
// Space Complexity O(1)

export default function insertionSortList(
  head: ListNode | null
): ListNode | null {
  let curr = head;
  let dummy = new ListNode();

  while (curr !== null) {
    let prev = dummy;

    while (prev.next !== null && prev.next.val <= curr.val) {
      prev = prev.next;
    }

    let next = curr.next;

    curr.next = prev.next;
    prev.next = curr;

    curr = next;
  }

  return dummy.next;
}

function createListNode(list: number[]) {
  let head: ListNode;

  list.forEach(num => {
    let temp = head;
    const node = new ListNode(num);

    if (!head) {
      return (head = node);
    }

    while (temp.next) {
      temp = temp.next;
    }

    temp.next = node;
  });

  return head;
}

function printListNode(head: ListNode) {
  while (head) {
    console.log(head.val);
    head = head.next;
  }
}
