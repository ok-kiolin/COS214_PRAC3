/*
Bugs Bunnies*/

/**
 * @file ChatRoom.cpp
 * @brief Implementation of the ChatRoom base class for chat room functionality
 * @author Taskeen Abdoola (u22698681), Kiolin Gounden (u22647300)
* @date 2025-09-27
 */

#include "Declarations.cpp"
#include <iostream>
using namespace std;

/**
 * @brief Constructs a ChatRoom with specified name
 * @param n The name of the chat room
 */

ChatRoom::ChatRoom(const string& n) : _name(n) {}

/**
 * @brief Sends a message to all users in the room except the sender
 * @param message The message to send
 * @param fromUser Pointer to the user sending the message
 */

void ChatRoom::sendMessage(const string& message, User* fromUser)
{
    for(size_t i=0;i<users.size();++i)
    {
        User* u = users[i];
        if(u && u != fromUser)
        {
            u->receive(message, fromUser, *this);
        }
    }
}

/**
 * @brief Saves a message to the chat history
 * @param message The message to save
 * @param fromUser Pointer to the user who sent the message (unused in base)
 */


void ChatRoom::saveMessage(const string& message, User*)
{
    chatHistory.push_back(message);
}

/**
 * @brief Creates an iterator for users in the chat room
 * @return UserIterator object for iterating through users
 */


UserIterator ChatRoom::createUserIterator() const 
{ 
    return UserIterator(&users); 
}

/**
 * @brief Creates an iterator for messages in the chat history
 * @return MessageIterator object for iterating through messages
 */

MessageIterator ChatRoom::createMessageIterator() const 
{ 
    return MessageIterator(&chatHistory); 
}
