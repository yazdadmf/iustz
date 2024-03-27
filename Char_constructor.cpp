 Character(string namee, string characterClass) {
        name = namee;
        if (characterClass == "tank") {
            Health = 7;
            vigor = 5;
            Strength = 7;
            Aim = 1;
            Knowledge = 0;
            level=20;
            HP=7*20;
            stamina=5*20;
        }
    };
Character(int god) {
    if (god == 1) {
        name = "jeff1";

        Health = 7;
        vigor = 5;
        Strength = 7;
        Aim = 1;
        Knowledge = 0;
        level = 20;
        HP = 7 * 20;
        stamina = 5 * 20;
        selah = Weapon("gun");
        head = Armor("naked1");
        middle = Armor("naked2");
        lower = Armor("naked3");
    } else {
        name = "jeff2";
   
        Health = 7;
        vigor = 5;
        Strength = 7;
        Aim = 1;
        Knowledge = 0;
        level = 20;
        HP = 7 * 20;
        stamina = 5 * 20;
        selah = Weapon("sword");
        head = Armor("naked1");
        middle = Armor("naked2");
        lower = Armor("naked3");
    }};
