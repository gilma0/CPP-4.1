#include <iostream>
#include <string>
#pragma once

using namespace std;

namespace bullpgia{
	class Chooser{
	public:
		int length;
		Chooser();
		Chooser(const string& constantString);
		virtual string choose(uint length);
	};
}
