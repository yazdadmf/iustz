void Character::getHit(int DAM, int bodypart) {
    int damageTaken = DAM;

    // Apply defense reduction based on the body part being hit
    switch (bodypart) {
        case 1:
            damageTaken -= head.getDefense();
            break;
        case 2:
            damageTaken -= middle.getDefense();
            break;
        case 3:
            damageTaken -= lower.getDefense();
            break;
    }

    // Apply additional reductions if the character is defending
    if (defending) {
        damageTaken *= 0.8;
    }

    // Ensure that damage taken is not negative
    damageTaken = max(0, damageTaken);

    // Deduct the damage from the character's health
    HP -= damageTaken;

    // Ensure that HP doesn't go below 0
    HP = max(0, HP);

    cout << endl << "Damage taken: " << HP << endl;
}
