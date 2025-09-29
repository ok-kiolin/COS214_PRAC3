/*
Bugs Bunnies
*/
/**
 * @file BannedState.cpp
 * @brief Implementation of the BannedState class representing banned user state
 * @author Taskeen Abdoola (u22698681), Kiolin Gounden (u22647300)
 * @date 2025-09-27
 */


#include "Declarations.cpp"

/**
 * @brief Gets the name of the state
 * @return String "Banned" representing the state name
 */
string BannedState::name() const 
{ 
    return "Banned"; 
}

/**
 * @brief Checks if user can send messages in this state
 * @return false - Banned users cannot send messages
 */
bool BannedState::canSend() const 
{ 
    return false; 
}

/**
 * @brief Checks if user can receive messages in this state
 * @return false - Banned users cannot receive messages
 */
bool BannedState::canReceive() const 
{ 
    return false; 
}
