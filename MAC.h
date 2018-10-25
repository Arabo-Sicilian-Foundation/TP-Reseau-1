#ifndef MAC_H
#define MAC_H

#include <string>

using namespace std;

class MAC
{
public:
	MAC();
	~MAC();

	string hmac(string k,string m);
};

#endif
