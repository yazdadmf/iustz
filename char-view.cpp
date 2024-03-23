  void Character::displayStatus() {
        cout << "name: " << name << " | HP: ";
        barandnumber(HP, Health * 20, "red", 10); 
        cout<< " | stamina: ";
        barandnumber(stamina, vigor * 20, "cyan", 10); 
        cout<<endl;
        effectsstring();
    }
