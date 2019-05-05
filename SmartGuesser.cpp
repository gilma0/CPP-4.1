#include "SmartGuesser.hpp"
using namespace std;
namespace bullpgia{
	uint length;
	//int pgiaA[4];
	char bullA[999];
	int nowBull;
	//int nowPgia;
	int now;
	string Guess;
	int bull;
	//int pgia;
	SmartGuesser::SmartGuesser(){
		for (int i = 0; i<999; i++){
			//pgiaA[i] = -1;
			bullA[i] = 'd';
		}
		//pgia = 0;
		bull = 0;
		now = 0;
		Guess = "";
	}
	string SmartGuesser::guess(){
		cout<<"guess: "<<Guess<<endl;
		return Guess;
	}
	void SmartGuesser::learn(string a){
		nowBull = a.at(0);
		//nowPgia = a.at(2);
		if (now <= 9){
			if (nowBull > bull){
				bullA[bull] = (now+48);
				bull++;
				cout<<"this is changed char "<< (char)bullA[nowBull]<<endl;
				cout<<"this is now "<<now<<endl;
			}
			now++;
			return;
		}
		now = 0;
		int h = 0;
		Guess = "";
		while (h<length){
			Guess += to_string(bullA[h++]);
		}
		Guess += to_string(now++);
/*		//nowPgia = a.at(2);
		if (now <= 9){
			if (nowBull > bull){
				bullA[nowBull++] = now;
				bull++;
			}
			if (nowPgia > pgia){
				pgiaA[nowPgia++] = now;
				pgia++;
			}
			now++;
			return;
		}
		if
		Guess += to_string(bullA[0]);
		if (nowBull > bull){
			bullA[nowBull-1] = now;
			now = 0;
			bull++;
		}
		int h = 0;
		Guess = "";
		while (h<length){
			Guess += to_string(bullA[h++]);
		}
		Guess += to_string(now++);*/
	}
	void SmartGuesser::startNewGame(int alength){
		length = alength;
		for (int i = 0; i<length; i++){
			//pgiaA[i] = -1;
			bullA[i] = 'd';
		}
		//pgia = 0;
		bull = 0;
		now = 0;
		Guess = "";
		int h = 0;
		while (h<length){
			Guess += string(1, bullA[h++]);
		}
	}
}

