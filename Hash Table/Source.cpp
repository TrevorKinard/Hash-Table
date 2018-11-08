#include "HashTable.h"

//Driver method to test map class 
int main()
{
	HashTable<int, int> *table = new HashTable<int, int>;
	table->insertNode(1, 1);
	table->insertNode(2, 2);
	table->insertNode(2, 3);
	table->display();
	std::cout << table->sizeofTable() << std::endl;
	std::cout << table->deleteNode(2) << std::endl;
	std::cout << table->sizeofTable() << std::endl;
	std::cout << table->isEmpty() << std::endl;
	std::cout << table->get(2) << std::endl;
	system("pause");
	return 0;
}
