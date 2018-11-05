
#include <thread>
#include <iostream>

#include "Util.h"

#define DEFAULT_BUFLEN 1024

#define BERNARD_PORT "27015"
#define BERNARD_ADRESS "127.0.0.1"

#define CLEMENT_PORT "27016"
#define CLEMENT_ADRESS "127.0.0.1"

#define AGNES_PORT "27017"
#define AGNES_ADRESS "127.0.0.1"

string clePriveeBernard;
string clePriveeAgnes;

int Agnes()
{
	SOCKET bernardSocket = INVALID_SOCKET;
	SOCKET clementSocket = INVALID_SOCKET;
	SOCKET listenSocket = INVALID_SOCKET;
	string action;
	string cleBernard;
	string mac;
	string messageDecrypt;
	MAC m;

	if (connectTo(clementSocket, CLEMENT_ADRESS, CLEMENT_PORT))
	{
		cout << "Agnes envoie un message a Clement pour entrer en contact avec Bernard " << endl;
		string message = Encrypt("Salut, il me faut la cle de Bernard!", clePriveeAgnes);
		mac = m.hmac(clePriveeAgnes, message);
		message = mac + message;
		sendTo(clementSocket, message);
	}

	if (ListenTo(listenSocket, AGNES_PORT))
	{
		string message;
		receiveFrom(listenSocket, message);
		cout << "Agnes recoit le message crypte: " << message << endl;
		m.verifierIntegrite(message, clePriveeAgnes);
		message = m.supprimerMac(message);
		cleBernard = Decrypt(message, clePriveeAgnes);
		cout << "Agnes decrypte le message: " << cleBernard << endl;

		if (connectTo(bernardSocket, BERNARD_ADRESS, BERNARD_PORT))
		{
			message.clear();
			mac.clear();
			cout << "Agnes envoi un message a Bernard" << endl;
			message = Encrypt("Salut Bernard, c'est Agnes", cleBernard);
			mac = m.hmac(cleBernard, message);
			message = mac + message;
			sendTo(bernardSocket, message);
		}
		closeSocket(listenSocket);

	}
	if (ListenTo(listenSocket, AGNES_PORT))
	{
		string message;
		receiveFrom(listenSocket, message);
		cout << "Agnes recoit le message crypte: " << message << endl;
		m.verifierIntegrite(message, cleBernard);
		message = m.supprimerMac(message);
		messageDecrypt = Decrypt(message, cleBernard);
		cout << "Agnes decrypte le message: " << messageDecrypt << endl;

		closeSocket(listenSocket);

	}

	return 0;
}

int Bernard()
{
	string message;
	string messageDecrypte;
	string mac;
	MAC m;

	SOCKET listenSocket = INVALID_SOCKET;
	SOCKET agnesSocket = INVALID_SOCKET;

	if (ListenTo(listenSocket, BERNARD_PORT))
	{
		receiveFrom(listenSocket, message);
		cout << "Bernard recoit le message crypte: " << message << endl;
		m.verifierIntegrite(message, clePriveeBernard);
		message = m.supprimerMac(message);
		messageDecrypte = Decrypt(message, clePriveeBernard);
		cout << "Bernard decrypte le message: " << messageDecrypte << endl;

		if (connectTo(agnesSocket, AGNES_ADRESS, AGNES_PORT))
		{
			message.clear();
			mac.clear();
			cout << "Bernard envoi un message a Agnes" << endl;
			message = Encrypt("Salut Agnes, c'est Bernard", clePriveeBernard);
			mac = m.hmac(clePriveeBernard, message);
			message = mac + message;
			sendTo(agnesSocket, message);
		}

		closeSocket(listenSocket);
	}

	return 0;
}

int Clement(const int nbConnection)
{
	string message;
	string cle;
	string messageDecrypte;
	string mac;
	MAC m;

	SOCKET listenSocket = INVALID_SOCKET;
	SOCKET agnesSocket = INVALID_SOCKET;
	SOCKET bernardSocket = INVALID_SOCKET;


	for (int connectNbr = 0; connectNbr  < nbConnection; connectNbr++)
	{

		if (ListenTo(listenSocket, CLEMENT_PORT))
		{
			receiveFrom(listenSocket, message);
			cout << "Clement recoit le message crypte: " << message << endl;
			m.verifierIntegrite(message, clePriveeAgnes);
			message = m.supprimerMac(message);
			messageDecrypte = Decrypt(message, clePriveeAgnes);
			cout << "Clement decrypte le message avec la cle d'Agnes: " << messageDecrypte << endl;

			if (connectTo(agnesSocket, AGNES_ADRESS, AGNES_PORT))
			{
				message.clear();
				cout << "Clement envoi la cle privee de Bernard a Agnes" << endl;
				message = Encrypt(clePriveeBernard, clePriveeAgnes);
				mac = m.hmac(clePriveeAgnes, message);
				message = mac + message;
				sendTo(agnesSocket, message);
			}

			closeSocket(listenSocket);
		}
	}
	return 0;
}

int main(int argc, char **argv)
{

	if (!InitialiseWinsock())
	{
		return 1;
	}

	if (argc == 1)	// using thread
	{

		cout << "!! les cles doivent faire 8 caracteres ou plus !!" << endl;
		do
		{
			cout << "Entrez la cle privee partage par Clement et Bernard: " << endl;
			cin >> clePriveeBernard;
		} while (clePriveeBernard.length() < 8);
		do
		{
			cout << "Entrez la cle privee partage par Clement et Agnes: " << endl;
			cin >> clePriveeAgnes;
		} while (clePriveeAgnes.length() < 8);

		std::thread thClement(Clement, 2);
		std::thread thBernard(Bernard);
		// sleep to make sure Clement and bernard are started before Agnes
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		std::thread thAgnes(Agnes);
		thAgnes.join();
		thClement.join();
		thBernard.join();

	}
	else if (argc == 2) //using three process
	{
		if (strcmp(argv[1], "-a") == 0)
		{
			Agnes();
		}
		else if (strcmp(argv[1], "-b") == 0)
		{
			Bernard();
		}
		else if (strcmp(argv[1], "-c") == 0)
		{
			Clement(2);
		}
		else
		{
			printf("Invalid argument: %s\n", argv[1]);
			return 1;
		}
	}
	else
	{
		printf("Too many arguments\n");
		return 1;
	}

	CleanupWinsock();

	system("pause");
	return 0;
}