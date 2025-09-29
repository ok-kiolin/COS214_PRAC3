/*
Bugs Bunnies
*/
/**
 * @file ActiveState.cpp
 * @brief Implementation of the ActiveState class representing active user state
 * @author Taskeen Abdoola (u22698681), Kiolin Gounden (u22647300)
 * @date 2025-09-27
 */

#include "Declarations.cpp"

/**
 * @brief Gets the name of the state
 * @return String "Active" representing the state name
 */
string ActiveState::name() const 
{ 
    return "Active"; 
}

/**
 * @brief Checks if user can send messages in this state
 * @return true - Active users can send messages
 */
bool ActiveState::canSend() const 
{ 
    return true; 
}

/**
 * @brief Checks if user can receive messages in this state
 * @return true - Active users can receive messages
 */
bool ActiveState::canReceive() const 
{ 
    return true; 
}