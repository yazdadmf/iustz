void Character::applyEffects() {
        int damage = 0;
        for (int i = 0; i < effects.size(); i++) {
            if (effects[i].first > 1) {
                string effectName = effects[i].second;

                if (effectName == "fire") {
                    damage += 5;
                } else if (effectName == "PoisonDamage") {
                    damage += 4;
                }
                effects[i].first -= 1;

                if (effects[i].first == 0) {
                    effects.erase(effects.begin() + i);
                    i--; // Adjust index after erasing element
                }
            }
        }
        HP -= damage;
        if (HP < 0) {
            HP = 0;
        }
    }
