#include "MAC.h"
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
	std::string s_i;
	std::string s_0;

	// c'est surement inutile et doit y avoir plus simple
	std::bitset<BBITS * 8> kplus;
	std::bitset<BBITS * 8> kBin;
	std::bitset<8> ipad = std::bitset<8>(00110110);
	std::bitset<8> opad = std::bitset<8>(01011100);

	while (k.length() <  BBITS /* 64 bits */)
	{
		// on rajoute des 0 a gauche de k pour obtenir k+
		k.insert(0, 'NUL');
	}

	// s_i = xor(kplus,00110110); 
	//ca marche pas du coup la
	kBin = std::bitset<BBITS * 8>(k);
	kplus = kBin ^ ipad;

	// s_i = concat(s_i,m);

	// s_i = hachage(s_i);

	// s_0 = xor(kplus,01011100);

	//s_0 = concat(s_0, s_i);

	// s_0 = hachage(s_0);

	return s_0;
}
