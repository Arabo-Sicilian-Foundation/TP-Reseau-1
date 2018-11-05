#include "Counter.h"



Counter::Counter()
{
	decoupageBlocs = new string[20];
	cleChiffrees = new string[20];
	blocsChiffres = new string[20];
}


Counter::~Counter()
{
}

// D�coupe le message en blocs de m�me taille
// Les blocs ont une taille de 8 caract�res ascii
void Counter::decouperBlocs(string message)
{
	int i, j, k;
	int combler = message.length() % 8;

	// Si la taille du message n'est pas un multiple de 8, on rajoute des '#' au message
	if (combler != 0)
	{
		for (i = 8;i > combler;i--)
			message.push_back('#');
	}

	// R�parti le message dans les blocs
	for (j = 0, k = 0;j < (int)message.length() / 8;j++, k += 8)
	{
		for (i = 0;i < 8;i++)
		{
			decoupageBlocs[j].push_back(message[i + k]);
		}
	}
	nombreBlocs = j;
}

// On cr�e des blocs contenant les cl�s qui serviront � chiffrer le message clair
// Chaque bloc est cr�e � partir de la cl� de base et d'un compteur 
void Counter::chiffrementCle(string cle)
{
	int compteur = 1;
	int i, j;
	int total;

	for (i = 0;i < nombreBlocs;i++,compteur++)
	{
		total = 0;
		for (j = 0; j < (int)cle.length();j++)
		{
			total += (int)cle[j] * compteur;
		}

		total = total % (99999999 - 10000000) + 10000000; // On fait en sorte que le bloc ait une taille de 8 caract�res

		cleChiffrees[i].append(to_string(total));

	}
}

// S�pare le message en blocs de m�me taille chiffr�s et tous diff�rents
void Counter::counterMode(string message, string cle)
{
	int i, j;

	decouperBlocs(message);
	chiffrementCle(cle);

	cout << "-- Counter Mode --" << endl;
	cout << "Blocs chiffres : " << endl;
	// Chiffre les blocs avec un ou exclusif entre le bloc de message et le bloc de la cl� chiffr�e
	for (j = 0;j < nombreBlocs;j++)
	{
		for (i = 0; i < 8; i++)
		{
			char temp = decoupageBlocs[j][i] ^ cleChiffrees[j][i];
			blocsChiffres[j].push_back(temp);
		}
		cout << blocsChiffres[j] << " ";
	}

	cout << endl;
}

void Counter::dechiffrerBlocs(string messageChiffre[20], string cle)
{
	int i, j;


	// On r�cup�re les cl�s chiffr�es
	chiffrementCle(cle);

	cout << "-- Counter Mode --" << endl;

	// D�chiffre les blocs avec un ou exclusif entre le bloc de message chiffr� et le bloc de la cl� chiffr�e
	for (j = 0;j < nombreBlocs;j++)
	{
		for (i = 0; i < 8; i++)
		{
			char temp = messageChiffre[j][i] ^ cleChiffrees[j][i];

			// On ajoute le caract�re au texte d�chiffr�
			// Si le caract�re est '#', on ne le garde pas 
			if(temp != '#')
				texteDechiffre.push_back(temp);
		}
	}
	cout << "Blocs dechiffres: " << texteDechiffre << endl;
}

