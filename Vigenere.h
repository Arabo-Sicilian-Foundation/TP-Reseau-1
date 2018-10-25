#ifndef VIGENERE_H
#define VIGENERE_H

#include "Hash.h"

class Vigenere
{
public:
	Vigenere(string _message);
	~Vigenere();
	string getMessageCode() const { return messageCode; };
	string getMessageDecode() const { return messageDecode; };
	void crypter(string cle);
	void decrypter(string cle);

private:
	string messageCode;
	string messageDecode;
	string message;
};

#endif