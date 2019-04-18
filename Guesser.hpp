#include <iostream>
#include <string>
#pragma once

using namespace std;

namespace bullpgia{
	class Guesser{
	public:
		int length;
		string learn(string a);
		virtual string guess();
		void startNewGame(int length);
	};
}
