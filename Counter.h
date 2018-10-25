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
	string* getDecoupageBlocs() const { return decoupageBlocs; };
	string* getTexteChiffre() const { return texteChiffre; };
	string* getTexteDechiffre() const { return texteDechiffre; };
	int getNombreBlocs() const { return nombreBlocs; };
	void decouperBlocs(string message);
	void chiffrementCle(string cle);
	void counterMode(string message, string cle);
	void dechiffrerBlocs();
private:
	int nombreBlocs;
	string* decoupageBlocs;
	string* cleChiffrees;
	string* texteChiffre;
	string* texteDechiffre;
};

#endif