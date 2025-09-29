/*
Bugs Bunnies
*/
/**
 * @file MutedState.cpp
 * @brief Implementation of MutedState class
 * @author Taskeen Abdoola (u22698681), Kiolin Gounden (u22647300)
 * @date 2025-09-27
 */


#include "Declarations.cpp"

/**
 * @brief Gets the state name
 * @return "Muted"
 */
string MutedState::name() const 
{ 
    return "Muted"; 
}

/**
 * @brief Checks if muted users can send messages
 * @return false - Muted users cannot send
 */
bool MutedState::canSend() const 
{ 
    return false; 
}

/**
 * @brief Checks if muted users can receive messages
 * @return true - Muted users can receive
 */
bool MutedState::canReceive() const 
{ 
    return true; 
}