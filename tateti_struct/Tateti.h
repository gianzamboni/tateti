#ifndef _TATETI_H_
#define _TATETI_H_

#include <vector>
using namespace std;

enum MODE { PVP, PVC };

class Tateti {

public:
		//Constructors
		Tateti();
		Tateti(MODE m);
		~Tateti();

		//Methods
		bool actual_player();
		bool game_over();
		bool not_a_valid_move(int x, int y);

		void init_game();
		void print_game();
		void set_slot(int x, int y, bool activePlayer);


	private: 
		vector<vector<char> > table;
		bool activePlayer;
		MODE mode;

		bool get_player1();

};
#endif
