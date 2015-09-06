#include "tateti_struct.h"
#include <iostream>
using namespace std	;

tateti_struct::tateti_struct(MODE m) {
	this.table = new char[3][3]
	this.mode = m;
	this.activeplayer = get_player1();
}

tateti_struct::init_game(){
	while(!game_over())
	{
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
		set_slot(x,y, actual_player);
		print_ttt();
		this.activeplayer = !this.activeplayer;

	}

}




bool tateti_struct::get_player1(){
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0,1);
	return (bool)distribution(generator);
}

bool tateti_struct::actual_player(){}//TODO

void tateti_struct::set_slot(int x, int y, bool actPlyr )
{
	actPlyr?(this.table[x][y]='X'):(this.table[x][y]='O')
	//this.table[x][y] = (actPlyr? 'X' : 'O')	
}

bool tateti_struct::game_over()
{
	//return no_valid_moves(0,0) || someone_won();
}//TODO

void tateti_struct::print_ttt()
{
	for(i=0; i<3, i++)
	{
		for(j=0; j<3, j++)
		{
			cout << not_a_valid_move(i,j)?('-'):this.table[x][y] << "\t"
		}
		cout << endl;
	}
}


bool tateti_struct::not_a_valid_move(int x,int y);
{
	return this.table[x][y]!=NULL;
}
