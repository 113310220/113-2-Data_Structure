#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const int EMPTY = NULL; // 用 NULL 代表沒有節點
class TreeNode {
public:
    int value;// 節點值
    TreeNode* left;// 左子節點
    TreeNode* right;// 右子節點

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}//初始化節點
};

class BinaryTree {
public:
    TreeNode* root;// 樹根節點

    BinaryTree() : root(nullptr) {}

    TreeNode* buildTree(const vector<int>& arr) {// 建立樹
        if (arr.empty() || arr[0] == EMPTY) return nullptr;

        queue<TreeNode**> q;//建立queue儲存待處理的節點指標
        root = new TreeNode(arr[0]);// 建立根節點 (陣列第一個元素)
        q.push(&root);// 將根節點的指標加入queue

        size_t i = 1;// 陣列索引
        while (!q.empty() && i < arr.size()) {
            TreeNode** nodePtr = q.front();// 取出queue的第一個節點指標
            q.pop();// 將該節點從queue中刪除

            // 左子節點
            if (i < arr.size()) {
                if (arr[i] != EMPTY) {
                    (*nodePtr)->left = new TreeNode(arr[i]);// 添加左子節點
                    q.push(&((*nodePtr)->left));// 將左子節點的指標加入queue
                }
                i++;
            }
            // 右子節點
            if (i < arr.size()) {
                if (arr[i] != EMPTY) {
                    (*nodePtr)->right = new TreeNode(arr[i]);// 添加右子節點
                    q.push(&((*nodePtr)->right));// 將右子節點的指標加入queue
                }
                i++;
            }
        }
        return root;
    }



    void Breadth_first_search(TreeNode* root) {
        if (root == nullptr) return;
        queue<TreeNode*> q;//建立queue儲存待處理的節點指標
        q.push(root); // 將根節點的指標加入queue

        while (!q.empty()) {
            TreeNode* current = q.front();// 取出queue的第一個節點指標
            q.pop();// 將該節點從queue中刪除
            cout << current->value << " ";
            if (current->left) q.push(current->left);  // 將左子節點的指標加入queue
            if (current->right) q.push(current->right);// 將左子節點的指標加入queue
        }
    }
      int subtreeSum(TreeNode* node) {
        if (!node) return 0;
        return node->value + subtreeSum(node->left) + subtreeSum(node->right);//將子樹點相加
    }

    TreeNode* findNode(TreeNode* node, int target) {
        if (!node) return nullptr;
        if (node->value == target) return node;
        TreeNode* leftResult = findNode(node->left, target);
        if (leftResult) return leftResult;
        return findNode(node->right, target);
    }

    void analyzeNode(TreeNode* root, int target) {
        TreeNode* targetNode = findNode(root, target);//找尋
        //沒找到
        if (!targetNode) {
            cout << "節點值 " << target << " 不存在於樹中。" << endl;
            return;
        }
        //當查詢到葉節點時
        if (!targetNode->left && !targetNode->right) {
            cout << "節點 " << target << " 是葉節點，沒有子樹。" << endl;
            return;
        }

        int leftSum = subtreeSum(targetNode->left);//右子樹增加
        int rightSum = subtreeSum(targetNode->right);//左子樹增加

        cout << "節點 " << target << " 左子樹總和為: " << leftSum << endl;
        cout << "節點 " << target << " 右子樹總和為: " << rightSum << endl;

        if (leftSum > rightSum)//左子>右子
            cout << "左子樹總和較大。" << endl;
        else if (rightSum > leftSum)//右子>左子
            cout << "右子樹總和較大。" << endl;
        else//相等
            cout << "左右子樹總和相等。" << endl;
    }

     
};

int main() {
    BinaryTree tree;
    vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, NULL, NULL, 10, 11, NULL, NULL };
    tree.buildTree(arr);
    int targetLevel = 0;

    cout << "BFS Result: ";
    tree.Breadth_first_search(tree.root);//轉為BFS
    cout << endl;
    cout << "請輸入要查詢的節點值: ";
    int targetNodeVal;
    cin >> targetNodeVal;
    tree.analyzeNode(tree.root, targetNodeVal);
    system("pause");
    return 0;
}
