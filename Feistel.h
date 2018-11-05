#ifndef FEISTEL_H
#define FEISTEL_H

#include "Vigenere.h"

class Feistel
{
public:
	Feistel();
	~Feistel();

	// Chiffrement par reseau de feistel
	string chiffrement(string bloc, string cle);
	
	// Dechiffrement par reseau de Feistel
	string dechiffrement(string bloc, string cle);
	
	// G�n�ration de la sous-cl� Kn+1 a partir de la cl� K
	string genSousCle(string cle, int nbTours);

private:
	string* tableauSousCle;
};

#endif