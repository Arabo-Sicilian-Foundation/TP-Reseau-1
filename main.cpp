#include <stdio.h>
#include <string.h>
#include "Hash.h"

int main() {
	int i;
	string str = "AAAAA";
	string str2 = "eazaez";
	string output = "00000";
	string output2 = "00000";

	for (i = 0; i < str.size(); i++)
	{
		char temp = str[i] ^ str2[i];
		output[i] = temp;
	}
	for (i = 0; i < str.size(); i++)
	{
		char temp = output[i] ^ str2[i];
		output2[i] = temp;
	}
	cout << output << endl; 
	cout << output2;
	cin >> i;
	return 0;
}