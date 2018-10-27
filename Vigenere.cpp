#include "Vigenere.h"



Vigenere::Vigenere(string _message)
{
	message = _message;
	messageCode = _message;
}


Vigenere::~Vigenere()
{
}

// Le cryptage et le d�cryptage se basent sur la table ascii, soit des codes ascii allant de 0 � 127
// Crypte le message
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

// D�crypte le message
void Vigenere::decrypter(string cle)
{
	int tailleCle = cle.length();
	int tailleMessage = messageCode.length();
	int i;

	messageDecode = messageCode; // Permet seulement de cr�er un messageDecode de la bonne taille

	for (i = 0;i < tailleMessage; i++)
	{
		messageDecode[i] = (381 + messageCode[i] - cle[i%tailleCle]) % 127;
	}
}