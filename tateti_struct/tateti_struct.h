#ifndef _TATETI_STRUCT_
#define _TATETI_STRUCT_

enum MODE { PVP, PVC };
class tateti_struct {

	tateti_struct();

	void move();

	private: 
		char** table;
		bool activeplayer;
		MODE mode;

		int get_player1();

};
#endif