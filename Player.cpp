/* File:	Player.cpp
 * Project:	Project 2
 * Author:	Ryan Baker
 * Date:	10/08/2022
 * Section:	50/53
 * E-mail:	rbaker8@umbc.edu
 * Description:	Keeps track of the information about the user
 */

#include "Player.h"

//Player (Default Constructor)
//Creates a new Player object and sets the name to "Beannie" and each of the stats to 1.
Player::Player(){
  SetName("Beannie");
  
  for (int i = 0; i < NUM_STATS; i++){
    m_stat[i] = START_STAT;
  }
}

//Player (Overloaded)
//Creates a new Player object and sets the name to the passed argument and each of the stats to 1.
Player::Player(string name){
  SetName(name);
  
  for (int i = 0; i < NUM_STATS; i++){
    m_stat[i] = START_STAT;
  }
}

//GetName
//Returns the name of Player.
string Player::GetName(){
  return m_name;
}

//SetName
//Sets the name of the of player to the passed argument.
void Player::SetName(string name){
  m_name = name;
}

//GetSpeed
//Returns the value of the speed stat.
int Player::GetSpeed(){
  return m_stat[0];
}

//GetAgility
//Returns the value of the agility stat.
int Player::GetAgility(){
  return m_stat[1];
}

//GetJump
//Returns the value of the jump stat.
int Player::GetJump(){
  return m_stat[2];
}

//GetRaces
//Returns the number of races that have been played.
int Player::GetRaces(){
  return m_races;
}

//GetFalls
//Returns the total number of times Player has fallen in all of the races.
int Player::GetFalls(){
  return m_falls;
}

//SetRaces
//Sets the number of races to the passed argument.
void Player::SetRaces(int races){
  m_races = races;
}

//SetFalls
//Sets the number of falls to the passed argument.
void Player::SetFalls(int falls){
  m_falls = falls;
}

//DisplayStatus
//Outputs the name of Player, the number of races, wins, and falls, and the values of each of Player's stats.
void Player::DisplayStatus(){
  cout << "The Mighty Racer " << m_name << "\n"
       << "Races: " << m_races << "\n"
       << "Wins: " << m_wins << "\n"
       << "Falls: " << m_falls << "\n"
       << "\n\nStats\n"
       << "Speed: " << m_stat[0] << "\n"
       << "Agility: " << m_stat[1] << "\n"
       << "Jump: " << m_stat[2] << "\n";
}

//IncreaseStat
//Increases one of the stats by 1 unless that stat is 10.
void Player::IncreaseStat(){
  int choice = 0;
  bool valid = false;
  
  do{
    cout << "Which stat would you like to increase?\n"
	 << "1. Speed\n"
	 << "2. Agility\n"
	 << "3. Jump\n";
    cin >> choice;
    
    if (m_stat[choice - 1] == 10){
      cout << "This stat is maxed out, please choose another.\n";
    }
    else if (choice >= 1 && choice <= 3){
      m_stat[choice - 1]++;
      valid = true;
    }
  } while(!valid);
}

//GetStat
//Given the stat index, returns the value
int Player::GetStat(int stat){
  return m_stat[stat];
}

//IncreaseWins
//Increase the number of Player's wins by 1.
void Player::IncreaseWins(){
  m_wins++;
}
