int Character::moddifier(string stat){
        int ret=1;
        for(int i=0;i<effects.size();i++){
            if(effects[i].second==stat+"+"){
                ret*=1.2;
            }
            else if((effects[i].second==stat+"-")){
                ret*=0.9;
            }
            else if((effects[i].second=="stun")){
                ret=0;
            }
        }
        return ret;
    }