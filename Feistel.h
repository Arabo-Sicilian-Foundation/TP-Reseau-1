#ifndef FEISTEL_H
#define FEISTEL_H

#include <string>
#include "Vigenere.h"

class Feistel
{
public:
	Feistel();
	~Feistel();

	// Chiffrement par reseau de feistel
	std::string chiffrement(std::string bloc, std::string cle);
	
	// Dechiffrement par reseau de Feistel
	std::string dechiffrement(std::string bloc, std::string cle);
	
	// Génération de la sous-clé Kn+1 a partir de la clé K
	std::string genSousCle(std::string cle, int nbTours);

	// Dechiffrement de la clé a partir de la sous clé
	std::string dechiffrementCle(std::string cle, int nbTours);
};

#endif