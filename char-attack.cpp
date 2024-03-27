 void attack(nonfreindly* enemy){
		int DAM=selah.use();
        int Aim1=Aim;
        Aim1*=moddifier("Aim");
    	int aim_chance = generateRandomNumber(Aim1);
        int bodypart;
        if(stamina != 0){
	        if(selah.durability>0){
	        	if (aim_chance==0) { //miss
	        	cout<<"missed"<<endl;
	           	bodypart = 0;
	           	return ;
				}
		        else if (aim_chance < 4){ //feet
		           	bodypart = 1;
		           	//effect
				}
		        else if (aim_chance < 10){ //body
		            bodypart = 2;
		            //effect
				}
				else if (aim_chance == 10){ //head
					bodypart = 3;
					//effect
				}
		        
				if(selah.LongRange){
                    
					cout<<"ooooooooooooooooooooo"<<endl;
		            DAM=DAM+DAM*(bodypart*0.2);
		            if(enemy->type=="zombie"){
                    Zombie* enemy1=dynamic_cast<Zombie*>(enemy);
                    cout<<"player delt"<<DAM<<endl;
		            enemy1->gethit(DAM,bodypart);}
	        	}
		        
		        else{
                    //nesfe
                    DAM*=moddifier("streght");
		        	//effect
		            DAM=DAM+(Strength*0.1)*DAM+(bodypart*0.05)*DAM;
		            if(rand()%4){
                        //counter zombie
                    }
                   if(enemy->type=="zombie"){
                    Zombie* enemy1=dynamic_cast<Zombie*>(enemy);
                    cout<<"player delt"<<DAM<<endl;
		            enemy1->gethit(DAM,bodypart);}
	        	}
		  
	        }
	        else{
	        	DAM=10;
	         if(enemy->type=="zombie"){
                    Zombie* enemy1=dynamic_cast<Zombie*>(enemy);
		            enemy1->gethit(DAM,bodypart);}
	        	}
	        		stamina = stamina - DAM*(0.5);
			}}
		
