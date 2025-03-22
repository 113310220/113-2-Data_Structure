#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Player { /*玩家結構資料型態,包含string類型的玩家名稱以及int類型的玩家分數*/
string name;
int score;
};

int drawCard() {
return rand() % 10 + 1; /*發牌功能,呼叫一次發一張數值在1-10之間的牌*/
}

// 初始化玩家
void initializePlayer(Player* player, string name) {
    player->name = name;
    player->score = drawCard() + drawCard(); // 發兩張牌
}

// 顯示玩家分數
void displayScore(Player* player) {
/*顯示玩家當前的手牌點數*/
 cout << player->name << " 的分數為 " << player->score << endl;
}

// 玩家回合
void playerTurn(Player& player) {
    char choice;
    while (player.score < 21) {
        cout << "要抽牌嗎? (h = 抽, s = 停) : ";
        cin >> choice;

        if (choice == 'h') {
            int newCard = drawCard();
            cout << "你抽到了 " << newCard << " 點。" << endl;

            // 若抽到 1 點，詢問是否當作 11 點
            if (newCard == 1 && player.score + 11 <= 21) {
                char choice_one;
                cout << "你抽到了 1 點，是否將其轉為 11 點? (y = 是, n = 否): ";
                cin >> choice_one;
                if (choice_one == 'y') {
                    newCard = 11;
                }
            }

            player.score += newCard;
            cout << "目前總分: " << player.score << endl;

            if (player.score == 21) {
                cout << "你剛好 21 點！回合結束。\n";
                return;
            }

            if (player.score > 21) {
                cout << player.name << " 爆掉了! 遊戲結束。\n";
                return;
            }
        } else if (choice == 's') {
            cout << player.name << " 選擇停牌。\n";
            break;
        }
    }
}

// 莊家回合
void dealerTurn(Player* dealer) {
while (dealer->score < 17) { // 莊家至少要到 17 點
 int newCard = drawCard();
dealer->score += newCard;
cout << "莊家抽到" << newCard << "點,目前總分: " <<
dealer->score << endl;
if (dealer->score > 21) { // 如果莊家超過 21 點
cout << "莊家抽到" << newCard << "點,目前總分: " <<
dealer->score << endl;
cout << "莊家爆了!玩家獲勝!" << endl;
return; // 遊戲結束
}
}
}

// 判斷勝負
void determineWinner(Player* player, Player* dealer) {
if (player->score > 21) {
cout << "你爆了!莊家獲勝!\n";
}
else if (dealer->score > 21 || player->score > dealer->score) {
cout << "你贏了!!\n";
}
else if (player->score == dealer->score) {
cout << "平手!\n";
}
else {

cout << "莊家贏了!\n";
}
}

// 主程式
int main() {
srand(time(0));
Player player, dealer;
initializePlayer(&player, "玩家");
initializePlayer(&dealer, "莊家");
displayScore(&player);
playerTurn(
player);
if (player.score <= 21) { // 如果沒爆才讓莊家回合
cout << "\n莊家回合...\n";
displayScore(&dealer);
dealerTurn(&dealer);
determineWinner(&player, &dealer);
}
return 0;
}
