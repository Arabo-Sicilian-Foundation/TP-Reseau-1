#ifndef MAC_H
#define MAC_H

#include <string>
#include <bitset>

class MAC
{
public:
	MAC();
	~MAC();

	std::string hmac(std::string k, std::string m);
};

#endif