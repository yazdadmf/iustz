	void Character::useMeds(Meds* meds) {
		vector<pair<int,string>> eff=meds->boosts;
        addeffects(eff);
        if(meds->onUse.second=="stamina"){
            stamina+=meds->onUse.first;
            if(stamina>vigor*20){stamina=vigor*20;}


        }
         if(meds->onUse.second=="health"){
            HP+=meds->onUse.first;
            if(HP>Health*20){HP=Health*20;}
        }
	    // az aval
       
