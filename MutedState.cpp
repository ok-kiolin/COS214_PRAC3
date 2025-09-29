/*
Bugs Bunnies
Taskeen Abdoola - u22698681
Kiolin Gounden - u22647300
*/

#include "Declarations.cpp"

string MutedState::name() const 
{ 
    return "Muted"; 
}

bool MutedState::canSend() const 
{ 
    return false; 
}

bool MutedState::canReceive() const 
{ 
    return true; 
}