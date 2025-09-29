/*
Bugs Bunnies
*/
/**
 * @file ChatRoom.cpp
 * @brief Implementation of the Command base class constructor
 * @author Taskeen Abdoola (u22698681), Kiolin Gounden (u22647300)
 * @date 2025-09-27
 */


#include "Declarations.cpp"

/**
 * @brief Constructs a Command object
 * @param r Pointer to the chat room where command will execute
 * @param u Pointer to the user executing the command
 * @param m The message associated with the command
 */
Command::Command(ChatRoom* r, User* u, const string& m) : room(r), fromUser(u), message(m) {}
