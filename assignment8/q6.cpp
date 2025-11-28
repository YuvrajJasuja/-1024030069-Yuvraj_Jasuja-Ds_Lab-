class PriorityQueue {
    int arr[100];
    int size;

public:
    PriorityQueue(){ size = 0; }

    void insert(int x){
        int i = size++;
        arr[i] = x;

        while(i != 0 && arr[(i-1)/2] < arr[i]){
            swap(arr[i], arr[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    int extractMax(){
        if(size == 0) return -1;
        int root = arr[0];
        arr[0] = arr[--size];
        heapify(arr, size, 0);
        return root;
    }
};
