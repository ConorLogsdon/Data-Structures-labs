/*
#include "hash.h"
HashMap::HashMap(int size) 
{
return size;	//33*x+b
}
HashMap::~HashMap() {}
...
*/

#include<iostream>
#include "hash.h"
using namespace std;

const int TABLE_SIZE = 128; // size of hash table.

class Overflow {};
HashMap::HashMap(int size)
{
	
}
HashMap::~HashMap()
{

}
unsigned long myHash(string str)
{
	const char* cstr = str.c_str();
}
void put(Entry* e);
Entry* get(string key);
Entry* remove(string key);