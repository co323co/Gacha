class Inventory;
class Item;

class Equipment
{
public:
	Item* head;
	Item* weapon;
	Item* armor;
	Inventory* inven;
	Equipment(Inventory* inventory);
	void putOnEuipment();
	void takeOffEuipment();
	void print();
};

