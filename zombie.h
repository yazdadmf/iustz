#ifndef ZOMBIE_H
#define ZOMBIE_H
#include "nonfreindly.h"
#include <vector>
#include <utility>
#include "Character.h"

class Character;
class Zombie: public nonfreindly{
	//MODEL
	public:
    
    int damagee = 10;
  
    int maxhealth;
    string weakness;
    std::vector<std::pair<int, std::string>> effects;
    std::vector<std::pair<int, std::string>> attackEffects;
    std::string block;
    std::string hint;


   Zombie(string tzname,string name="")  {
         if(tzname=="zombie."){
            id=tzname;
            damagee = 30;
            maxhealth = 120;
            health = 120;
            weakness = "";
            type = "zombie";
            discription = "Risen from the grave to kick your ass";
        }
        if(tzname=="fast zombie"){
            id=tzname;
            damagee=35;
            maxhealth=125;
            health=125;
            weakness="lower";
            type="zombie";
            discription=" This dude's like greased lightning, muscles bulging and legs moving faster than a cat on a hot tin roof.";
            hint= "Yeah, they're quick, but you know what they ain't quick at dodging? Low blows. Give 'em a good kick where the sun don't shine, and they'll be limping like a wounded puppy!";
            attackEffects={{2,"confusion"}};
        }
        if(tzname=="smart zombie"){
            id=tzname;
            damagee=25;
            maxhealth=150;
            health=150;
            weakness="head";
            type="zombie";
            discription="Picture this zombie like the undead Einstein, all serious-looking with a side of 'I've got a plan'.";
            hint= "These brainy ones might think they've got it all figured out, but a solid smack to the noggin? Lights out, pal! Keep a bat handy for these smarty-pants.";
            attackEffects={{4,"slip"}};
		}
        if(tzname=="screamer zombie"){
            id=tzname;
            damagee = 30;
            maxhealth = 130;
            health = 130;
            weakness = "";
            type = "zombie";
            discription = "You can't miss this one. Always yelling like it's got a permanent case of the Mondays. Eyes wide, mouth open, and veins popping out like it's auditioning for a horror movie.";
            hint = "That screamer? Yeah, keep your ears covered, or you'll be ringing like a church bell on Sunday! Just knock 'em out quick, and let's move on.";
            attackEffects={{3,"stun"}};
		}
        if(tzname=="body builder zombie"){
            id=tzname;
            damagee=45;
            maxhealth=140;
            health=140;
            weakness="";
            type="zombie";
            hint="we're cooked.";
            discription="Look at that body, it's a pity that she is dead now";
        }
        if(tzname=="explosive zombie"){
            id=tzname;
            damagee=50;
            maxhealth=90;
            health=90;
            weakness="fire";
            type="zombie";
            hint="boombs and fire arent the best of friends now are they";
            discription="you have to be careful aroud this ones if he gets so close to you he says <<allahoo akbarrrr   boom>>";
            attackEffects={{1,"boom"}};
        }
        if(tzname=="A zombie who didn't eat breakfast"){
            id=tzname;
            damagee=35;
            maxhealth=100;
            health=100;
            weakness="a";
            type="zombie";
            hint="This zombie has not eaten breakfast and her mouth smells like a dead dog, her breath is poisonous, be careful not to be too close to her";
           discription=" Looks like it skipped breakfast, lunch, and dinner for a decade. Pale, skinny, and with breath that could wilt flowers at twenty paces.";
        }
        if(tzname=="dancer zombie"){
            id=tzname;
            damagee=20;
            maxhealth=120;
            health=120;
            weakness="lower";
            type="zombie";
            discription="he is such a good dancer be i bet he would love some Electric guitar";
            hint="he sure has fast feet doesnt it would be a shame if someone shot them.";
            attackEffects={{5,"Aim-"},{5,"Aim-"},{5,"Aim-"},{5,"Aim-"}};
            
        }
     if(tzname=="Conjoined twins"){
            id=tzname;
            damagee=20;
            maxhealth=220;
            health=220;
            weakness="";
            type="zombie";
            discription="the fuck is that ?";
            hint="idk ?!!?!?!!";
      
		}
		
        if(tzname=="Nigger zombie"){
            id=tzname;
            damagee=40;
            maxhealth=150;
            health=150;
            weakness="";
            type="zombie";
            discription="Because of working in the cotton fields, he has a strong physique and always carries his sickle with her, be careful not to throw it at you.";
            hint="whip that son of a bitch.";
           
		}
		if(tzname=="zombie succubus"){
            id=tzname;
            damagee=30;
            maxhealth=130;
            health=130;
            weakness="freeze";
            type="zombie";
            discription="if you get deceived by this beautiful creature, you will be confused for several turns";
            hint="";
        }
		if(tzname=="bin Laden zombie"){
            id=tzname;
            damagee=30;
            maxhealth=100;
            health=100;
            weakness="";
            type="zombie";
            discription="The killer of the twins wants to kill yus now";
            hint="doenst seem that strong.";
        }
        
        if(tzname=="Zombie batman"){
            id=tzname;
            damagee = 40 ;
            maxhealth = 200 ;
            health = 200 ;
            weakness = "";
            type = "zombie";
            discription = "a tortured, brooding vigilante dressed as a bat who fights against evil and strikes fear into the hearts of criminals everywhere,never meet your heroes";
            hint = "";
		}
      
    }

    void addeffects(vector<pair<int,string>> neew){
    	effects.insert(effects.end(),neew.begin(),neew.end());
	}
	  void gethit(int Dam,int bodypart) ;
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
    void displaystatus() override {
        View view;
        view.displayStatus(id,health,maxhealth,effects);
    }
    void effectsString(){
        View view;
        view.effectsString(effects);
    }
    class Controller {
    public:
        void attack(Character& char1,std::vector<std::pair<int, std::string>> attackeffects,Zombie& zombie,std::vector<std::pair<int, std::string>> effects);
	    void applyEffects(Zombie& zombie,std::vector<std::pair<int, std::string>> effects){
	    	
	        int damage=0;
	        
		    for (int i=0;i<effects.size();i++) {
		       
	            if(effects[i].first>0){
		        string effectName = effects[i].second;
		
		        if (effectName == "fire") {
		           
		                damage += 5;
		        } 
				else if (effectName == "freeze") {
		            damage += 4;
		        } 
	            effects[i].first-=1;}
	            else{
	                 effects.erase(effects.begin() + i);
	                 i--;
	            }
		    }
	        zombie.health-=damage;
	        if(zombie.health>0){}
	        else{zombie.health=0;}}
	    void getHit(int DAM, int bodypart,Zombie& zombie){
        int damageTaken=DAM;
    
        if(rand()%10==0){ damageTaken*=0.7;
        cout<<"-"<<zombie.id<<" Blocked"<<endl;}
        switch (bodypart) {
	        case 1:
	            if (zombie.weakness == "head") {
	                damageTaken *= 2;
	            }
	            std::cout << "- " << zombie.id << " took ";
	            color(std::to_string(damageTaken), "red");
	            std::cout << " damage to the head!" << std::endl;
	            break;
	        case 2:
	            if (zombie.weakness == "middle") {
	                damageTaken *= 2;
	            }
	            std::cout << "- " << zombie.id << " took ";
	            color(std::to_string(damageTaken), "red");
	            std::cout << " damage to the body!" << std::endl;
	            break;
	        case 3:
	            if (zombie.weakness == "lower") {
	                damageTaken *= 2;
	            }
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
        zombie.health-= damageTaken;
    }
	    void gethit1(unique_ptr<Throwables>& thrown,Zombie& zombie){
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
	                cout<<"-zombie is stuned";
	                ret=0;
	            }
	            else if((effects[i].second=="slip")){
	                if(!(rand()%4)){cout<<"-zombie sliped";ret=0;}
	            }
	            else if((effects[i].second=="confusion")){
	                if(!(rand()%2)){cout<<"-zombie is confused";ret=0.5;}
	            }
	        }
	        return ret;
	    }
		};
    
    void attack(Character& character) override{
        Controller controller;
        controller.attack(character,attackEffects, *this,effects);
    }
  
    void gethit1(unique_ptr<Throwables>& thrown) override {Controller controller; controller.gethit1(thrown,*this);}
    void applyeffects() override{
        Controller controller; controller.applyEffects(*this,effects);
    }
};
void Zombie::gethit(int Dam,int bodypart) {
        Controller controller; controller.getHit(Dam,bodypart,*this);
    }

#endif // ZOMBIE_H