#include <iostream>
#include <string>
#include "calculate.hpp"
#pragma once

using namespace std;

namespace bullpgia{
	class Guesser{
	public:
		int length;
		Guesser();
		Guesser(const string& constantString);
		string learn(string a);
		virtual string guess();
		void startNewGame(int length);
	};
}
