#ifndef MAC_H
#define MAC_H

#include "Hash.h"
#include <string>

using namespace std;

class MAC
{
public:
	MAC();
	~MAC();

	string hmac(string cle,string message);
	bool verifierIntegrite(string message, string cle);
	string supprimerMac(string message);
};

#endif
