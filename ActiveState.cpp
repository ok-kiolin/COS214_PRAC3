/*
Bugs Bunnies
Taskeen Abdoola - u22698681
Kiolin Gounden - u22647300
*/

#include "Declarations.cpp"

string ActiveState::name() const 
{ 
    return "Active"; 
}

bool ActiveState::canSend() const 
{ 
    return true; 
}

bool ActiveState::canReceive() const 
{ 
    return true; 
}