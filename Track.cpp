/* File:	Track.cpp
 * Project:	Project 2
 * Author:	Ryan Baker
 * Date:	10/08/22
 * Section:	50/53
 * E-mail:	rbaker8@umbc.edu
 * Description:	Holds the information about a race.
 */

#include "Track.h"

//Track (default
//Creates a new Track object and sets the length to the default length
//Sets the positions of each of the players to 0.
Track::Track(){
  SetLength(DEFAULT_LENGTH);
  ResetLocation();
}

//SetLength
//Sets the length of the track to the passed argument
void Track::SetLength(int length){
  m_length = length;
}

//PopulateObstacles
//For each position in the length of the track, sets the index in the obstacle array a value 0-2
//0 = Speed, 1 = Agility, 2 = Jump
void Track::PopulateObstacles(){
  for (int i = 0; i < m_length; i++){
    m_obstacle[i] = rand() % 2;
  }
}

//GetStatus
//Outputs the type of obstacle each player is on and the position of the obstacle
void Track::GetStatus(){
  cout << "You are on an " << ConvertObstacle(0) << " obstacle in (obstacle " << m_track[0] + 1 << " of " << m_length << ")\n";
  
  for (int i = 1; i < NUM_RACERS; i++){
    cout << "Player " << i << " is on a " << ConvertObstacle(i) << " obstacle in (obstacle " << m_track[i] + 1 << " of " << m_length << ")\n";
  }
}

//CheckWin
//Checks the position of each player. If one of the players has reached the end of the race,
//return their index from m_track. Starts from index 0 and goes up so ties go to the player in the lower index.
//If none of the players have reached the end, return -1.
int Track::CheckWin(){
  for (int i = 0; i < NUM_RACERS; i++){
    if (m_track[i] == m_length){
      return i;
    }
  }
  return -1;
}

//GetObstacle
//Given the location of a player, return the value of the obstacle index.
//0 = Speed, 1 = Agility, 2 = Jump.
int Track::GetObstacle(int location){
  return m_obstacle[location];
}

//IncrementLocation
//Given the player index, increase the position of the player by 1.
void Track::IncrementLocation(int player){
  m_track[player]++;
}

//ResetLocation
//Sets all of the positions of the players to 0.
void Track::ResetLocation(){
  for (int i = 0; i < NUM_RACERS; i++){
    m_track[i] = 0;
  }
}

//ConvertObstacle
//Given the player index, return the type of obstacle of the player's location.
string Track::ConvertObstacle(int player){
  return OBSTACLE_TYPE[GetObstacle(m_track[player])];
}
