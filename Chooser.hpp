#include <iostream>
#include <string>
#pragma once

using namespace std;

namespace bullpgia{
	class Chooser{
	public:
		int length;
		virtual string choose(uint length);
	};
}
