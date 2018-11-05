#ifndef COUNTER_H
#define COUNTER_H

#include <string>
#include <iostream>

using namespace std;

class Counter
{
public:
	Counter();
	~Counter();

	// Retourne le message d�coup� en blocs
	string* getDecoupageBlocs() const { return decoupageBlocs; };

	// Retourne les blocs chiffr�s
	string* getBlocsChiffres() const { return blocsChiffres; };

	// Retourne les blocs d�chiffr�s
	string getTexteDechiffre() const { return texteDechiffre; };

	// D�coupe le message en blocs de m�me taille
	void decouperBlocs(string message);

	// Chiffre la cl�
	void chiffrementCle(string cle);

	// D�coupe le message, chiffre la cl� puis chiffre le message
	void counterMode(string message, string cle);

	// D�chiffre les blocs
	void dechiffrerBlocs(string messageChiffre[20], string cle);

	int nombreBlocs;

private:
	string* decoupageBlocs;
	string* cleChiffrees;
	string* blocsChiffres;
	string texteChiffre;
	string texteDechiffre;
};

#endif