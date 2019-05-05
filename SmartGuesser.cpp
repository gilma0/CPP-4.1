#include "SmartGuesser.hpp"
#include <string>
using namespace std;
namespace bullpgia{
	uint length;
	int bullA[4];
	int nowBull;
	int now;
	string Guess;
	int bull;
	SmartGuesser::SmartGuesser(){
		bull = 0;
		now = 0;
		Guess = "";
	}
	string SmartGuesser::guess(){
		cout<<"guess: "<<Guess<<endl;
		return Guess;
	}
	void SmartGuesser::learn(string a){
		cout<<"learn used"<<endl;
		nowBull = a.at(0)-48;
		if (nowBull > bull){
			cout<<"now bull: "<<nowBull<<endl;
			bullA[bull++] = now-1;
			now = 0;
			Guess = "";
			for (int i = 0; i<bull; i++){
				Guess += to_string(bullA[i]);
			}
			if(Guess.length() < length){
				Guess += to_string(now++);
			}
			while (Guess.length() < length){
				Guess += 'd';
			}
		}else{
			Guess = "";
			for (int i = 0; i<bull; i++){
				Guess += to_string(bullA[i]);
			}
			if(Guess.length() < length){
				Guess += to_string(now++);
			}
			while (Guess.length() < length){
				Guess += string(1,'d');
			}
		}
	}
	void SmartGuesser::startNewGame(int alength){
		length = alength;
		bull = 0;
		now = 0;
		Guess = "";
		int h = 0;
		while (h<length){
			Guess += string(1,'d');
			h++;
		}
	}
}

