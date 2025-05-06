#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

// 從檔案中讀取資料並存入向量
vector<int> readFromFile(const string& filename) {
    vector<int> arr;
    ifstream file(filename);

    if (!file) {
        cerr << "開啟檔案錯誤: " << filename << endl;
        return arr;
    }

    string line;
    while (getline(file, line)) { // 持續讀取整行內容
        stringstream ss(line);    // 創建字串流
        string value;
        while (getline(ss, value, ',')) { // 用逗號分隔值
            try {
                arr.push_back(stoi(value)); // 將字串轉換為整數並存入向量
            }
            catch (exception& e) {
                cerr << "檔案中數字格式錯誤: " << value << endl;
            }
        }
    }

    file.close();
    return arr;
}

class MinHeap {
public:
    vector<int> heap; // 儲存Min Heap的元素

    // 建立Min Heap
    void buildMinHeap(vector<int>& arr) {  // 建立Min Heap
        heap = arr;

        for (int i = (heap.size() / 2) - 1; i >= 0; i--) { // 從最後一個非葉子節點開始向上執行Min Heap
            heapify(i);
        }
    }

    // 堆化函式（確保以i為根的子樹符合Min Heap性質）
    void heapify(int i) {
        int smallest = i;          // 假設當前節點是最小的
        int left = 2 * i + 1;      // 左子節點索引
        int right = 2 * i + 2;     // 右子節點索引

        // 檢查左子節點是否比當前節點小
        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }

        // 檢查右子節點是否比當前節點小
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        // 如果最小的不是父節點，交換並繼續堆化
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest); // 迴圈處理受影響的子樹
        }
    }

    // 顯示Heap的內容（使用BFS）
    void printHeap() {
        for (int val : heap) {  // 遍歷 Min Heap中的每個元素
            cout << val << " ";  // 輸出元素
        }
        cout << endl;
    }
};

int main() {
    // 從檔案讀取輸入元素
    string filename = "C:\\Users\\CNC\\Desktop\\input2.txt"; // 請貼上input檔案的正確路徑
    vector<int> arr = readFromFile(filename);  // 讀取資料

    if (arr.empty()) {  // 如果資料為空
        cerr << "檔案中沒有有效資料。" << endl;  // 輸出錯誤訊息
        return -1;
    }

    cout << "輸入資料: ";  // 輸出讀取的資料
    for (int val : arr) {
        cout << val << " ";  // 輸出每個元素
    }
    cout << endl;

    MinHeap minHeap;  // 創建Min Heap對象
    minHeap.buildMinHeap(arr);  // 建立Min Heap

    // 輸出Min Heap的內容
    cout << "Min Heap (使用BFS): ";
    minHeap.printHeap();
    cout << endl;

    system("pause");
    return 0;
}
