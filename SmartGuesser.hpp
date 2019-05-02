#include <iostream>
#include <string>
#include "Guesser.hpp"
#pragma once

using namespace std;

namespace bullpgia{
	class SmartGuesser: public bullpgia::Guesser{
	public:
		SmartGuesser();
		uint length;
		void learn(string a) override{}
		string guess() override{return "";}
		void startNewGame(uint length){}
	};
}
