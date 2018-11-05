#include "Feistel.h"



Feistel::Feistel()
{
	tableauSousCle = new string[16];
}


Feistel::~Feistel()
{
}

string Feistel::chiffrement(string bloc, string cle)
{
	string l = bloc.substr(0,4);
	string r = bloc.substr(4,8);
	string rCrypte;
	string resultatXOR = "0000";

	for (int nbTours = 0; nbTours < 16; nbTours++)
	{
		// On coupe le bloc en 2
		l = bloc.substr(0, 4);
		r = bloc.substr(4, 8);

		// On genère la sous clé
		cle = genSousCle(cle, nbTours);

		// On crypte le sous bloc droit
		Vigenere* f = new Vigenere(r);
		f->crypter(cle);
		rCrypte = f->getMessageCode();
		// On fait un XOR entre la partie droite et le resultat
		for (int i = 0; i < (int)l.length(); i++)
		{
			char tmp = l[i] ^ rCrypte[i];
			resultatXOR[i] = tmp;

		}
		bloc = r + resultatXOR;


		tableauSousCle[nbTours].append(cle);
	}
	bloc = resultatXOR + r;
	return bloc;
}

string Feistel::dechiffrement(string bloc, string cle)
{
	string l = bloc.substr(0, 4);
	string r = bloc.substr(4, 8);
	string rDecrypte;
	string resultatXOR = "0000";
	int nbTours;
	for (nbTours = 0; nbTours < 16; nbTours++)
	{

		cle = genSousCle(cle, nbTours);
		tableauSousCle[nbTours] = cle;
	}
	for (nbTours = 0; nbTours < 16; nbTours++)
	{
		cle = tableauSousCle[15 - nbTours];
		// On coupe le bloc en 2
		l = bloc.substr(0, 4);
		r = bloc.substr(4, 8);

		// On crypte le sous bloc droit
		Vigenere* f = new Vigenere(r);
		f->crypter(cle);
		rDecrypte = f->getMessageCode();

		// On fait un XOR entre la partie droite et le resultat
		for (int i = 0; i < (int)l.length(); i++)
		{
			char tmp = l[i] ^ rDecrypte[i];
			resultatXOR[i] = tmp;  

		}
		bloc = r + resultatXOR;
	}
	bloc = resultatXOR + r;
	return bloc;
}

string Feistel::genSousCle(string cle, int nbTours)
{
	// on traite chaque partie de la clé séparement
	string l = cle.substr(0, 4);
	string r = cle.substr(4, 7);
	if (nbTours % 2 == 0)
	{
		// Décalage de 1 bits vers la gauche
		char l0 = l[0];
		char r0 = r[0];

		for (int i = 0; i < (int)l.length() - 1; i++)
		{

			l[i] = l[i + 1];
			r[i] = r[i + 1];
		}

		l[l.length() - 1] = l0;
		r[r.length() - 1] = r0;
	}
	else
	{
		// Decalage de 2 bits vers la gauche
		char l0 = l[0];
		char l1 = l[1];
		char r0 = r[0];
		char r1 = r[1];

		for (int i = 0; i < (int)l.length() - 2; i++)
		{
			l[i] = l[i + 2];
			r[i] = r[i + 2];
		}
		l[l.length() - 2] = l0;
		l[l.length() - 1] = l1;
		r[r.length() - 2] = r0;
		r[r.length() - 1] = r1;
	}

	// on retourne la sous clé (en inversant les 2 sous blocs)
	return r + l;
}