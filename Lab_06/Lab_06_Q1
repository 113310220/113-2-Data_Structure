#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

// 定義 Stack 的節點結構
struct Node {
    char data;  // 存儲字符 (運算子或括號)
    Node* next; // 指向下一個節點
};

// 使用 linked list 實作 Stack
class Stack {
private:
    Node* top; // 指向堆疊頂端
public:
    Stack() { top = nullptr; } // 初始化堆疊

    // Push 操作：將元素放入堆疊
    void push(char ch) {
      Node* newNode = new Node(); // 建立新節點
        newNode->data = ch;         // 儲存資料
        newNode->next = top;        // 新節點指向原本的頂端
        top = newNode;              // 更新頂端為新節點
      
    }

    // Pop 操作：移除並回傳頂端元素
    char pop() {
         if (top == nullptr) {  // 如果堆疊是空的
            cout << "堆疊為空，無法取出元素。\n";
            return '\0';        // 返回空字符，表示堆疊空
        }

        char poppedValue = top->data; // 取得頂端元素的值
        Node* temp = top;            // 用 temp 暫存目前頂端節點
        top = top->next;             // 更新頂端為下一個節點
        delete temp;                 // 釋放記憶體，刪除原頂端節點
        return poppedValue;          // 返回彈出的元素
 
    }

    // Peek 操作：取得頂端元素但不移除
     char peek() {
        if (top == nullptr) {  // 如果堆疊是空的
            cout << "堆疊為空，無法取出元素。\n";
            return '\0';        // 返回空字符，表示堆疊空
        }
        return top->data;       // 返回頂端元素但不移除
    }

    // 判斷堆疊是否為空
    bool isEmpty() {
        return top == nullptr;  // 如果堆疊為空，返回 true，否則返回 false
    }
};

// 判斷運算子(加減乘除) 的優先順序
int precedence(char op) {
   if (op == '+' || op == '-') {
        return 1; // 加減的優先順序較低
    }
    else if (op == '*' || op == '/') {
        return 2; // 乘除的優先順序較高
    }
    return 0; // 非運算子的情況
}

// 將中序表達式 (infix) 轉換為後序表達式 (postfix)
void InfixToPostfix(const char* infix, char* postfix) {
   Stack stack;
    int j = 0; // 後序表達式的索引

    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // 如果是操作數（數字或字母），直接加到後序表達式
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // 如果是左括號，推入堆疊
        else if (ch == '(') {
            stack.push(ch);
        }
        // 如果是右括號，彈出堆疊直到遇到左括號
        else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix[j++] = stack.pop();
            }
            stack.pop(); // 彈出左括號
        }
        // 如果是運算子
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                postfix[j++] = stack.pop(); // 彈出堆疊直到運算子優先順序較低
            }
            stack.push(ch); // 把運算子推入堆疊
        }
    }

    // 彈出剩餘的運算子
    while (!stack.isEmpty()) {
        postfix[j++] = stack.pop();
    }

    postfix[j] = '\0'; // 結束後序表達式的字符串
}

int main() {
    char infix[100], postfix[100];
    cout << "Enter an Infix expression: ";
    cin >> infix; // 輸入中序表達式

    InfixToPostfix(infix, postfix); // 轉換為後序表達式
    cout << "Postfix expression: " << postfix << endl; // 輸出後序表達式

    return 0;
}
