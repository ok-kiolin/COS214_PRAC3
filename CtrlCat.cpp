/*
Bugs Bunnies
*/

/**
 * @file CtrlCat.cpp
 * @brief Implementation of the CtrlCat chat room class
 * @author Taskeen Abdoola (u22698681), Kiolin Gounden (u22647300)
* @date 2025-09-27
 */

#include "Declarations.cpp"
#include <iostream>
using namespace std;

/**
 * @brief Constructs a CtrlCat chat room with fixed name
 */

CtrlCat::CtrlCat() : ChatRoom("CtrlCat") {}

/**
 * @brief Registers a user to the CtrlCat chat room
 * @param u Pointer to the user to register
 */

void CtrlCat::registerUser(User* u)
{
    users.push_back(u);
    if(u) 
    {
        u->addRoom(this);
    }
    cout << "[CtrlCat] Registered: " << (u ? u->getName() : "null") << endl;
}

/**
 * @brief Removes a user from the CtrlCat chat room
 * @param u Pointer to the user to remove
 */

void CtrlCat::removeUser(User* u)
{
    for(size_t i=0;i<users.size();++i)
    {
        if(users[i]==u)
        { 
            users.erase(users.begin()+i); 
            break; 
        }
    }
    cout << "[CtrlCat] Removed: " << (u ? u->getName() : "null") << endl;
}
