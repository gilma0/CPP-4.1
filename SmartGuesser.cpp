#include "SmartGuesser.hpp"
namespace bullpgia{
	uint length;
	int bull;
	int pgia;
	SmartGuesser::SmartGuesser(){

	}
	string guess(){
		return "";
	}
	void learn(string a){
		bull = a.at(0);
		pgia = a.at(2);
	}
	void startNewGame(uint alength){
		alength = alength;
	}
}
