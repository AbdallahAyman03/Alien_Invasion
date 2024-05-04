#include "Rand_Gen.h"
#include<iostream>
#include<fstream>
using namespace std;
Rand_Gen::Rand_Gen(Game* game):game_ptr(game)
{
	id_earth = 1;
	id_alien = 2000;
    ES_total = ET_total = EG_total = HU_total = AS_total = AM_total = AD_total = 0;
}
void Rand_Gen::setN(int x)
{
    N = x;
}
void Rand_Gen::setES(int x)
{
    ES = x;
}
void Rand_Gen::setET(int x)
{
    ET = x;
}
void Rand_Gen::setEG(int x)
{
    EG = x;
}
void Rand_Gen::setAS(int x)
{
    AS = x;
}
void Rand_Gen::setAD(int x)
{
    AD = x;
}
void Rand_Gen::setAM(int x)
{
    AM = x;
}
void Rand_Gen::setHU(int x)
{
    HU = x;
}
void Rand_Gen::setProp(int x)
{
    Prop = x;
}
void Rand_Gen::E_Cap(int x0, int x1)
{
    E_Cap0 = x0;
    E_Cap1 = x1;
}
void Rand_Gen::E_Pow(int x0, int x1)
{
    E_Pow0 = x0;
    E_Pow1 = x1;
}
void Rand_Gen::E_Health(int x0, int x1)
{
    E_Health0 = x0;
    E_Health1 = x1;
}
void Rand_Gen::A_Cap(int x0, int x1)
{
    A_Cap0 = x0;
    A_Cap1 = x1;
}
void Rand_Gen::A_Pow(int x0, int x1)
{
    A_Pow0 = x0;
    A_Pow1 = x1;
}
void Rand_Gen::A_Health(int x0, int x1)
{
    A_Health0 = x0;
    A_Health1 = x1;
}
int Rand_Gen::get_E_Pow0()
{
    return E_Pow0;
}
int Rand_Gen::get_E_Pow1()
{
    return E_Pow1;
}
int Rand_Gen::getAD_total()
{
    return AD_total;
}
int Rand_Gen::getAM_total()
{
    return AM_total;
}
int Rand_Gen::getAS_total()
{
    return AS_total;
}
int Rand_Gen::getES_total()
{
    return ES_total;
}
int Rand_Gen::getET_total()
{
    return ET_total;
}
int Rand_Gen::getEG_total()
{
    return EG_total;
}
int Rand_Gen::getHU_total()
{
    return HU_total;
}
//for earth army:
//arr[9]&&arr[10]---->power 
//arr[11]&&arr[12]--->health
//arr[13]&&arr[14]--->attack capacity
armyUnit* Rand_Gen::generate_earth_unit(int join_time)//generate earth unit
{
    int random_power = (rand() % (E_Pow1 -E_Pow0 +1) + E_Pow0);
    int random_health = (rand() % (E_Health1 - E_Health0 + 1) + E_Health0);
    int random_attack_capacity = (rand() % (E_Cap1 - E_Cap0 + 1) + E_Cap0);
    int b = rand() % 100 + 1;
    if (b <= ES)
    {
        //generate soldier
       earthSoldier* new_ES = new earthSoldier(id_earth++, join_time, random_health, random_power, random_attack_capacity, earth_soldier,game_ptr);
       ES_total++;
        return new_ES;
    }
    else if ( b <= ES+ET)
    {
        //generate tank
        tank* new_ET = new tank(id_earth++, join_time, random_health, random_power, random_attack_capacity, Tank,game_ptr);
        ET_total++;
        return new_ET;

    }
    else  if(b<=ES+ET+EG)
    {
        //generate gunnery
        Gunnery* new_gunnery = new Gunnery(id_earth++, join_time, random_health, random_power, random_attack_capacity,gunnery, game_ptr);
        EG_total++;
        return new_gunnery;
    }
    else
    {
        Heal_Soldier* new_heal = new Heal_Soldier(id_earth++, join_time, random_health, random_power, random_attack_capacity, Heal_soldier, game_ptr);
        HU_total++;
        return new_heal;
    }
   
    //random the data of this unit according of its range
    return nullptr;
}
//for alien army:
//arr[15]&&arr[16]---->power 
//arr[17]&&arr[18]--->health
//arr[19]&&arr[20]--->attack capacity
armyUnit* Rand_Gen::generate_alien_unit(int join_time)//generate a random alien unit
{
    int random_power = (rand() % (A_Pow1 - A_Pow0 + 1) + A_Pow0);
    int random_health = (rand() % (A_Health1 - A_Health0 + 1) + A_Health0);
    int random_attack_capacity = (rand() % (A_Cap1 - A_Cap0 + 1) + A_Cap0);

    int b = rand() % 100 + 1;
    if (b <= AS)
    {
        //generate soldier
        AllienSoldier* new_allienS = new AllienSoldier(id_alien++, join_time, random_health, random_power, random_attack_capacity,alien_soldier, game_ptr);
        AS_total++;
        return new_allienS;
    }
    
    else if (b <= AS+AM)
    {
        //generate monster
        monsters* new_monster = new monsters(id_alien++, join_time, random_health, random_power, random_attack_capacity,monster, game_ptr);
        AM_total++;
        return new_monster;
    }
    else
    {
        //generate drone
        Drones* new_drone = new Drones(id_alien++, join_time, random_health, random_power, random_attack_capacity,drone, game_ptr);
        AD_total++;
        return new_drone;
    }
    return nullptr;
}
