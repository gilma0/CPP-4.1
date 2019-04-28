#include <iostream>
#include <string>
#include "calculate.hpp"
#pragma once

using namespace std;

namespace bullpgia{
	class Chooser{
	public:
		virtual string choose(uint length) = 0;
	};
}
