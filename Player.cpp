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
    //�Ĥ@�i��H�R���
    {896, 896, 896, 640, 1984, 4064, 4064, 2976,
    2976, 2976, 4064, 1984, 1728, 1728, 1728, 3808},

    //�ĤG�i��H�B���
    {0, 6144, 15360, 6144, 3072, 3840, 3712, 5696,
    9792, 1792, 1280, 2272, 2064, 2080, 12288, 0},

    //�ĤT�i��H�B���
    {0, 3072, 7680, 3072, 1536, 1792, 1664, 3904,
    4928, 896, 640, 1120, 2080, 1632, 512, 3584},

    //�ĥ|�i��H�B���
    {0, 6144, 15360, 6144, 3072, 3584, 3840, 3712,
    1664, 1792, 1280, 2176, 2112, 2080, 14352},

    //�Ĥ��i��H�B���
    {0, 3072, 7680, 3072, 1536, 1920, 1856, 2880,
    4864, 896, 640, 1120, 1048, 1032, 6160, 0},

    //�Ĥ��i��H�B���
    {0, 6144, 15360, 6144, 3072, 3584, 3584, 3584,
    1536, 1536, 1536, 1536, 512, 512, 512, 512},

    //�ĤC�i��H�B���
    {0, 3072, 7680, 3072, 1536, 1920, 1856, 1824,
    2816, 896, 640, 1136, 1032, 7168, 0, 0},

    //�ĤK�i��H�B���
    {0, 6144, 15360, 6144, 3072, 3584, 3328, 3840,
    1792, 1536, 1536, 3584, 2304, 1152, 7232, 0},

    //�ĤE�i��H�B���
    {0, 3072, 7680, 3072, 1536, 1920, 1856, 2848,
    4896, 768, 896, 640, 1120, 1072, 1040, 6176},

    //�ĤQ�i��H�B���
    {0, 3072, 7680, 3072, 1536, 1792, 1664, 3904,
    4928, 896, 640, 1088, 2080, 1552, 560, 1536}
    };

    for(int pic=1 ; pic<=9 ; pic++)
    {
        system("cls"); //�M���ù��e��

        //��ܲ�(pic+1)�i��
        int temp;

        //��Ϯפ�16��10�i��Ʀr�A�H2�i����
        //�A�N1������ . �A 0 �������ťաA��X��ù�
        for(int i=0 ; i<16 ; i++) // �C�i�ϳ���16�ӼƭȡA�۷��16�C���
        {
            temp = walker[pic][i]; // ��num+1�i�Ϫ���i+1�Ӽƭ�

            for(int j=0 ; j<16 ; j++) // �C�ӼƭȡA�ন16�쪺2�i����
            {
                if((temp / (int)pow(2, 15-j)) >= 1) //temp���H2��(15-i)����
                    cout << ".";
                else
                    cout << " ";
                temp = temp % (int)pow(2, 15-j);//temp���H2��(15-i)���誺�l��
            }
            cout << endl;

        }

        for(int i=1 ; i<=100000000 ; i++);//���{������A�n���Ȱ��@�Ǯɶ�
    }
}
