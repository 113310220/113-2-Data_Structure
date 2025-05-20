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
    int sumOfLevel(TreeNode* root, int targetLevel) {
        if (!root) return 0;

        queue<TreeNode*> q;//建立queue儲存待處理的節點指標
        q.push(root);// 將根節點的指標加入queue
        int currentLevel = 0;

        while (!q.empty()) {
            int size = q.size();
            int levelSum = 0;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front(); q.pop();

                if (currentLevel == targetLevel) {
                    levelSum += node->value; //將節點相加
                }

                if (node->left) q.push(node->left); // 將左子節點的指標加入queue
                if (node->right) q.push(node->right);// 將左子節點的指標加入queue
            }

            if (currentLevel == targetLevel) {
                return levelSum;//回傳
            }

            currentLevel++;
        }

        // 若層數超過樹高
        cout << "超過樹高度。" << endl;
        return 0;
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
    cout << "請輸入要查詢的層數: ";//輸入曾數
    int level;
    cin >> level;
    int sum = tree.sumOfLevel(tree.root, level);
    if (sum != 0)
        cout << "第 " << level << " 層節點值的總和為: " << sum << endl;//輸出總和
    system("pause");
    return 0;
}
