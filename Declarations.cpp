/*
Bugs Bunnies
*/
/**
 * @file Declarations.cpp
 * @brief Header file containing all class declarations and forward declarations
 * @author Taskeen Abdoola (u22698681), Kiolin Gounden (u22647300)
* @date 2025-09-27
 */

#ifndef DECLARATIONS_CPP
#define DECLARATIONS_CPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User; class ChatRoom;

/**
 * @brief Iterator for iterating through users in a chat room
 */
class UserIterator
{
    const vector<User*>* d; size_t i;
public:
    UserIterator(const vector<User*>* p);
    bool hasNext() const;
    User* next();
};

/**
 * @brief Iterator for iterating through messages in chat history
 */
class MessageIterator
{
    const vector<string>* d; size_t i;
public:
    MessageIterator(const vector<string>* p);
    bool hasNext() const;
    string next();
};

/**
 * @brief Abstract base class for user states
 */
class UserState
{
public:
    virtual ~UserState() {}
    virtual bool canSend() const = 0;
    virtual bool canReceive() const = 0;
    virtual string name() const = 0;
};

/**
 * @brief State representing active users who can send and receive messages
 */
class ActiveState : public UserState
{
public:
    bool canSend() const;
    bool canReceive() const;
    string name() const;
};

/**
 * @brief State representing muted users who can receive but not send messages
 */
class MutedState : public UserState
{
public:
    bool canSend() const;
    bool canReceive() const;
    string name() const;
};

/**
 * @brief State representing banned users who cannot send or receive messages
 */
class BannedState : public UserState
{
public:
    bool canSend() const;
    bool canReceive() const;
    string name() const;
};

/**
 * @brief Abstract base class for chat rooms implementing mediator pattern
 */
class ChatRoom{
protected:
    string _name;
    vector<User*> users;
    vector<string> chatHistory;
public:
    ChatRoom(const string& n);
    virtual ~ChatRoom(){}

    virtual void registerUser(User* u) = 0;
    virtual void removeUser(User* u) = 0;

    virtual void sendMessage(const string& message, User* fromUser);
    virtual void saveMessage(const string& message, User* fromUser);

    UserIterator    createUserIterator() const;
    MessageIterator createMessageIterator() const;

    const string& name() const 
    { 
        return _name; 
    }
};

/**
 * @brief Concrete chat room implementation - CtrlCat
 */
class CtrlCat : public ChatRoom
{
public:
    CtrlCat();
    void registerUser(User* u);
    void removeUser(User* u);
};

/**
 * @brief Concrete chat room implementation - Dogorithm
 */
class Dogorithm : public ChatRoom
{
public:
    Dogorithm();
    void registerUser(User* u);
    void removeUser(User* u);
};

/**
 * @brief Abstract base class for command pattern implementation
 */
class Command
{
protected:
    ChatRoom* room;
    User* fromUser;
    string message;
public:
    Command(ChatRoom* r, User* u, const string& m);
    virtual ~Command(){}
    virtual void execute() = 0;
};

/**
 * @brief Command for sending messages in chat rooms
 */
class SendMessageCommand : public Command
{
public:
    SendMessageCommand(ChatRoom* r, User* u, const string& m);
    void execute();
};

/**
 * @brief Command for saving messages to chat history
 */
class SaveMessageCommand : public Command
{
public:
    SaveMessageCommand(ChatRoom* r, User* u, const string& m);
    void execute();
};

/**
 * @brief Command for logging messages to output
 */
class LogMessageCommand : public Command
{ 
public:
    LogMessageCommand(ChatRoom* r, User* u, const string& m);
    void execute();
};

/**
 * @brief Class representing a user in the chat system
 */
class User{
    string _name;
    std::vector<ChatRoom*> chatRooms;
    std::vector<Command*> commandQueue;
    UserState* state;
public:
    explicit User(const string& n);
    virtual ~User();

    const string& getName() const 
    { 
        return _name; 
    }
    void setState(UserState* s);
    const UserState& getState() const 
    { 
        return *state; 
    }
    void addRoom(ChatRoom* r)
    { 
        chatRooms.push_back(r); 
    }

    virtual void send(const string& message, ChatRoom& room);
    virtual void receive(const string& message, User* fromUser, ChatRoom& room);

    void addCommand(Command* c){ if(c) commandQueue.push_back(c); }
    void executeAll();
};

/* Named users */
/**
 * @brief Concrete user implementation - Name1
 */
class Name1 : public User{ public: Name1(); };
/**
 * @brief Concrete user implementation - Name2
 */
class Name2 : public User{ public: Name2(); };
/**
 * @brief Concrete user implementation - Name3
 */
class Name3 : public User{ public: Name3(); };

#endif
