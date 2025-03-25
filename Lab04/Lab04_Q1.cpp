#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
// 表示單張撲克牌的類別
class Card {
public:
string colors; //儲存撲克牌的花色
string rank; //儲存撲克牌的數值
Card(string s, string r) : colors(s), rank(r) {} //建立 constructor來初始化物件,當 Card 物件建立時,它會自動執行這個函式,並把 s 和 r 的值存入colors 和 rank
void display() const { //顯示撲克牌的資訊
cout << rank << " of " << colors << endl;
}
};
// 實作 Stack
class Stack {
private:
vector<Card> stack; //表示 stack 是一個能存放 Card 類別物件的 vector

public:
void push(const Card& card) {
	  if (stack.size()>= 52) { // top已經到達上限，即stack滿了
        cout << "Stack是滿的" << endl;
        } 
      else {
        stack.push_back(card); // 存入新元素
    } 
    }

Card pop() {
	if (stack.empty()) { // stack目前沒有存放內容
        cout << "Stack是空的" << endl;
        return Card("", "");// 回傳一張空的牌
    }
    else {  
        Card card = stack.back();// 取得堆疊頂端的牌
        stack.pop_back();// 彈出這張牌
        return card;
    }
}
// 檢查堆疊是否為空
bool isEmpty() const {
	 return stack.empty();
}
};

// 代表一副撲克牌的類別
class Deck {
private:
vector<Card> cards; // 存放未洗牌的撲克牌
Stack shuffledDeck; // 存放洗過的牌,用實作的 stack 來管理
public:
Deck() { //建立 constructor 來初始化物件
string colors[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
//儲存撲克牌的花色
string ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9",
"10", "J", "Q", "K", "A" }; //儲存撲克牌的數值
//利用迴圈將 52 張牌加入 cards 這個 vector 裡面
for (int i = 0; i < 4; i++) { // 四種花色
for (int j = 0; j < 13; j++) { // 13 種點數
cards.push_back(Card(colors[i], ranks[j]));
}
}
}
//洗牌(Hint:使用 shuffle 函數)
void shuffleDeck() {
    // 用 rand() 來進行隨機洗牌
    srand(time(0)); // 使用當前時間作為隨機種子

    // 進行洗牌
    for (int i = cards.size() - 1; i > 0; --i) {
        // 隨機選擇一個位置
        int j = rand() % (i + 1);  // 在 [0, i] 之間隨機選擇 j
        // 交換位置 i 和 j 的卡片
        swap(cards[i], cards[j]);
    }

    // 把洗過的牌放入堆疊
    for (const auto& card : cards) {
        shuffledDeck.push(card);
    }
}

//發牌
void drawAllCards() {
    // 從堆疊中取出所有卡片並顯示
	while (!shuffledDeck.isEmpty()) {
            Card card = shuffledDeck.pop();
            card.display();
			}
}
};
int main() {
Deck deck; //建立 deck 產生 52 張撲克牌
deck.shuffleDeck(); //進行洗牌並放入堆疊
cout << "Shuffled deck:" << endl;
deck.drawAllCards(); //依序取出堆疊內的牌並顯示
return 0;
}
