/*
Bugs Bunnies
Taskeen Abdoola - u22698681
Kiolin Gounden - u22647300
*/

#include "Declarations.cpp"

Command::Command(ChatRoom* r, User* u, const string& m) : room(r), fromUser(u), message(m) {}
