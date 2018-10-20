#include "Hash.h"

int main()
{
	string messageClair;
	Hash hash;

	cout << "Texte a hacher" << endl;
	cin >> messageClair;

	hash.fonctionHachage(messageClair);

	cout << hash.getMessageHacher();

	cin >> messageClair;

	return 0;

}