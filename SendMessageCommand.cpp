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
#include <iostream>
using namespace std;

/**
 * @brief Constructs a SendMessageCommand
 * @param r Chat room where message will be sent
 * @param u User sending the message
 * @param m Message content
 */
SendMessageCommand::SendMessageCommand(ChatRoom* r, User* u, const string& m)
: Command(r,u,m) {}

/**
 * @brief Executes the send command if user has permission
 */
void SendMessageCommand::execute()
{
    if(!room || !fromUser) 
    {
        return;
    }
    
    if(!fromUser->getState().canSend())
    {
        cout << "[" << room->name() << "] " << fromUser->getName()
        << " cannot send in state: " << fromUser->getState().name() << endl;
        return;
    }
    room->sendMessage(message, fromUser);
}
