#pragma once
#include <iostream>
using namespace std;

class Hilmys {
public:
	enum level { //makes methods more readible
		lvlhap = 0, lvlhyg, lvlsoc, lvlhelt, lvlmon
	};

protected: //variable stats
	int m_hap;
	int m_hyg;
	int m_;
	int m_helt;
	int m_mon;

public: //for base functions that manipulates the stats
	//show stats
	void show(level x) {
		switch (x) {
		case(lvlhap): cout << m_hap << endl;
			break;
		case(lvlhyg): cout << m_hyg << endl;
			break;
		case(lvlsoc): cout << m_ << endl;
			break;
		case(lvlhelt): cout << m_helt << endl;
			break;
		case(lvlmon): cout << m_mon << endl;
			break;
		}
	}

	//Manipulate up the stats by "y"
	void up(level x, int y) {
		switch (x) {
		case(lvlhap): m_hap = m_hap + y;
			break;
		case(lvlhyg): m_hyg = m_hyg + y;
			break;
		case(lvlsoc): m_ = m_ + y;
			break;
		case(lvlhelt): m_helt = m_helt + y;
			break;
		case(lvlmon): m_mon = m_mon + y;
			break;
		}
	}

	//Manipulate down the stats by "y"
	void down(level x, int y) {
		switch (x) {
		case(lvlhap): m_hap = m_hap - y;
			break;
		case(lvlhyg): m_hyg = m_hyg - y;
			break;
		case(lvlsoc): m_ = m_ - y;
			break;
		case(lvlhelt): m_helt = m_helt - y;
			break;
		case(lvlmon): m_mon = m_mon - y;
			break;
		}
	}

public: //method for activities, made with the base manipulation function
	//Activity 1
	void eat(int y) {
		up(lvlhelt, y);
		up(lvlhap, y);
		show(lvlhelt);
		show(lvlhap);
	}

	//Activity 2
	void play(int y) {
		up(lvlhap, y);
		show(lvlhap);
	}

	//Activity 3
	void bath(int y) {
		up(lvlhyg, y);
		show(lvlhyg);
	}

	//Activity 4
	void talkto(int y) {
		up(lvlsoc, y);
		show(lvlsoc);
	}

	//Activity 5
	void work(int y) {
		up(lvlmon, y);
		down(lvlhap, y);
		show(lvlmon);
		show(lvlhap);
	}

	//Activity 6
	void starve(int y) {
		down(lvlhelt, y);
		show(lvlhelt);
	}

	//Activity 7
	void bored(int y) {
		down(lvlhap, y);
		show(lvlhap);
	}

	//Activity 8
	void dirty(int y) {
		down(lvlhap, y);
		show(lvlhap);
	}

	//Activity 9
	void embarass(int y) {
		down(lvlsoc, y);
		down(lvlhap, y);
		show(lvlsoc);
		show(lvlhap);
	}

	//Activity 10
	void buy(int y) {
		down(lvlmon, y);
		up(lvlhap, y);
		show(lvlmon);
		show(lvlhap);
	}

public: //Constructor and destructor
	//Constructor, set stats
	Hilmys() {
		cout << "Hilmys is created" << endl;
		m_hap = 100;
		m_hyg = 100;
		m_ = 100;
		m_helt = 100;
		m_mon = 100;
	}

	//Destructor
	~Hilmys() {
		cout << "Hilmy is dead, oof" << endl;
	}
};

