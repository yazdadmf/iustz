void Shop::scrollThroughBuyInventory(Party& party) {
    const int itemsPerPage = 5;
    size_t currentPage = 0;

    while (true) {
        system("cls");
        cout << "Shop Inventory (Page " << currentPage + 1 << "):" << endl;
        for (size_t i = currentPage * itemsPerPage; i < min((currentPage + 1) * itemsPerPage, inventory.size()); ++i) {
           color("┌───────┬─────────────────────┬───────────────────┐" ,"cyan");
		   cout<< endl;
            color("│ ","cyan"); 
			cout<< setw(6) <<left<< i + 1;
			 color("│ ","cyan");
			cout<<setw(20) << left << inventory[i]->id ;
			 color("│ ","cyan");
            // Type casting and getting the price
            if (dynamic_cast<Meds*>(inventory[i])) {
            	
                cout << "Price: " << setw(10) << dynamic_cast<Meds*>(inventory[i])->getPrice();
				 color(" │ ","cyan"); 
				 cout<< endl;
            } else if (dynamic_cast<Weapon*>(inventory[i])) {
                cout << "Price: " << setw(10) << dynamic_cast<Weapon*>(inventory[i])->getPrice();
				color(" │ ","cyan");
				cout<< endl;
            } else if (dynamic_cast<Throwables*>(inventory[i])) {
                cout << "Price: " << setw(10) << dynamic_cast<Throwables*>(inventory[i])->getPrice();
				 color(" │ ","cyan");
				 cout << endl;
            } else if (dynamic_cast<Armor*>(inventory[i])) {
                cout << "Price: " << setw(10) << dynamic_cast<Armor*>(inventory[i])->getPrice();
                color(" │ ","cyan");
				 cout << endl;
            }
             color("└───────┴─────────────────────┴───────────────────┘","cyan");
			 cout << endl;
        }
        cout << "Enter 'next' to see next page, 'prev' to see previous page, or type 'back' to return to main menu: ";
        string inputStr;
        cin >> inputStr;
        if (inputStr == "back") {
            break;
        } else if (inputStr == "next") {
            ++currentPage;
            if (currentPage * itemsPerPage >= inventory.size()) {
                currentPage = 0;
            }
        } else if (inputStr == "prev") {
            if (currentPage == 0) {
                currentPage = (inventory.size() - 1) / itemsPerPage;
            } else {
                --currentPage;
            }
        }else{
            buyItem(party,stoi(inputStr)-1);
        }
    }
}
void	 Shop::scrollThroughSellInventory(Party& party) {
         const int itemsPerPage = 5;
    size_t currentPage = 0;

    while (true) {
        system("cls");
        cout << "your Inventory (Page " << currentPage + 1 << "):" << endl;
       for (size_t i = currentPage * itemsPerPage; i < min((currentPage + 1) * itemsPerPage, party.inventory.size()); ++i) {
           color("┌───────┬─────────────────────┬───────────────────┐" ,"cyan");
		   cout<< endl;
            color("│ ","cyan"); 
			cout<< setw(6) <<left<< i + 1;
			 color("│ ","cyan");
			cout<<setw(20) << left <<  party.inventory[i]->id ;
			 color("│ ","cyan");
            // Type casting and getting the price
            if (dynamic_cast<Meds*>( party.inventory[i])) {
            	
                cout << "Price: " << setw(10) << dynamic_cast<Meds*>( party.inventory[i])->getPrice();
				 color(" │ ","cyan"); 
				 cout<< endl;
            } else if (dynamic_cast<Weapon*>( party.inventory[i])) {
                cout << "Price: " << setw(10) << dynamic_cast<Weapon*>( party.inventory[i])->getPrice();
				color(" │ ","cyan");
				cout<< endl;
            } else if (dynamic_cast<Throwables*>( party.inventory[i])) {
                cout << "Price: " << setw(10) << dynamic_cast<Throwables*>( party.inventory[i])->getPrice();
				 color(" │ ","cyan");
				 cout << endl;
            } else if (dynamic_cast<Armor*>( party.inventory[i])) {
                cout << "Price: " << setw(10) << dynamic_cast<Armor*>( party.inventory[i])->getPrice();
                color(" │ ","cyan");
				 cout << endl;
            }
             color("└───────┴─────────────────────┴───────────────────┘","cyan");
			 cout << endl;
        }
        cout << "Enter 'next' to see next page, 'prev' to see previous page, or type 'back' to return to main menu: ";
        string inputStr;
        cin >> inputStr;
        if (inputStr == "back") {
            break;
        } else if (inputStr == "next") {
            ++currentPage;
            if (currentPage * itemsPerPage >= inventory.size()) {
                currentPage = 0;
            }
        } else if (inputStr == "prev") {
            if (currentPage == 0) {
                currentPage = (inventory.size() - 1) / itemsPerPage;
            } else {
                --currentPage;
            }
        }
        else{
            sellItem(party,stoi(inputStr)-1);
        }
    }
    }
