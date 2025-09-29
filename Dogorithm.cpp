/*
Bugs Bunnies
*/
/**
 * @file Dogorithm.cpp
 * @brief Implementation of the Dogorithm chat room class
 * @author Taskeen Abdoola (u22698681), Kiolin Gounden (u22647300)
* @date 2025-09-27
 */

#include "Declarations.cpp"
#include <iostream>
using namespace std;

/**
 * @brief Constructs a Dogorithm chat room with fixed name
 */
Dogorithm::Dogorithm() : ChatRoom("Dogorithm") {}

/**
 * @brief Registers a user to the Dogorithm chat room
 * @param u Pointer to the user to register
 */
void Dogorithm::registerUser(User* u)
{
    users.push_back(u);
    if(u) 
    {
        u->addRoom(this);
    }
    cout << "[Dogorithm] Registered: " << (u ? u->getName() : "null") << endl;
}


/**
 * @brief Removes a user from the Dogorithm chat room
 * @param u Pointer to the user to remove
 */
void Dogorithm::removeUser(User* u)
{
    for(size_t i=0;i<users.size();++i)
    {
        if(users[i]==u)
        { 
            users.erase(users.begin()+i); 
            break; 
        }
    }
    cout << "[Dogorithm] Removed: " << (u ? u->getName() : "null") << endl;
}
