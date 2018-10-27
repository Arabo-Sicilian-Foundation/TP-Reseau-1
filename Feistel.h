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
	
	// Génération de la sous-clé Kn+1 a partir de la clé K
	string genSousCle(string cle, int nbTours);

	// Dechiffrement de la clé a partir de la sous clé
	string dechiffrementCle(string cle, int nbTours);

	string getCleFinal() const { return cleFinal; };

private:
	string cleFinal;
	string* tableauSousCle;
};

#endif