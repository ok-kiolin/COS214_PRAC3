/*
Bugs Bunnies
*/
/**
 * @file LogMessageCommand.cpp
 * @brief Implementation of LogMessageCommand for logging chat messages
 * @author Taskeen Abdoola (u22698681), Kiolin Gounden (u22647300)
 * @date 2025-09-27
 */

#include "Declarations.cpp"
#include <iostream>
using namespace std;

/**
 * @brief Constructs a LogMessageCommand
 * @param r Pointer to the chat room where message was sent
 * @param u Pointer to the user who sent the message
 * @param m The message content to log
 */
LogMessageCommand::LogMessageCommand(ChatRoom* r, User* u, const string& m)
: Command(r,u,m) {}


/**
 * @brief Executes the log command, outputting message details to console
 */
void LogMessageCommand::execute()
{
    if(room && fromUser)
    {
        cout << "[LOG][" << room->name() << "] "
        << fromUser->getName() << " -> \"" << message << "\"" << endl;
    }
}