#include "Vigenere.h"



Vigenere::Vigenere(string _message)
{
	message = _message;
	messageCode = _message;
}


Vigenere::~Vigenere()
{
}

void Vigenere::crypter(string cle)
{
	int tailleCle = cle.length();
	int tailleMessage = message.length();
	int i;

	for (i = 0;i < tailleMessage; i++)
	{
		messageCode[i] = (message[i] + cle[i%tailleCle]) % 127;
	}
}

void Vigenere::decrypter(string cle)
{
	int tailleCle = cle.length();
	int tailleMessage = messageCode.length();
	int i;

	messageDecode = messageCode;

	for (i = 0;i < tailleMessage; i++)
	{
		messageDecode[i] = (127 + messageCode[i] - cle[i%tailleCle]) % 127;
	}
}