#include "MAC.h"
#include "Hash.h"

#define BBITS 8


MAC::MAC()
{
}


MAC::~MAC()
{
}

std::string MAC::hmac(std::string k, std::string m)
{
	std::string zeros;
	std::string s_0;
	std::string s_i = "00000000";
	Hash* hache = new Hash();

	// s_i = xor(kplus,00110110); 
	for (int i = 0; i < k.size(); i++)
	{
		char tmp = k[i] ^ '6';
		s_i[i] = tmp;
	}

	// s_i = concat(s_i,m);
	s_i += m;

	// s_i = hachage(s_i);
	hache->fonctionHachage(s_i);
	s_i = hache->getMessageHacher();

	// s_0 = xor(kplus,01011100);
	for (int i = 0; i < k.size(); i++)
	{
		char tmp = k[i] ^ '6';
		s_0[i] = tmp;
	}

	//s_0 = concat(s_0, s_i);
	s_0 += s_i;

	// s_0 = hachage(s_0);
	hache->fonctionHachage(s_0);
	s_0 = hache->getMessageHacher();

	return s_0;
}
