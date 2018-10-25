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
	
	// G�n�ration de la sous-cl� Kn+1 a partir de la cl� K
	std::string genSousCle(std::string cle, int nbTours);

	// Dechiffrement de la cl� a partir de la sous cl�
	std::string dechiffrementCle(std::string cle, int nbTours);
};

#endif