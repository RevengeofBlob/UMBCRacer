/* File:	Racer.cpp
 * Project:	Project 2
 * Author:	Ryan Baker
 * Date:	10/11/22
 * Section:	50/53
 * E-mail:	rbaker8@umbc.edu
 * Description:	Manages the Players and Track objects.
 */

#include "Race.h"

//Race
//Creates a new Race object
Race::Race(){}

//StartRace
//Resets the location of the players, sets the length of the track, increases the amount of Player's races.
//Calls RaceOptions until a player has won the race.
void Race::StartRace(){
  int length = 0; //Length of the track.
  int choice = 0; //What the player wants to do in the race.
  int winner = -1; //Index of the winner
  
  m_track.ResetLocation();
  m_track.SetLength(0);
  m_myPlayer.SetRaces(m_myPlayer.GetRaces() + 1);

  do{
    cout << "How long would you like the race?\n";
    cin >> length;
  } while (length < 1 || length > MAX_LENGTH);

  m_track.SetLength(length);
  m_track.PopulateObstacles();

  while (winner == -1){
    choice = RaceOptions();

    if (choice == 1){
      m_track.GetStatus();
    } else {
      ProgressRace(choice);
    }

    winner = m_track.CheckWin();
  }

  //If the user wins, increases their number of wins and increases one of the stats.
  if (winner == 0){
    cout << "You won the race!\n";
    
    m_myPlayer.IncreaseStat();
    m_myPlayer.IncreaseWins();
    
  } else {
    cout << "Player " << winner << " won the race!\n";
  }
  
}

//GetRacerInfo
//Sets the name of the user's player to their input.
void Race::GetRacerInfo(){
  string name;

  cout << "What is your racer's name\n";
  cin >> name;
  
  m_myPlayer.SetName(name);
}

//ProgressRace
//Sets the difficulty of this round's obstacle to a random value from 1-100.
//Given the stat index, compare the value of the stat operations to the obstacle difficulty.
//If the stat operations result in a number greater than or equal to the difficulty, result is a success, else failure.
void Race::ProgressRace(int stat){
  int difficulty = rand() % BASE_DIFFICULTY + 1;
  int statValue = m_myPlayer.GetStat(stat - 2);
  
  cout << "You are trying to progress the race!\n";

  if ((BASE_SKILL + (5 * statValue)) >= difficulty){
    cout << "You made it through the " << m_track.ConvertObstacle(0) << " obstacle!\n";
    m_track.IncrementLocation(0);
  } else {
    cout << "You fell!\n";
    m_myPlayer.SetFalls(m_myPlayer.GetFalls() + 1);
  }

  ProgressComputer(difficulty);
}

//MainMenu
//Asks the use what they would like to do and either start a new race, display the user's stats, or quit the game.
bool Race::MainMenu(){
  int choice = 0;

  cout << "What would you like to do?\n"
       << "1. Start New Race\n"
       << "2. View Racer History\n"
       << "3. Quit\n";
  cin >> choice;
  if (choice < 1 || choice > 3){
    return true;
  }
  
  switch(choice){
  case 1:
    StartRace();
    return true;
    break;
  case 2:
    m_myPlayer.DisplayStatus();
    return true;
    break;
  case 3:
    return false;
    break;
  default:
    return true;
    break;
  }    
}

//RaceOptions
//Asks the user what they would like to do during a race and either display the position of each player
//or attempts an obstacle with the corresponding stat.
int Race::RaceOptions(){
  int choice = 0;

  do{
    cout << "What would you like to do?\n"
	 << "1. Get Race Status\n"
         << "2. Try to Sprint (Speed)\n"
         << "3. Try to Dodge (Agility)\n"
         << "4. Try to Jump (Jump)\n";
    cin >> choice;
  } while (choice < 1 || choice > 4);

  return choice;
}

//ManageGame
//Starts the game. Displays the title, gets the name of the user, and calls MainMenu.
//If the user quits the MainMenu, thanks the user for playing.
void Race::ManageGame(){
  bool play = true;

  RaceTitle();
  GetRacerInfo();
  
  while(play){
    play = MainMenu();
  }

  cout << "Thank you for playing UMBC race!\n";
}

//ProgressComputer
//Sets the skill stat of each computer to a random number from 40-100.
//Given the difficulty, if the skill stat is greater than or equal to the difficulty, result is success, else failure.
void Race::ProgressComputer(int diff){
  int computerStat = 0;
  
  for (int i = 1; i < NUM_RACERS; i++){
    computerStat = (rand() * (COMP_MAX + 1 - COMP_MIN)) + COMP_MIN;

    if (computerStat >= diff){
      m_track.IncrementLocation(i);
      
      cout << "Player " << i << " made it through the " << m_track.ConvertObstacle(i) << " obstacle!\n";
    } else {
      cout << "Player " << i << " fell!\n";
    }
  }
}
