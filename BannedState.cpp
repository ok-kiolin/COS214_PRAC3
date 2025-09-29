/*
Bugs Bunnies
Taskeen Abdoola - u22698681
Kiolin Gounden - u22647300
*/

#include "Declarations.cpp"

string BannedState::name() const 
{ 
    return "Banned"; 
}

bool BannedState::canSend() const 
{ 
    return false; 
}

bool BannedState::canReceive() const 
{ 
    return false; 
}
