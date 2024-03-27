  void Character::displayStatus() {
        cout << "name: " << name << " | HP: ";
        barandnumber(HP, Health * 20, "red", 10); 
        cout<< " | stamina: ";
        barandnumber(stamina, vigor * 20, "cyan", 10); 
        cout<<endl;
        effectsstring();
    }
void CHaracter::effectsstring() {
 
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
}
