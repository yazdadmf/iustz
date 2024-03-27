class Character {
public:
    int stamina;
    int vigor, Aim, Strength, Knowledge;
    int level;
    bool defending = false;
    Weapon selah;
    Armor head, middle, lower;
    vector<pair<int, string>> effects;
	int HP;
	int Health;

	string name;
    Character(string namee, string characterClass) 
    };
Character(int god) 
    void displayStatus() 
void effectsstring() 

    void applyEffects()
       
    
void getHit(int DAM, int bodypart) 

    //****************be careful that aim must be under 10 range****************
    int generateRandomNumber(int aim) {random_device rd;mt19937 gen(rd()); uniform_int_distribution<> distrib(aim, 10); return distrib(gen);}
    void addeffects(vector<pair<int, string>> neew){effects.insert(effects.end(), neew.begin(), neew.end());}
    
   void attack(nonfreindly* enemy)
		
    	
	
    
	void useMeds(Meds* meds) 
    
    int moddifier(string stat)
	

	
    void equiparmor(){}
    void equipWeapon(){}
    void checkforlevelup(){}
    void levelup(){}
};
