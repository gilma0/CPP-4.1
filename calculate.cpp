#include <iostream>
#include "calculate.hpp"
using namespace std;

namespace bullpgia{
	string calculateBullAndPgia(string choose, string guess){
		int cSize = choose.length();
		int gSize = guess.length();
		int a = 0;
		int b = 0;
		int bull = 0;
		int pgia = 0;
		while (a < cSize){
			char now = choose.at(a);
			b = 0;
			while (b < gSize){
				if (guess.at(b) == now){
					if (a == b){
						bull++;
						choose[a]='a';
						guess[b]='b';
					}
				}
				b++;
			}
			a++;
		}
		a= 0;
		b = 0;
		while (a < cSize){
			char now = choose.at(a);
			b = 0;
			while (b < gSize){
				if (guess.at(b) == now){
					pgia++;
					choose[a]='a';
					guess[b]='b';
				}
				b++;
			}
			a++;
		}

		string answer = to_string(bull)+","+to_string(pgia);
		return answer;
	}
}
