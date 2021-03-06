#include <iostream>
#include <string>
#include "Guesser.hpp"
#pragma once

using namespace std;

namespace bullpgia{
	class SmartGuesser: public bullpgia::Guesser{
	public:
		SmartGuesser();
		int bull;
		int nowBull;
		int now;
		int bullA[4];
		string Guess;
		//int pgia;
		uint length;
		void learn(string a) override;
		string guess() override;
		void startNewGame(int length) override;
	};
}
