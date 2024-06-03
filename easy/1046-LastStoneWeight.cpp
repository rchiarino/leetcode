// You are given an array of integers stones where stones[i] is the weight of the ith stone.

// We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.

// Return the weight of the last remaining stone. If there are no stones left, return 0.

// Example 1 :

// Input : stones = [ 2, 7, 4, 1, 8, 1 ] Output : 1
// Explanation : We combine 7 and 8 to get 1 so the array converts to[2, 4, 1, 1, 1] then,
//              we combine 2 and 4 to get 2 so the array converts to[2, 1, 1, 1] then,
//              we combine 2 and 1 to get 1 so the array converts to[1, 1, 1] then,
//              we combine 1 and 1 to get 0 so the array converts to[1] then that's the value of the last stone.

// Example 2 :
// Input : stones = [1] Output : 1

template <class T>
class MaxHeap
{
public:
    MaxHeap(int capacity)
    {
        size = 0;
        this->capacity = capacity;
        heap = new T[capacity + 1];
    }

    void insert(T value)
    {
        if (size == capacity)
        {
            std::cout << "Heap is full" << std::endl;
            return;
        }
        size++;
        heap[size] = value;
        swim(size);
    }

    T deletePeek()
    {
        if (isEmpty())
        {
            std::cout << "Heap is empty" << std::endl;
            return T();
        }
        T maxValue = heap[1];
        swap(1, size);
        size--;
        sink(1);
        return maxValue;
    }

    T peek()
    {
        return heap[1];
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool moreThanOneElement()
    {
        return size > 1;
    }

private:
    T *heap;
    int size;
    int capacity;

    void swim(int index)
    {
        while (index > 1 && heap[index / 2] < heap[index])
        {
            swap(index, index / 2);
            index = index / 2;
        }
    }

    void sink(int index)
    {
        while (2 * index <= size)
        {
            int j = 2 * index;
            if (j < size && heap[j] < heap[j + 1])
                j++;
            if (heap[index] >= heap[j])
                break;
            swap(index, j);
            index = j;
        }
    }

    void swap(int i, int j)
    {
        T temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
};

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        MaxHeap<int> heap(stones.size());
        for (int i = 0; i < stones.size(); i++)
        {
            heap.insert(stones[i]);
        }
        while (heap.moreThanOneElement())
        {
            int y = heap.peek();
            heap.deletePeek();
            int x = heap.peek();
            heap.deletePeek();
            if (x != y)
            {
                heap.insert(y - x);
            }
        }
        return heap.isEmpty() ? 0 : heap.peek();
    }
};