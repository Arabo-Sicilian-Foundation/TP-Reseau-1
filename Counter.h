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

	// Retourne le message découpé en blocs
	string* getDecoupageBlocs() const { return decoupageBlocs; };

	// Retourne les blocs chiffrés
	string* getBlocsChiffres() const { return blocsChiffres; };

	// Retourne les blocs déchiffrés
	string getTexteDechiffre() const { return texteDechiffre; };

	// Découpe le message en blocs de même taille
	void decouperBlocs(string message);

	// Chiffre la clé
	void chiffrementCle(string cle);

	// Découpe le message, chiffre la clé puis chiffre le message
	void counterMode(string message, string cle);

	// Déchiffre les blocs
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