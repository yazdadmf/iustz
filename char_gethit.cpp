void getHit(int DAM, int bodypart) {
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

    
}
