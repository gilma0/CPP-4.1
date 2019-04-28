#include <iostream>
#include <string>
#include "calculate.hpp"
#pragma once

using namespace std;

namespace bullpgia{
	class Guesser{
	public:
		uint length;
		virtual void learn(string a){}
		virtual string guess() = 0;
		virtual void startNewGame(int length){}
	};
}
