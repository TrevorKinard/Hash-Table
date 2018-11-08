#ifndef _Hash_Table_
#define _Hash_Table_

//Work to remove this to source only
#include <iostream>

//Hash Table
template<typename K, typename V>
class HashTable
{
	//Key Value Node
	struct Hash
	{
		K key;
		V value;
	};

public:
	HashTable()
	{
		//Initial capacity of hash table 
		capacity = 20;
		size = 0;
		table = new Hash *[capacity];

		//Initialise all elements of table as NULL 
		for (int i = 0; i < capacity; i++)
			table[i] = NULL;

		//blank node with value and key -1 
		blank = new Hash{ -1, -1 };
	}
	 
	// Hash the key
	int hashing(K key)
	{
		return key % capacity;
	}

	//Function to add key value pair 
	void insertNode(K key, V value)
	{
		// Apply hash function to find index for given key 
		int index = hashing(key);

		//find next free space 
		while (table[index] != NULL && table[index]->key != key
			&& table[index]->key != -1)
		{
			index++;
			index %= capacity;
		}

		//if new node to be inserted increase the table current size 
		if (table[index] == NULL || table[index]->key == -1)
			size++;
		table[index] = new Hash{ key, value };;
	}

	//Function to delete a key value pair 
	V deleteNode(int key)
	{
		// Apply hash function to find index for given key 
		int index = hashing(key);

		//finding the node with given key 
		while (table[index] != NULL)
		{
			//if node found 
			if (table[index]->key == key)
			{
				//Insert blank node here for further use 
				table[index] = blank;

				// Reduce size 
				size--;
				return table[index]->value;
			}
			index++;
			index %= capacity;

		}

		//If not found return null 
		return NULL;
	}

	//Function to search the value for a given key 
	V get(int key)
	{
		// Apply hash function to find index for given key 
		int index = hashing(key);
		int counter = 0;
		//finding the node with given key 
		while (table[index] != NULL)
		{
			int counter = 0;
			//Break if reached bounds of array
			if (counter++ > capacity)
				return NULL;
			//if node found return its value 
			if (table[index]->key == key)
				return table[index]->value;
			index++;
			index %= capacity;
		}

		//If not found return null 
		return NULL;
	}

	//Return current size 
	int sizeofTable()
	{
		return size;
	}

	//Check to see size is zero
	bool isEmpty()
	{
		return size == 0;
	}

	//Function to display the stored key value pairs 
	void display()
	{
		for (int i = 0; i<capacity; i++)
		{
			if (table[i] != NULL && table[i]->key != -1)
				std::cout << "key = " << table[i]->key
				<< " value = " << table[i]->value << std::endl;
		}
	}

private:
	//hash element table
	Hash **table;
	int capacity;
	//current size 
	int size;
	//blank node 
	Hash *blank;
};
#endif