/*
Bugs Bunnies
*/
/**
 * @file User.cpp
 * @brief Implementation of User class with State pattern and Command queue
 * @author Taskeen Abdoola (u22698681), Kiolin Gounden (u22647300)
 * @date 2025-09-27
 */

#include "Declarations.cpp"
#include <iostream>
using namespace std;

/**
 * @brief Constructs a User with name and active state
 * @param n User name
 */
User::User(const string& n) : _name(n), state(new ActiveState()) {}

/**
 * @brief Destructor - cleans up state and command queue
 */
User::~User()
{
    delete state;
    for(size_t i=0;i<commandQueue.size();++i) 
    {
        delete commandQueue[i];
    }
    commandQueue.clear();
}

/**
 * @brief Sets user state
 * @param s New state to set
 */
void User::setState(UserState* s)
{
    if(state != s)
    { 
        delete state; 
        state = s; 
    }
}

/**
 * @brief Sends message by queuing commands
 * @param message Message to send
 * @param room Chat room to send to
 */
void User::send(const string& message, ChatRoom& room)
{
    addCommand(new SendMessageCommand(&room, this, message));
    addCommand(new SaveMessageCommand(&room, this, message));
    addCommand(new LogMessageCommand (&room, this, message)); 
    executeAll();
}

/**
 * @brief Receives message if allowed by state
 * @param message Received message
 * @param fromUser Sender user
 * @param room Chat room where received
 */
void User::receive(const string& message, User* fromUser, ChatRoom& room)
{
    if(!state->canReceive()) 
    {
        return;
    }
    cout << "[" << room.name() << "] " << _name
              << " received from " << (fromUser ? fromUser->getName() : "null")
              << ": " << message << endl;
}

/**
 * @brief Executes all queued commands
 */
void User::executeAll()
{
    for(size_t i=0;i<commandQueue.size();++i)
    { 
        commandQueue[i]->execute();
        delete commandQueue[i]; 
    }
    commandQueue.clear();
}
