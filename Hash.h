#ifndef HASH_H
#define HASH_H

#include <string>
#include <iostream>

using namespace std;

class Hash
{
public:
	Hash();
	~Hash();
	void fonctionHachage(string messageClair);
	string getMessageHacher() const { return messageHacher; };
private:
	string messageHacher;
};

#endif