/*
Bugs Bunnies
Taskeen Abdoola - u22698681
Kiolin Gounden - u22647300
*/

/*
 * User (Invoker) with State + Command queue
 */

#include "Declarations.cpp"
#include <iostream>
using namespace std;

User::User(const string& n) : _name(n), state(new ActiveState()) {}

User::~User()
{
    delete state;
    for(size_t i=0;i<commandQueue.size();++i) 
    {
        delete commandQueue[i];
    }
    commandQueue.clear();
}

void User::setState(UserState* s)
{
    if(state != s)
    { 
        delete state; 
        state = s; 
    }
}

void User::send(const string& message, ChatRoom& room)
{
    addCommand(new SendMessageCommand(&room, this, message));
    addCommand(new SaveMessageCommand(&room, this, message));
    addCommand(new LogMessageCommand (&room, this, message)); 
    executeAll();
}

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

void User::executeAll()
{
    for(size_t i=0;i<commandQueue.size();++i)
    { 
        commandQueue[i]->execute();
        delete commandQueue[i]; 
    }
    commandQueue.clear();
}
