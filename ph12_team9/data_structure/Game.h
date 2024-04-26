#pragma once
#ifndef GA_ME
#define GA_ME
#include<iostream>
#include<fstream>
#include"AlienArmy.h"
#include"EarthArmy.h"
#include"Rand_Gen.h"
using namespace std;
class Game
{
private:
	LinkedQueue<armyUnit*>*killed_list;
	priQueue<armyUnit*>* UML;
	AlienArmy* aliens;
	EarthArmy* humans;
	Rand_Gen*random_generator;
	int current_time;
	int N, Prop;
public:
	Game(string fileName);
	void attack();	
	void print_lists();
	void generate();
	void increament_time();
	int  get_current_time();
	//void test();
	void simulate();
	bool loadFromInput(string fileName);
	void add_to_killed_list(armyUnit* unit);
	AlienArmy* get_aliens_pointer();
	EarthArmy* get_humans_pointer();
	~Game();



};
#endif

