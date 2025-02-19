#include "Player.h"
#include <cmath>

//constructor
Player::Player(){}

/*Player::Player(string Name,int MaxHealth,int Attack,int Defense){
    this->setName(Name);
    this->setMaxHealth(MaxHealth);
    this->setAttack(Attack);
    this->setDefense(Defense);
}*/


//funtion
void Player::addItem(Item* item){
    inventory.push_back(item);
}

bool Player::triggerEvent(Object*object){
    this->showStatus();
    return true;
}

void Player::changeRoom(Room*room){
    previousRoom = currentRoom;
    currentRoom = room;
}

void Player::setCurrentRoom(Room*room){
    currentRoom = room;
}

void Player::setPreviousRoom(Room*room){
    previousRoom = room;
}

void Player::setMoney(int Money){
    money = Money;
}

void Player::setKey(bool Key){
    key = Key;
}

Room* Player::getCurrentRoom(){
    return currentRoom;
}

Room* Player::getPreviousRoom(){
    return previousRoom;
}

int Player::getMoney(){
    return money;
}

bool Player::getKey(){
    return key;
}

void Player::showStatus(){
    cout << "Name: " << this->getName() << endl;
    cout << "Attack: " << this->getAttack() << "       " << "Defense: " << this->getDefense() << endl;
    cout << "HP: " << this->getCurrentHealth() << " / " << this->getMaxHealth() << endl;
    cout << "Occupation: " << this->getOccupation() << endl;
    cout << "Skill: " << this->getSkill() << "     " << "CD: " << this->getCurrentCD() << endl;
    cout << "Money: " << this->getMoney() << endl;
    cout << endl;
}

void Player::takeAction(){
    cout << "What do you want to do ?" << endl;
    cout << "1. Move\n" << "2.check status\n" << "3.save file" << endl;
}

vector<Item*>Player:: getInventory(){
    return inventory;
}

void Player::increaseStates(int Attack,int Defense,int Maxhealth, int Health){
    this->setAttack(this->getAttack() + Attack);
    this->setDefense(this->getDefense() + Defense);
    this->setMaxHealth(this->getMaxHealth() + Maxhealth);
    this->setCurrentHealth(this->getCurrentHealth()+ Health);
}

void Player::move_picture(){
    int walker[10][16]
    {
    //第一張行人靜止圖
    {896, 896, 896, 640, 1984, 4064, 4064, 2976,
    2976, 2976, 4064, 1984, 1728, 1728, 1728, 3808},

    //第二張行人步行圖
    {0, 6144, 15360, 6144, 3072, 3840, 3712, 5696,
    9792, 1792, 1280, 2272, 2064, 2080, 12288, 0},

    //第三張行人步行圖
    {0, 3072, 7680, 3072, 1536, 1792, 1664, 3904,
    4928, 896, 640, 1120, 2080, 1632, 512, 3584},

    //第四張行人步行圖
    {0, 6144, 15360, 6144, 3072, 3584, 3840, 3712,
    1664, 1792, 1280, 2176, 2112, 2080, 14352},

    //第五張行人步行圖
    {0, 3072, 7680, 3072, 1536, 1920, 1856, 2880,
    4864, 896, 640, 1120, 1048, 1032, 6160, 0},

    //第六張行人步行圖
    {0, 6144, 15360, 6144, 3072, 3584, 3584, 3584,
    1536, 1536, 1536, 1536, 512, 512, 512, 512},

    //第七張行人步行圖
    {0, 3072, 7680, 3072, 1536, 1920, 1856, 1824,
    2816, 896, 640, 1136, 1032, 7168, 0, 0},

    //第八張行人步行圖
    {0, 6144, 15360, 6144, 3072, 3584, 3328, 3840,
    1792, 1536, 1536, 3584, 2304, 1152, 7232, 0},

    //第九張行人步行圖
    {0, 3072, 7680, 3072, 1536, 1920, 1856, 2848,
    4896, 768, 896, 640, 1120, 1072, 1040, 6176},

    //第十張行人步行圖
    {0, 3072, 7680, 3072, 1536, 1792, 1664, 3904,
    4928, 896, 640, 1088, 2080, 1552, 560, 1536}
    };

    for(int pic=1 ; pic<=9 ; pic++)
    {
        system("cls"); //清除螢幕畫面

        //顯示第(pic+1)張圖
        int temp;

        //對圖案中16個10進制數字，以2進位表示
        //再將1對應成 . ， 0 對應成空白，輸出到螢幕
        for(int i=0 ; i<16 ; i++) // 每張圖都有16個數值，相當於16列資料
        {
            temp = walker[pic][i]; // 第num+1張圖的第i+1個數值

            for(int j=0 ; j<16 ; j++) // 每個數值，轉成16位的2進位資料
            {
                if((temp / (int)pow(2, 15-j)) >= 1) //temp除以2的(15-i)次方
                    cout << ".";
                else
                    cout << " ";
                temp = temp % (int)pow(2, 15-j);//temp除以2的(15-i)次方的餘數
            }
            cout << endl;

        }

        for(int i=1 ; i<=100000000 ; i++);//讓程式空轉，好像暫停一些時間
    }
}
