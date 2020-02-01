#pragma once
#include <iostream>
#include "HilmysClass.h"
using namespace std;

class GameState : public Hilmys {
public:
	// shows the turn (days) of the game
	static int m_turn;

public:
	//Constructor for every start iteration of the cycle (loop)
	GameState() : Hilmys() {
		cout << "Start of day " << m_turn + 1 << endl;
	}
	//Destructor for every end iteration of the cycle (loop)
	~GameState() {
		cout << "End of day " << m_turn + 1 << endl;
		m_turn++;
	}
};

//to declare static turn variable in main
int GameState::m_turn;