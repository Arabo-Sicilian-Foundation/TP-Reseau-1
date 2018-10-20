#include "Counter.h"



Counter::Counter()
{
	decoupageBlocs = new string[20];
	cleChiffrees = new string[20];
	texteChiffre = new string[20];
}


Counter::~Counter()
{
}

void Counter::decouperBlocs(string message)
{
	int i, j, k;
	int combler = message.length() % 8;

	if (combler != 0)
	{
		for (i = 8;i > combler;i--)
			message.push_back('0');
	}

	for (j = 0, k = 0;j < (int)message.length() / 8;j++, k += 8)
	{
		for (i = 0;i < 8;i++)
		{
			decoupageBlocs[j].push_back(message[i + k]);
		}
	}
	nombreBlocs = j;
}

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
		total = total % (99999999 - 10000000) + 10000000;
		cleChiffrees[i].append(to_string(total));
	}
}

void Counter::counterMode(string message, string cle)
{
	int i, j;

	cout << "Operation de Chiffrement: Counter Mode" << endl;
	cout << "Message de base: " << message << endl;
	decouperBlocs(message);
	chiffrementCle(cle);

	cout << "Message decoupe en blocs chiffres: ";
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

