/*
Bugs Bunnies
*/
/**
 * @file Iterator.cpp
 * @brief Implementation of iterator classes for users and messages
 * @author Taskeen Abdoola (u22698681), Kiolin Gounden (u22647300)
* @date 2025-09-27
 */

#include "Declarations.cpp"

/**
 * @brief Constructs a UserIterator
 * @param p Pointer to vector of users to iterate over
 */
UserIterator::UserIterator(const vector<User*>* p) : d(p), i(0) {}

/**
 * @brief Checks if there are more users to iterate over
 * @return true if more users available, false otherwise
 */
bool UserIterator::hasNext() const 
{ 
    return d && i < d->size(); 
}

/**
 * @brief Gets the next user in iteration
 * @return Pointer to next user, or nullptr if no more users
 */
User* UserIterator::next() 
{ 
    return hasNext() ? (*d)[i++] : 0; 
}

/**
 * @brief Constructs a MessageIterator
 * @param p Pointer to vector of messages to iterate over
 */
MessageIterator::MessageIterator(const vector<string>* p) : d(p), i(0) {}

/**
 * @brief Checks if there are more messages to iterate over
 * @return true if more messages available, false otherwise
 */
bool MessageIterator::hasNext() const 
{ 
    return d && i < d->size(); 
}

/**
 * @brief Gets the next message in iteration
 * @return Next message string, or empty string if no more messages
 */
string MessageIterator::next()
{ 
    return hasNext() ? (*d)[i++] : ""; 
}