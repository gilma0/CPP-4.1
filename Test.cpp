/**
 * A demo program for bull-pgia.
 * 
 * @author Erel Segal-Halevi
 * @since  2019-04
 */


#include <iostream>
using namespace std;

#include "play.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {

		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{"1234"}, c12345{"12345"}, c9999{"9999"};
		ConstantGuesser g1234{"1234"}, g12345{"12345"}, g9999{"9999"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("1234","1234"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1234","4321"), "0,4")      // 0 bull, 4 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
		.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		;

		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100)<=100, true);  // smarty should always win in at most 100 turns!
		}
		/////////////////////////////////////////////////OUR_TEST////////////////////////////////////////////////////////////////////////////////////////
	ConstantChooser c4567{"4567"}, c25478{"25478"}, c3321{"3321"}, c234787{"234787"}, c5555{"5555"}, c2345{"2345"}, c23456{"23456"},
                                c2234{"2234"}, c0246{"0246"}, c1357{"1357"}, c24680{"24680"}, c2332{"2332"}, c11111{"11111"}, c13578{"13578"},
                                c02468{"02468"}, c12346{"12346"}, c123123{"123123"}, c012345{"012345"}, c0{"0"}, c12{"12"}, c123{"123"} , c5432{"5432"}, c543210{"543210"}, c321{"321"}
				, c21{"21"}, c31{"31"}, c41{"41"}, c51{"51"};


	ConstantGuesser g4567{"4567"}, g25478{"25478"}, g3321{"3321"}, g5555{"5555"}, g2345{"2345"}, g1111{"1111"}, g23456{"23456"},
                                g2234{"2234"}, g02468{"02468"}, g1357{"1357"}, g2468{"2468"}, g2332{"2332"}, g11111{"11111"}, g13578{"13578"},
                                g024680{"024680"}, g123456{"123456"}, g1231231{"1231231"}, g0123456{"0123456"}, g234787{"234787"},
                                g0{"0"}, g123{"123"},g00{"00"},g22345{"22345"} , g543210{"012345"},  g12{"12"}  , g5432{"5432"}, g012345{"543210"}, g21{"21"}, g321{"321"},
				g31{"31"}, g41{"41"}, g51{"51"};

		testcase.setname("Calculate bull and pgia")
		.CHECK_OUTPUT(calculateBullAndPgia("4567","4589"), "2,0")      // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3321","3321"), "4,0")      // 4 bull, 0 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("9087","7809"), "0,4")      // 0 bull, 4 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1235","1235"), "4,0")      // 4 bull, 0 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("1212","1213"), "3,0")      // 3 bull, 0 pgia
	 	.CHECK_OUTPUT(calculateBullAndPgia("123","123"), "3,0")        // 3 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("230199","230111"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("9900","9900"), "3,0")      // 4 bull, 0 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("999","111"), "0,0")      // 3 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("678","179"), "0,0")        // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("555555","111111"), "6,0")   // 6 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3456","1789"), "0,0")      // 0 bull, 0 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("2468","2569"), "1,2")      // 0 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1635","1653"), "2,2")      // 2 bull, 2 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("2345","2345"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2345","2354"), "2,2")      // 2 bull, 2 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("0123","3210"), "0,4")      // 0 bull, 4 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1115","5111"), "2,2")      // 2 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2225","5222"), "2,2")      // 2 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3334","4333"), "2,2")      // 2 bull, 2 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("4562","1563"), "2,0")      // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1342","1234"), "1,3")      // 1 bull, 3 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2808","3808"), "3,1")      // 3 bull, 1 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3456","1789"), "0,0")      // 0 bull, 0 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("2469","2468"), "3,0")      // 3 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2459","2468"), "2,0")      // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1667","1653"), "2,0")      // 2 bull, 0 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("1645","1614"), "2,2")      // 2 bull, 2 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("5555","5545"), "3,0")      // 3 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2545","5254"), "0,4")      // 0 bull, 4 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("0101","0010"), "1,2")      // 1 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1789","1789"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("0101","0110"), "2,2")      // 2 bull, 2 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("1536","1563"), "2,2")      // 2 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3456","1789"), "0,0")      // 0 bull, 0 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("3469","2468"), "2,0")      // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("6776","7667"), "0,4")      // 0 bull, 4 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("9999","9990"), "3,0")      // 3 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1233","1232"), "3,0")      // 3 bull, 0 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("12345","12345"), "5,0")      // 5 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("12122","12111"), "3,0")      // 3 bull, 0 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("34567","34576"), "3,2")      // 3 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("34569","96543"), "1,4")      // 1 bull, 4 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("2468","2648"), "2,2")      // 2 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("6565","5656"), "0,4")      // 0 bull, 4 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("4884","4884"), "4,0")      // 4 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2389","9382"), "2,2")      // 2 bull, 2 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("0987","7890"), "0,4")      // 0 bull, 4 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("9867","9876"), "2,2")      // 2 bull, 2 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("4569","4563"), "2,0")      // 2 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3345","2234"), "0,0")      // 0 bull, 0 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("2445","2444"), "3,0")      // 3 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1656","1645"), "2,0")      // 2 bull, 0 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("1365","1563"), "2,2")      // 2 bull, 2 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("2222","2221"), "3,0")      // 3 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2698","8692"), "1,3")      // 1 bull, 3 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("3456","3965"), "1,2")      // 1 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("1775","1775"), "4,0")      // 4 bull, 0 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("1757","5717"), "2,2")      // 2 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("0099","1122"), "0,0")      // 0 bull, 0 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("0023","0045"), "3,0")      // 3 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("0023","0026"), "3,0")      // 3 bull, 0 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("1","1"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("2","2"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("3","3"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("4","4"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("4","4"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("5","5"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("6","6"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("7","7"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("8","8"), "1,0")      // 1 bull, 0 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("13","31"), "0,2")      // 0 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("6799","9976"), "0,4")      // 0 bull, 4 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("09","01"), "1,0")      // 1 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("66","66"), "2,0")      // 2 bull, 0 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("0389","0398"), "2,2")      // 2 bull, 2 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("012","012"), "3,0")      // 3 bull, 0 pgia
                .CHECK_OUTPUT(calculateBullAndPgia("345","121"), "0,0")      // 0 bull, 0 pgia
		.CHECK_OUTPUT(calculateBullAndPgia("0","1"), "0,0")      // 0 bull, 0 pgia
		;

		testcase.setname("Play with dummy choosers and guessers")
		.CHECK_EQUAL(play(c4567, g4567, 4, 100), 1)      // guesser wins in one turn.
                .CHECK_EQUAL(play(c25478, g25478, 5, 100), 1)      // guesser wins in one turn.
                .CHECK_EQUAL(play(c2345, g2345, 4, 30), 1)      // guesser wins in one turn.
                .CHECK_EQUAL(play(c234787, g234787, 6, 100), 1)      // guesser wins in one turn.
                .CHECK_EQUAL(play(c2234, g2234, 4, 100), 1)      // guesser wins in one turn.
                .CHECK_EQUAL(play(c23456, g23456, 5, 100), 1)      // guesser wins in one turn.
                .CHECK_EQUAL(play(c1357, g1357, 4, 30), 1)      // guesser wins in one turn.
                .CHECK_EQUAL(play(c11111, g11111, 5, 100), 1)      // guesser wins in one turn.
                .CHECK_EQUAL(play(c12, g12, 2, 100), 1)      // guesser wins in one turn.
                .CHECK_EQUAL(play(c0, g0, 1, 100), 1)      // guesser wins in one turn.
                .CHECK_EQUAL(play(c123, g123, 3, 30), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c5432, g5432, 3, 30), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c321, g321, 3, 30), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c21, g21, 3, 30), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c31, g31, 3, 30), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c41, g41, 3, 30), 1)      // guesser wins in one turn.
		.CHECK_EQUAL(play(c51, g51, 3, 30), 1)      // guesser wins in one turn.


		.CHECK_EQUAL(play(c4567, g25478, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c5555, g234787, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c1357, g13578, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c0246, g02468, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
                .CHECK_EQUAL(play(c02468, g024680, 5, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12346, g123456, 5, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c123123, g1231231, 6, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c012345, g0123456, 6, 100), 101)   // guesser loses technically by making an illegal guess (too long).
                .CHECK_EQUAL(play(c123, g1234, 3, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c0, g00, 1, 100), 101)   // guesser loses technically by making an illegal guess (too long).
		.CHECK_EQUAL(play(c12, g123, 2, 100), 101)   // guesser loses technically by making an illegal guess (too long).

		.CHECK_EQUAL(play(c25478, g3321, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c234787, g4567, 4, 100), 0)  // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c12346, g2234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c234787, g5555, 4, 50), 0)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c13578, g1357, 4, 50), 0)     // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c11111, g1111, 4, 100), 0)  // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c24680, g2468, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
                .CHECK_EQUAL(play(c123123, g22345, 5, 100), 0)  // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c012345, g22345, 5, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
                .CHECK_EQUAL(play(c12, g0, 1, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
                .CHECK_EQUAL(play(c123, g12, 2, 100), 0)  // chooser loses technically by choosing an illegal number (too long).
		.CHECK_EQUAL(play(c0, g123, 3, 100), 0)     // chooser loses technically by choosing an illegal number (too long).

		.CHECK_EQUAL(play(c2345, g2345, 4, 30), 31)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c5555, g5555, 4, 60), 61)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c2332, g2332, 4, 60), 61)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c1357, g1357, 4, 30), 31)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c11111, g11111, 4, 70), 71)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c4567, g3321, 4, 90), 91)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c3321, g4567, 4, 50), 51)    // guesser loses by running out of turns
                .CHECK_EQUAL(play(c0, g0, 1, 50), 51)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c12, g12, 2, 90), 91)    // guesser loses by running out of turns
		.CHECK_EQUAL(play(c123, g123, 3, 70), 71)    // guesser loses by running out of turns
		;

		testcase.setname("Play with smart guesser");
		RandomChooser R2;//randy2
		SmartGuesser S2;//smarty2
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(R2, S2, 4, 100)>100, false);  // smarty should always win in at most 10 turns!
		}

		RandomChooser R3;
		SmartGuesser S3;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(R3, S3, 5, 100)>100, true);
		}

		RandomChooser R4;
		SmartGuesser S4;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(R4, S4, 5, 100)>100, true);
		}

		RandomChooser R5;
		SmartGuesser S5;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(R5, S5, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}

		RandomChooser R6;
		SmartGuesser S6;
		for (uint i=0; i<100; ++i) {
			testcase.CHECK_EQUAL(play(R6, S6, 4, 100)<=100, true);  // smarty should always win in at most 10 turns!
		}

    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}

