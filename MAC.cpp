#include "MAC.h"

MAC::MAC()
{
}


MAC::~MAC()
{
}

std::string MAC::hmac(string cle, string message)
{
	string zeros;
	string s_0;
	string s_i;
	Hash* hache = new Hash();

	cout << "-- MAC --" << endl;
	// s_i = xor(kplus,00110110); 
	for (int i = 0; i < (int)cle.size(); i++)
	{
		char tmp = cle[i] ^ '6';
		s_i.push_back(tmp);
	}

	// s_i = concat(s_i,m);
	s_i += message;

	// s_i = hachage(s_i);
	hache->fonctionHachage(s_i);
	s_i = hache->getMessageHacher();

	// s_0 = xor(kplus,01011100);
	for (int i = 0; i < (int)cle.size(); i++)
	{


		char tmp = cle[i] ^ '6';
		s_0.push_back(tmp);

	}

	//s_0 = concat(s_0, s_i);
	s_0 += s_i;

	// s_0 = hachage(s_0);
	hache->fonctionHachage(s_0);
	s_0 = hache->getMessageHacher();

	cout << "MAC : " << s_0 << endl;
	return s_0;
}

// Vérfie l'intégrité du message
bool MAC::verifierIntegrite(string messageMac, string cle)
{
	string mac;
	string message;
	MAC m;

	int i;

	// On récupère la partie MAC du message
	for (i = 0;i < 16;i++)
		mac.push_back(messageMac[i]);
	
	// On récupère le message
	for (i = 16;i < (int)messageMac.length();i++)
		message.push_back(messageMac[i]);

	// On compare les deux MAC
	if (mac == m.hmac(cle, message))
	{
		cout << "Le message est integre ! " << endl;
		return true;
	}
	else
	{
		cout << "Le message n'est pas integre ! " << endl;
		return false;
	}
}

// Renvoie le message sans le MAC
string MAC::supprimerMac(string message)
{
	int i;
	string messageSansMac;

	for (i = 16;i < (int)message.length();i++)
		messageSansMac.push_back(message[i]);

	return messageSansMac;
}