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
		set_slot(x,y, actual_player);
		this.activeplayer = !this.activeplayer
	}

}




tateti_struct::get_player1(){
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0,1);
	return distribution(generator);
}

tateti_struct::actual_player(){}//TODO

tateti_struct::set_slot(){} //TODO

tateti_struct::game_over()
{
	return no_valid_moves(0,0) || someone_won();
}//TODO


tateti_struct::someone_won();
{
	
}
