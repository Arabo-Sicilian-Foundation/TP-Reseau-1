#include "Hash.h"
#include "Counter.h"
#include "Vigenere.h"

int main() {
	int i;
	Counter ctr;
	Vigenere vig("Message");
	string cle = "cle";

	//ctr.counterMode("BonjoureBonjoureBisousee", "Cletressecurisee");
	vig.crypter(cle);
	vig.decrypter(cle);
	cin >> i;
	return 0;
}