#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;


class Item {
public:
	string id;
	string type ;
    string detail;
	int price=100;
	virtual ~Item() {}

};
#endif // ITEM_H