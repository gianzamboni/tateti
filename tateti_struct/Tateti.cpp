#include "Tateti.h"
#include <iostream>
#include <random>
using namespace std;

Tateti::Tateti(){
	table = vector<vector<char> >(3, vector<char>(0));
	mode = PVC;
	activePlayer = get_player1();
}

Tateti::Tateti(MODE m) {
	table = vector<vector<char> >(3, vector<char>(3,0));
	mode = m;
	activePlayer = get_player1();
}

Tateti::~Tateti(){}

void Tateti::init_game(){

	int n = 0;
	while(n!=6){
		n++;
		int x;
		int y;

		cout<< "gimme me ya move "<< actual_player() << "!: ";
		cin >> x >> y;
		cout << endl;
		while(not_a_valid_move(x,y)){
			cout<<"stop being a cunt!:"<< endl;
			cin >> x >> y;
			cout << endl;
		}

		set_slot(x,y, activePlayer);
		print_game();
		activePlayer = !activePlayer;

	}

}

bool Tateti::get_player1(){
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0,1);
	return (bool) distribution(generator);
}

bool Tateti::actual_player(){
	// TODO
	return true;
}

void Tateti::set_slot(int x, int y, bool actPlyr ){
	actPlyr?(table[x][y]='X'):(table[x][y]='O');
	//this.table[x][y] = (actPlyr? 'X' : 'O')	
}

bool Tateti::game_over(){
	//TODO
	//return no_valid_moves(0,0) || someone_won();
	return true;
}

void Tateti::print_game(){
	for(int col=0; col<3; col++){
		for(int row=0; row<3; row++){
			cout << (!not_a_valid_move(col,row)? '-': table[col][row]) << "\t";
		}
		cout << endl;
	}
}


bool Tateti::not_a_valid_move(int x,int y){
	return x>2 || y>2 || x<0 || y<0 || table[x][y] != 0;
}
