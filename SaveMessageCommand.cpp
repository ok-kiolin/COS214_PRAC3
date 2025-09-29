/*
Bugs Bunnies
*/
/**
 * @file SaveMessageCommand.cpp
 * @brief Implementation of SaveMessageCommand class
 * @author Taskeen Abdoola (u22698681), Kiolin Gounden (u22647300)
* @date 2025-09-27
 */

#include "Declarations.cpp"
using namespace std;

/**
 * @brief Constructs a SaveMessageCommand
 * @param r Chat room where message will be saved
 * @param u User sending the message
 * @param m Message content
 */
SaveMessageCommand::SaveMessageCommand(ChatRoom* r, User* u, const string& m)
: Command(r,u,m) {}

/**
 * @brief Executes the save command if user has permission
 */
void SaveMessageCommand::execute()
{
    if (!room || !fromUser) 
    {
        return;
    }

    if (!fromUser->getState().canSend()) 
    {
        return;
    }

    room->saveMessage(fromUser->getName() + ": " + message, fromUser);
}

