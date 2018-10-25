#include "Counter.h"



Counter::Counter()
{
	decoupageBlocs = new string[20];
	cleChiffrees = new string[20];
	texteChiffre = new string[20];
	texteDechiffre = new string[20];
}


Counter::~Counter()
{
}

// Découpe le message en blocs de même taille
// Les blocs ont une taille de 8 caractères ascii
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

	// Réparti le message dans les blocs
	for (j = 0, k = 0;j < (int)message.length() / 8;j++, k += 8)
	{
		for (i = 0;i < 8;i++)
		{
			decoupageBlocs[j].push_back(message[i + k]);
		}
	}
	nombreBlocs = j;
}

// On crée des blocs contenant les clés qui serviront à chiffrer le message clair
// Chaque bloc est crée à partir de la clé de base et d'un compteur 
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

		total = total % (99999999 - 10000000) + 10000000; // On fait en sorte que le bloc ait une taille de 8 caractères

		cleChiffrees[i].append(to_string(total));

	}
}

// Sépare le message en blocs de même taille chiffrés et tous différents
void Counter::counterMode(string message, string cle)
{
	int i, j;

	cout << "Operation de Chiffrement: Counter Mode" << endl;
	cout << "Message de base: " << message << endl;
	decouperBlocs(message);
	chiffrementCle(cle);

	cout << "Message decoupe en blocs chiffres: ";

	// Chiffre les blocs avec un ou exclusif entre le bloc de message et le bloc de la clé chiffrée
	for (j = 0;j < nombreBlocs;j++)
	{
		for (i = 0; i < 8; i++)
		{
			char temp = decoupageBlocs[j][i] ^ cleChiffrees[j][i];
			texteChiffre[j].push_back(temp);
		}
		cout << texteChiffre[j] << " ";
	}
	cout << endl;
}

void Counter::dechiffrerBlocs()
{
	int i, j;

	cout << "Blocs dechiffres: ";

	// Déchiffre les blocs avec un ou exclusif entre le bloc de message chiffré et le bloc de la clé chiffrée
	for (j = 0;j < nombreBlocs;j++)
	{
		for (i = 0; i < 8; i++)
		{
			char temp = texteChiffre[j][i] ^ cleChiffrees[j][i];

			// On supprime les '#' qui ont été ajouté lors de la création des blocs
			if(temp != '#')
				texteDechiffre[j].push_back(temp);
		}
		cout << texteDechiffre[j] << " ";
	}
	cout << endl;
}

