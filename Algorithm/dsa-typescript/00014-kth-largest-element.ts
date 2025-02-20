class MinHeap {
  private heap: number[] = [];

  add(val: number): void {
    this.heap.push(val);
    this.bubbleUp();
  }

  remove(): number | undefined {
    if (this.heap.length === 1) return this.heap.pop();

    const root = this.heap[0];
    this.heap[0] = this.heap.pop();
    this.bubbleDown();

    return root;
  }

  peek(): number | undefined {
    return this.heap[0];
  }

  size(): number {
    return this.heap.length;
  }

  private bubbleUp(): void {
    let index = this.heap.length - 1;
    const element = this.heap[index];

    while (index > 0) {
      const parentIndex = Math.floor((index - 1) / 2);
      const parent = this.heap[parentIndex];

      if (element >= parent) break;

      this.heap[index] = parent;
      index = parentIndex;
    }

    this.heap[index] = element;
  }

  bubbleDown() {
    let index = 0;
    const element = this.heap[0];
    const length = this.heap.length;

    while (index < length / 2) {
      let parent = index;
      let left = 2 * index + 1;
      let right = 2 * index + 2;

      if (left < length && this.heap[left] < this.heap[index]) parent = left;
      if (right < length && this.heap[right] < this.heap[index]) parent = right;
      if (parent === index) break;

      [this.heap[index], this.heap[parent]] = [
        this.heap[parent],
        this.heap[index]
      ];
      index = parent;
    }

    this.heap[index] = element;
  }
}

export default function findKthLargest(nums: number[], k: number): number {
  const minHeap = new MinHeap();

  for (let num of nums) {
    minHeap.add(num);
    if (minHeap.size() > k) {
      minHeap.remove();
    }
  }

  return minHeap.peek();
}
