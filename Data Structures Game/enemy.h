#ifndef ENEMY_H
#define ENEMY_H
#include <string>

//class enemy {
//public:
//	//members
//	int health;
//	int strength;
//	std::string name;
//	
//public:
//	//constructors
//	enemy(int battleHealth, int str, std::string Nname);
//	//getters
//	int getHealth();
//	int getStrength();
//	std::string getName();
//	//setters
//	void setHealth(int newHealth);
//
//	//methods]
//	int randomAtkValue();
//};
//
//class goblin : public enemy {
//
//public:
//	//members
//	
//public:
//	//constructors
//	goblin(int battleHealth, int str, std::string Nname);
//	//getters
//
//	//setters
//
//	//methods
//
//
//
//
//};
class enemy {
public:
    int health;
    int strength;
    std::string name;

public:
    enemy(int battleHealth, int str, std::string Nname);
    int getHealth();
    int getStrength();
    std::string getName();
    void setHealth(int newHealth);
    virtual int randomAtkValue();
};

class goblin : public enemy {
public:
    goblin(int battleHealth, int str, std::string Nname);
};

class wizard : public enemy {
public:
    wizard(int battleHealth, int str, std::string Nname);
    int randomAtkValue() override;
};

class orc : public enemy {
public:
    orc(int battleHealth, int str, std::string Nname);
};

class dragon : public enemy {
public:
    dragon(int battleHealth, int str, std::string Nname);
    int randomAtkValue() override;
};

#endif