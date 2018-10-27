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
	string dechiffrement(string bloc);
	
	// G�n�ration de la sous-cl� Kn+1 a partir de la cl� K
	string genSousCle(string cle, int nbTours);

	// Dechiffrement de la cl� a partir de la sous cl�
	string dechiffrementCle(string cle, int nbTours);

	string getCleFinal() const { return cleFinal; };

private:
	string cleFinal;
	string* tableauSousCle;
};

#endif