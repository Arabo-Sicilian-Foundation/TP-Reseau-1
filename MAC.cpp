#include "MAC.h"
#include "Hash.h"

MAC::MAC()
{
}


MAC::~MAC()
{
}

std::string MAC::hmac(string k, string m)
{
	string zeros;
	string s_0;
	string s_i = "00000000";
	Hash* hache = new Hash();

	// s_i = xor(kplus,00110110); 
	for (int i = 0; i < (int)k.size(); i++)
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
	for (int i = 0; i < (int)k.size(); i++)
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
