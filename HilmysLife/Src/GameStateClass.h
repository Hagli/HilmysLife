#pragma once
#include "HilmysClass.h"

class GameState : public Hilmys {
private:
	// shows the turn (days) of the game
	 static int m_turn;

public: // Manipulate game turn
	static void turnup() {
		m_turn++;
	}

	static void startsetturn() {
		m_turn = 1;
	}

public:
	void game() {
		while (m_turn < 10 && a) {
			turnup();
			std::cout << "Start of day " << m_turn << std::endl;
			choose();
			check();
		}
	}

	//checking stats
	void check() {
		if ((m_hap == 0) || (m_helt == 0) || (m_soc == 0) || (m_helt == 0) || (m_mon == 0)) {
			a = 0;
		}
	}

public:
	GameState() {
		m_turn = 0;
	}
};

//to declare static turn variable in main
int GameState::m_turn;