#include "knight2.h"

/* * * BEGIN implementation of class Events * * */
Events::Events(const string& file_Events){
     
    
    ifstream infile;
    infile.open(file_Events);
    string str1, str2;
    getline(infile, str1);
    istringstream s1(str1); s1 >> event_num;
    getline(infile, str2);
    event = new int[event_num];

    getline(infile, str2);
    istringstream s2(str2);
    for (int  i = 0; i < event_num; i++){
        s2 >> event[i];
    }
    for (int i = 0; i< event_num; i++){
        cout << event[i] << " ";
    }
}

int Events::count() const{
    return event_num;
}

int Events::get(int i) const{
    return event[i];
}

Events::~Events(){
    delete[] event;
}
/* * * END implementation of class Events * * */

/* * * BEGIN implementation of class BaseBag * * */

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */


BaseKnight * BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
    BaseKnight * x;

}

string BaseKnight::toString() const {
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) 
        + ",hp:" + to_string(hp) 
        + ",maxhp:" + to_string(maxhp)
        + ",level:" + to_string(level)
        + ",gil:" + to_string(gil)
        + "," + bag->toString()
        + ",knight_type:" + typeString[knightType]
        + "]";
    return s;
}

/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
ArmyKnights::ArmyKnights (const string & file_armyknights){
    ifstream infile;
    infile.open(file_armyknights);
    string str1, str2;
    getline(infile, str1);
    istringstream s1(str1);
    int n; 
    s1 >> n;
    KnightsList = new ArmyKnightStatistic[n];
    for (int i = 0; i < n; i++){
        infile >> KnightsList[i].HP >> KnightsList[i].phoenixdownI >> KnightsList[i].gil >> KnightsList[i].antidote;
        KnightsList[i].id = i + 1;
    }
    for (int i = 0; i < n; i++){
        cout << KnightsList[i].id << " " << KnightsList[i].HP << " " << KnightsList[i].phoenixdownI 
        << " " << KnightsList[i].gil << " " << KnightsList[i].antidote << endl;
    }
}

ArmyKnights::~ArmyKnights(){
    
}


bool ArmyKnights::hasPaladinShield() const{
    return 0;
}
bool ArmyKnights::hasLancelotSpear() const{
    return 0;
}
bool ArmyKnights::hasGuinevereHair() const{
    return 0;
}
bool ArmyKnights::hasExcaliburSword() const{
    return 0;
}

BaseKnight * ArmyKnights::lastKnight() const{
    return 0;
}

int ArmyKnights::count() const{
    return 0;
}

void ArmyKnights::printInfo() const {
    cout << "No. knights: " << this->count();
    if (this->count() > 0) {
        BaseKnight * lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}

/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}

KnightAdventure::~KnightAdventure(){}

void KnightAdventure::loadArmyKnights(const string & file_armyknights){
    ArmyKnights x(file_armyknights);

    BaseKnight x;
    x->create(ArmyKnights -> Knightlist)
}

void KnightAdventure::loadEvents(const string & file_Events){
    Events x(file_Events);
}

void KnightAdventure::run(){

}


/* * * END implementation of class KnightAdventure * * */