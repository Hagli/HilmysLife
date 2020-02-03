#pragma once
#include <iostream>
#include <string>

class Hilmys {
public:
	enum level { //makes methods more readible
		lvlhap = 0, lvlhyg, lvlsoc, lvlhelt, lvlmon
	};

protected: //variable stats
	int m_hap;
	int m_hyg;
	int m_soc;
	int m_helt;
	int m_mon;

public: //for base functions that manipulates the stats
	//Manipulate up the stats by "y"
	void up(level x, int y) {
		switch (x) {
		case(lvlhap):
			m_hap = m_hap + y;
			if (m_hap > 100) {
				m_hap = 100;
				std::cout <<  m_hap;
			}
			break;
		case(lvlhyg): m_hyg = m_hyg + y;
			if (m_hyg > 100) {
				m_hyg = 100;
				std::cout <<  m_hyg;
			}
			break;
		case(lvlsoc): m_soc = m_soc + y;
			if (m_soc > 100) {
				m_soc = 100;
				std::cout <<  m_soc;
			}
			break;
		case(lvlhelt): m_helt = m_helt + y;
			if (m_helt > 100) {
				m_helt = 100;
				std::cout <<  m_helt;
			}
			break;
		case(lvlmon): m_mon = m_mon + y;
			if (m_mon > 100) {
				m_mon = 100;
				std::cout <<  m_mon;
			}
			break;
		}
	}

	//Manipulate down the stats by "y"
	void down(level x, int y) {
		switch (x) {
		case(lvlhap): m_hap = m_hap - y;
			if (m_hap < 0) {
				m_hap = 0;
				std::cout <<  m_hap;
			}
			break;
		case(lvlhyg): m_hyg = m_hyg - y;
			if (m_hyg < 0) {
				m_hyg = 0;
				std::cout <<  m_hyg;
			}
			break;
		case(lvlsoc): m_soc = m_soc - y;
			if (m_soc < 0) {
				m_soc = 0;
				std::cout <<  m_soc;
			}
			break;
		case(lvlhelt): m_helt = m_helt - y;
			if (m_helt < 0) {
				m_helt = 0;
				std::cout <<  m_helt;
			}
			break;
		case(lvlmon): m_mon = m_mon - y;
			if (m_mon < 0) {
				m_mon = 0;
				std::cout <<  m_mon;
			}
			break;
		}
	}

public: //method for activities, made with the base manipulation function
	//Eat
	void act0(int y) {
		up(lvlhelt, y);
		up(lvlhap, y);
	}
	 
	//Play
	void act1(int y) {
		up(lvlhap, y);
	}

	//Bath
	void act2(int y) {
		up(lvlhyg, y);
	}

	//Talkto
	void act3(int y) {
		up(lvlsoc, y);
	}

	//Work
	void act4(int y) {
		up(lvlmon, y);
		down(lvlhap, y);
	}

	//Starve
	void act5(int y) {
		down(lvlhap, y);
		down(lvlhelt, y);
	}

	//Bored
	void act6(int y) {
		down(lvlhap, y);
	}

	//Dirty
	void act7(int y) {
		down(lvlhap, y);
	}

	//Lonely
	void act8(int y) {
		down(lvlsoc, y);
		down(lvlhap, y);
	}

	//Buy
	void act9(int y) {
		down(lvlmon, y);
		up(lvlhap, y);
	}

	std::string acts[6] = { "1. Makan, ", "2. Main, ", "3. Mandi, ", "4. Bicara, ", "5. Bekerja"};
	std::string food[3] = { "1. Bakso, ", "2. Nasi goreng, ", "3. Permen" };
	std::string game[3] = { "1. CoD, ", "2. ML, ", "3. The chicken game" };
	std::string time[3] = { "1. Sebentar, ", "2. Moderate, ", "3. Lembur" };

	//Choosing activity
	void choose() {
		int a,b;
		std::cout << "Pick an activity, type in the number " << std::endl;
		for (int i = 0; i < 6; i++) {
			std::cout << acts[i] << std::endl;
		}
		std::cout << std::endl;
		std::cin >> a;
		switch (a-1) {
		case(0):std::cout << "Pilih makanan yang ingin dimakan, type in the number " << std::endl;
			for (int i = 0; i < 3; i++) {
				std::cout << food[i] << std::endl;
			}
			std::cin >> b;
			switch (b) {
			case(1):act0(30);
				act9(30);
				break;
			case(2):act0(20);
				act9(20);
				break;
			case(3):act0(10);
				act9(10);
				break;
			default: std::cout << "Nah man, try again " << std::endl;
				choose();
				break;
			}
			break;
		case(1):std::cout << "Pilih permainan yang ingin di mainkan, type the number " << std::endl;
			for (int i = 0; i < 3; i++) {
				std::cout << game[i] << std::endl;
			}
			std::cin >> b;
			switch (b) {
			case(1):act1(30);
				act9(30);
				break;
			case(2):act1(20);
				act9(20);
				break;
			case(3):act1(10);
				break;
			default: std::cout << "Nah man, try again " << std::endl;
				choose();
				break;
			}
			break;
		case(2):act2(50);
			break;
		case(3):act3(30);
			break;
		case(4):std::cout << "Pilih lama waktu, type the number " << std::endl;
			for (int i = 0; i < 3; i++) {
				std::cout << time[i] << std::endl;
			}
			std::cin >> b;
			switch (b) {
			case(1):act4(30);
				break;
			case(2):act4(40);
				break;
			case(3):act4(50);
				break;
			default: std::cout << "Nah man, try again " << std::endl;
				choose();
				break;
			}
			break;
		default: std::cout << "Nah man, try again " << std::endl;
			choose();
			break;
		}
	}

public: //Constructor and destructor
	//Constructor, set stats
	Hilmys() {
		std::cout << "Hilmys is created" << std::endl;
		m_hap = 100;
		m_hyg = 100;
		m_soc = 100;
		m_helt = 100;
		m_mon = 100;
	}

	//Destructor, called when the game ends
	~Hilmys() {
		if ((m_hap == 0) || (m_helt == 0) || (m_soc == 0) || (m_helt == 0) || (m_mon == 0)) {
			std::cout << "Hilmy is dead, oof" << std::endl;
		}
		else {
			std::cout << "Congrats, you win " << std::endl;
		}
	}
};

int a = 1;