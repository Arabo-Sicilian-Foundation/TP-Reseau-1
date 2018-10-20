#include "Hash.h"



Hash::Hash()
{
	// Initialisation du hash
	// Taille fixe de 16 caractères
	messageHacher = "0000000000000000";
}


Hash::~Hash()
{
}

void Hash::fonctionHachage(string messageClair)
{
	int i;
	int tailleMessage = messageClair.size();

	string messageACode = messageClair;

	if (tailleMessage < 16)
	{
		// Si le message est plus petit que 16 caractères, on le répète
		while (tailleMessage < 16)
		{
			messageACode = messageACode + messageClair;
			tailleMessage += messageClair.size();
		}
	}

	for (i = 0;i < tailleMessage;i++)
	{
		// Modifie le caractère à la position i modulo 16 du message hacher
		// "%(122-97) + 97" permet d'obtenir des caractères entre 'a' (code ascii 97) et 'z' (code ascii 122)
		messageHacher[i % 16] = ((messageHacher[i % 16] + messageACode[i]) + i)%(122-97) + 97;
	}

}