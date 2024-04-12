#ifndef NONFREINDLY_H
#define NONFREINDLY_H
#include"character.h"

#include <string>
#include <vector>
class Character;
class Throwables;
using namespace std;
class nonfreindly{
	public:
	int health;
	string id;
	string hint="";
	string discription;

	
	virtual void displaystatus(){
	}
	virtual void gethit(int DAM,int bodypart) {
	}
	virtual void gethit1(unique_ptr<Throwables>& thrown) {
}
	virtual void attack(Character& character){
		
	}
	virtual void applyeffects(){
		
	}
    public:
    virtual ~nonfreindly() {}
	string type;
	string gettype(){return type;}
};


#endif // NONFREINDLY_H
