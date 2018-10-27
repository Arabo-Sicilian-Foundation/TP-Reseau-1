#include "Hash.h"
#include "Counter.h"
#include "Vigenere.h"
#include "Feistel.h"

int main() {
	int i;
	Feistel feistel;
	Counter ctr;
	string cle = "cleeeeee";
	string* blocs = new string[20];
	string* blocsChiffres = new string[20];
	string* blocsDechiffres = new string[20];

	ctr.counterMode("Bonjoure", "Cletressecurisee");
	blocs = ctr.getTexteChiffre();
	for (i = 0;i < ctr.nombreBlocs;i++)
	{
		blocsChiffres[i] = feistel.chiffrement(blocs[i], cle);
	}
	for (i = 0;i < ctr.nombreBlocs;i++)
	{
		blocsDechiffres[i] = feistel.dechiffrement(blocsChiffres[i]);
		cout << blocsDechiffres[i] << endl;
	}
	ctr.dechiffrerBlocs();
	cin >> i;
	return 0;
}