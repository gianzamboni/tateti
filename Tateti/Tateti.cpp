#include "Tateti.h"
#include <iostream>
#include <random>
using namespace std;

Tateti::Tateti(){
	table = vector<vector<char> >(3, vector<char>(3));
	mode = PVC;
	actualPlayer = getPlayer1();
}

Tateti::Tateti(MODE m) {
	table = vector<vector<char> >(3, vector<char>(3,0));
	mode = m;
	actualPlayer = getPlayer1();
}

Tateti::~Tateti(){}

 void Tateti::initGame(){

 	int n = 0;
 	while(n!=6){
 		n++;
 		int x;
 		int y;

 		cout<< "gimme me ya move "<< getActualPlayer() << "!: ";
 		cin >> x >> y;
 		cout << endl;
 		while(notAValidMove(x,y)){
 			cout<<"stop being a cunt!:"<< endl;
 			cin >> x >> y;
 			cout << endl;
 		}

 		setSlot(x,y);
 		printGame();

 	}
}

bool Tateti::getPlayer1(){
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0,1);
	return (bool) distribution(generator);
}

bool Tateti::getActualPlayer(){
	return actualPlayer;
}

void Tateti::setSlot(int x, int y){
	table[x][y] = actualPlayer? 'X' : 'O';
	actualPlayer = !actualPlayer;	
}

char Tateti::getSlotValue(int x, int y){
	return table[x][y];
}

bool Tateti::gameOver(){
	return hayDiagonal() || hayColumna() || hayColumna();	
}

bool Tateti::hayDiagonal(){
	return ((table[0][0] != 0)&&(table[0][0] == table[1][1]) && (table[0][0] == table[2][2]));
}

bool Tateti::hayFila(){
	
	for(int i=0; i<3; i++){
		cout<< ((table[i][0] != 0)&&(table[i][0] == table[i][1]) && (table[i][0] == table[i][2])) << endl;
		if ((table[i][0] != 0)&&(table[i][0] == table[i][1]) && (table[i][0] == table[i][2])){
			return true;
		}
	}
	return false;
}

bool Tateti::hayColumna(){

	for(int i=0; i<3; i++){
		if ((table[0][i] != 0)&&(table[0][i] == table[1][i]) && (table[0][i] == table[2][i])){
			return true;
		}
	}
	return false;
}

void Tateti::printGame(){
 	for(int y=0; y<3; y++){
 		for(int x=0; x<3; x++){
 			cout << (!notAValidMove(x,y)? '-': table[x][y]) << "\t";
 		}	
 		cout << endl;
 	}
}

bool Tateti::notAValidMove(int x,int y){
	return x>2 || y>2 || x<0 || y<0 || table[x][y] != 0;
}
