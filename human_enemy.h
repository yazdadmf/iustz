#ifndef Henemy_H
#define Henemy_H


#include <vector>
#include <string>
#include <cstdlib>

#include "Character.h"
#include "nonfreindly.h"

using namespace std;



class Character;
class nonfreindly;


class Human_enemy: public nonfreindly  {
    public:
        int HP = 250;
        int maxHP = 250;
        int stamina;
        Throwables throwables;
        std::vector<std::pair<int, std::string>> effects;
        Weapon weapon;
        string id;
    	int damagee;
    	string type;
    Human_enemy(string tzname){
	if(tzname=="police officer"){
    id=tzname;
    damagee=30;
    maxHP=240;
    HP=240;
    string a="pistol";
    weapon=Weapon(a);
    throwables=Throwables("grenade");
    type="human";
    discription="A dedicated police officer patrolling the streets, upholding law and order with unwavering determination. Clad in a crisp uniform, this officer embodies bravery and commitment to serving and protecting the community.";
    stamina = 120;
}
if(tzname=="handicap old man"){
    id=tzname;
    damagee=35;
    maxHP=200;
    HP=200;
    string a="Cane";
    weapon=Weapon(a);
    throwables=Throwables("slippers");
    type="human";
    discription="An elderly man, weathered by time and life's challenges, yet carrying a wealth of experience and wisdom. Despite physical limitations, his spirit remains unbroken, offering insights and guidance to those who cross his path.";
    stamina = 100;
	}
if(tzname=="vladimir putin"){
    id=tzname;
    damagee=40;
    maxHP=250;
    HP=250;
    string a="AK-47";
    weapon=Weapon(a);
    throwables=Throwables("molotov");
    type="human";
    discription="Vladimir Putin, the enigmatic leader of Russia, known for his strong leadership and strategic prowess. He commands respect and fear in equal measure, navigating the complexities of international politics with a steely resolve.";
    stamina = 170;
}
if(tzname=="kazem forghani"){
    id=tzname;
    damagee=50;
    maxHP=120;
    HP=120;
    string a="shocker";
    weapon=Weapon(a);
    throwables=Throwables("oxford dictionary");
    type="human";
    discription="Kazem Forghani, The homework he gives you makes you want to commit suicide";
    stamina = 130;
}
if(tzname=="Mr.X"){
    id=tzname;
    damagee=30;
    maxHP=220;
    HP=220;
    string a="Whip";
    weapon=Weapon(a);
    type="human";
    throwables=Throwables("rock");
    discription="Mr. X, a mysterious figure lurking in the shadows, his true identity concealed behind a veil of secrecy. He operates with calculated precision, manipulating events from behind the scenes.";
    stamina = 150;
}
if(tzname=="Soilder guy"){
    id=tzname;
    damagee=25;
    maxHP=260;
    HP=260;
    string a="Machine gun";
    weapon=Weapon(a);
    throwables=Throwables("grenade");
    type="human";
    discription="Captain Price, a battle-hardened soldier with years of combat experience. Leading by example, he inspires loyalty and camaraderie among his troops, facing danger head-on with unwavering courage.";
    stamina = 140;
}
if(tzname=="THE shop keeper"){
    id=tzname;
    damagee=20;
    maxHP=160;
    HP=160;
    string a="stapler";
    weapon=Weapon(a);
    throwables=Throwables("batrang");
    type="human";
    discription="A humble shopkeeper, running a quaint store filled with treasures and trinkets from distant lands. With a warm smile, he welcomes travelers, eager to share stories of his adventures.";
    stamina = 100;
}

if(tzname=="Drunk teenager"){
    id=tzname;
    damagee=20;
    maxHP=180;
    HP=180;
    string a="Wrench";
    weapon=Weapon(a);
    throwables=Throwables("molotov");
    type="human";
    discription="A reckless teenager, stumbling through life with a carefree attitude and a penchant for mischief. With a penchant for trouble, he embarks on misadventures fueled by youthful exuberance.";
    stamina = 110;
}
if(tzname=="Mario"){
    id=tzname;
    damagee=35;
    maxHP=180;
    HP=180;
    string a="Dagger";
    weapon=Weapon(a);
    throwables=Throwables("snowball");
    type="human";
    discription="Mario, a beloved plumber from the Mushroom Kingdom, known for his heroic deeds and unwavering determination to rescue Princess Peach from the clutches of Bowser. With his trusty sidekick, Luigi, he embarks on daring quests to save the day.";
    stamina = 150;
}

if(tzname=="guardian of hell"){
    id=tzname;
    damagee=40;
    maxHP=300;
    HP=300;
    string a="Whip";
    weapon=Weapon(a);
    throwables=Throwables();
    type="human";
    discription="A fearsome guardian tasked with protecting the gates of hell, wielding infernal powers to thwart intruders seeking to disturb the realm of the damned. With an ominous presence, he strikes terror into the hearts of mortals.";
    stamina = 220;
}
if(tzname=="banana man"){
    id=tzname;
    damagee=20;
    maxHP=140;
    HP=140;
    string a="Shotgun";
    weapon=Weapon(a);
    throwables=Throwables("peel of banana");
    type="human";
    discription="Banana Man, a peculiar individual with a penchant for bananas and a bizarre sense of humor. With a banana for a weapon and a smile on his face, he brings chaos and laughter wherever he goes.";
    stamina = 300;
}
if(tzname=="spartan soldier"){
    id=tzname;
    damagee=35;
    maxHP=280;
    HP=280;
    string a="bow";
    weapon=Weapon(a);
    throwables=Throwables("rock");
    type="human";
    discription="A fierce Spartan warrior, trained from birth to be a formidable fighter on the battlefield. With unwavering loyalty to Sparta, he embodies the warrior ethos, ready to lay down his life for king and country.";
    stamina = 250;
}

		}
    int getstate (){
    		return (rand() % 3 +1) * HP/maxHP;
		}
		
		
       
	      void addeffects(vector<pair<int,string>> neew){
    	effects.insert(effects.end(),neew.begin(),neew.end());
	}

    // Nested classes for View and Controller
    class View {
    public:
     

        void effectsString( std::vector<std::pair<int, std::string>> effects){
			for (int i = 0; i < effects.size(); i++) {
		        if (effects[i].second.back() == '-') {
		            cout<< "|";
		            color(effects[i].second, "red");
		        } else if (effects[i].second.back() == '+') {
		            cout<< "|";
		            color(effects[i].second, "green");
		        } else {
		            cout<< "|";
		            color(effects[i].second, "yellow");
		        }
		    }
		    cout<<endl;
		};
		   void displayStatus(string id,int health,int maxhealth,std::vector<std::pair<int, std::string>> effects){
	        cout<<"name:"<< id <<"|health:";
	        barandnumber(health,maxhealth,"magenta",10);
	        cout<<endl;
	        effectsString(effects);
    	};
    };
    void displaystatus() override{
        View view;
        view.displayStatus(id,HP,maxHP,effects);
    }
    void effectsString() {
        View view;
        view.effectsString(effects);}
    
    class Controller {
    public:
        void attack(Character& char1,std::vector<std::pair<int, std::string>> effects,Human_enemy& zombie);
	    void applyEffects(Human_enemy& zombie,std::vector<std::pair<int, std::string>> effects){
	    	
	        int damage=0;
	        
		    for (int i=0;i<effects.size();i++) {
		       
	            if(effects[i].first>0){
		        string effectName = effects[i].second;
		
		        if (effectName == "fire") {
		           
		                damage += 10;
		        } 
				else if (effectName == "freeze") {
		            damage += 5;
		        } 
	            effects[i].first-=1;}
	            else{
	                 effects.erase(effects.begin() + i);
	                 i--;
	            }
		    }
	        zombie.HP-=damage;
	        if(zombie.HP>0){}
	        else{zombie.HP=0;}}
	    void getHit(int DAM, int bodypart,Human_enemy& zombie){
        int damageTaken=DAM;
    
        if(rand()%10==0){ damageTaken*=0.7;
        cout<<"-"<<zombie.id<<"Blocked"<<endl;}
        switch (bodypart) {
	        case 1:
	           
	            std::cout << "- " << zombie.id << " took ";
	            color(std::to_string(damageTaken), "red");
	            std::cout << " damage to the head!" << std::endl;
	            break;
	        case 2:
	            
	            std::cout << "- " << zombie.id << " took ";
	            color(std::to_string(damageTaken), "red");
	            std::cout << " damage to the body!" << std::endl;
	            break;
	        case 3:
	         
	            std::cout << "- " << zombie.id << " took ";
	            color(std::to_string(damageTaken), "red");
	            std::cout << " damage to the lower body!" << std::endl;
	            break;
	        default:
	            std::cout << "- " << zombie.id << " took ";
	            color(std::to_string(damageTaken), "red");
	            std::cout << " damage!" << std::endl;
	            break;
    	}
       zombie.HP-= damageTaken;
    };
	    void gethit1(unique_ptr<Throwables>& thrown,Human_enemy& zombie){
	        zombie.gethit(thrown->instantDamage,2);
	        vector<pair<int,string>>effectsh=thrown->effects;
	        zombie.addeffects(effectsh);
	      
		} 
	    int moddifier(string stat,std::vector<std::pair<int, std::string>> effects){
	        int ret=1;
	        for(int i=0;i<effects.size();i++){
	            if(effects[i].second==stat+"+"){
	                cout<<"-applied streght moddifer";
	                ret*=1.2;
	            }
	            else if((effects[i].second==stat+"-")){
	                ret*=0.9;
	            }
	            else if((effects[i].second=="stun")){
	                cout<<"-ebemy is stuned";
	                ret=0;
	            }
	            else if((effects[i].second=="slip")){
	                if(!(rand()%4)){cout<<"-enemy sliped";ret=0;}
	            }
	            else if((effects[i].second=="confusion")){
	                if(!(rand()%2)){cout<<"-enemy is confused";ret=0.5;}
	            }
	        }
	        return ret;
	    }
		}; 
    void attack(Character& character) override{
        Controller controller;
        controller.attack(character,effects, *this);
    }
    void gethit(int Dam,int bodypart) override;
    void gethit1(unique_ptr<Throwables>& thrown) override{Controller controller; controller.gethit1(thrown,*this);}
    void applyeffects() override{
        Controller controller; controller.applyEffects(*this,effects);
    }
};

void Human_enemy::gethit(int Dam,int bodypart){
        Controller controller; controller.getHit(Dam,bodypart,*this);
    }
 
    
    
#endif
