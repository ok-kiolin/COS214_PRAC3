/*
Bugs Bunnies
*/
/**
 * @file TestingMain.cpp
 * @brief Test suite for chat system functionality
 * @author Taskeen Abdoola (u22698681), Kiolin Gounden (u22647300)
 * @date 2025-09-27
 */


#include "Declarations.cpp"
#include <iostream>
using namespace std;

/**
 * @brief Counts users in a chat room
 * @param room Chat room to count users from
 * @return Number of users in the room
 */
static size_t countUsers(ChatRoom& room) 
{
    UserIterator it = room.createUserIterator();
    size_t n = 0;
    while (it.hasNext()) 
    { 
        it.next(); ++n; 
    }
    return n;
}

/**
 * @brief Counts messages in chat history
 * @param room Chat room to count history from
 * @return Number of messages in history
 */
static size_t countHistory(ChatRoom& room) 
{
    MessageIterator it = room.createMessageIterator();
    size_t n = 0;
    while (it.hasNext()) 
    { 
        it.next(); ++n; 
    }
    return n;
}

/**
 * @brief Gets the last message in chat history
 * @param room Chat room to get last message from
 * @return The last message string
 */
static string lastHistory(ChatRoom& room) 
{
    MessageIterator it = room.createMessageIterator();
    string last;
    while (it.hasNext())
    {
        last = it.next();
    } 
    return last;
}

/**
 * @brief Prints all users in a chat room
 * @param room Chat room to print users from
 */
static void printUsers(ChatRoom& room) 
{
    cout << "Users in [" << room.name() << "]: ";
    UserIterator it = room.createUserIterator();
    bool first = true;
    while (it.hasNext()) 
    {
        User* u = it.next();
        if (!first) 
        {
            cout << ", ";
        }
        cout << (u ? u->getName() : "null");
        first = false;
    }
    cout << endl;
}

/**
 * @brief Prints all messages in chat history
 * @param room Chat room to print history from
 */
static void printHistory(ChatRoom& room) 
{
    cout << "History of [" << room.name() << "]" << endl;
    MessageIterator it = room.createMessageIterator();
    int idx = 1;
    while (it.hasNext()) 
    {
        cout << idx++ << ". " << it.next() << endl;
    }
}

/**
 * @brief Tests if two values are equal
 * @param label Test description
 * @param got Actual value
 * @param want Expected value
 * @param fails Reference to failure counter
 */
static void expectEq(const char* label, size_t got, size_t want, int& fails) 
{
    if (got == want) 
    {
        cout << "[PASS] " << label << " == " << want << endl;
    } 
    else 
    {
        cout << "[FAIL] " << label << " got " << got << " (want " << want << ")" << endl;
        ++fails;
    }
}

/**
 * @brief Tests if a string ends with a given suffix
 * @param label Test description
 * @param got Actual string
 * @param suffix Expected suffix
 * @param fails Reference to failure counter
 */
static void expectStrEndsWith(const char* label, const string& got, const string& suffix, int& fails) 
{
    bool ok = got.size() >= suffix.size() && got.substr(got.size() - suffix.size(), suffix.size()) == suffix;
    if (ok) 
    {
        cout << "[PASS] " << label << endl;
    }
    else 
    { 
        cout << "[FAIL] " << label << " got: \"" << got << "\"" << endl; ++fails; 
    }
}

/**
 * @brief Main test function
 * @return 0 if all tests pass, 1 otherwise
 */
int main() 
{
    int fails = 0;

    cout << "=== Setup rooms & users ===" << endl;
    CtrlCat cats;
    Dogorithm dogs;

    Name1 a;  //will join both rooms
    Name2 b;  //cats only 
    Name3 c;  //dogs only 

    cats.registerUser(&a);
    cats.registerUser(&b);

    dogs.registerUser(&a);
    dogs.registerUser(&c);

    printUsers(cats);
    printUsers(dogs);

    expectEq("cats.userCount", countUsers(cats), 2, fails);
    expectEq("dogs.userCount", countUsers(dogs), 2, fails);
    expectEq("cats.historyCount (start)", countHistory(cats), 0, fails);
    expectEq("dogs.historyCount (start)", countHistory(dogs), 0, fails);

    cout << "\n=== Active sends (Command: send/save/log through Mediator) ===" << endl;
    a.send("Hello from Name1", cats);
    expectEq("cats.historyCount after a.send", countHistory(cats), 1, fails);
    expectStrEndsWith("cats.last ends with payload",
                      lastHistory(cats), "Name1: Hello from Name1", fails);

    b.send("We love CtrlCat!", cats);
    expectEq("cats.historyCount after b.send", countHistory(cats), 2, fails);
    expectStrEndsWith("cats.last ends with payload",
                      lastHistory(cats), "Name2: We love CtrlCat!", fails);

    a.send("woof meets code!", dogs);
    expectEq("dogs.historyCount after a.send", countHistory(dogs), 1, fails);
    expectStrEndsWith("dogs.last ends with payload",
                      lastHistory(dogs), "Name1: woof meets code!", fails);

    cout << "\n=== State: Muted cannot send (but can receive) ===" << endl;
    c.setState(new MutedState());
    size_t dogsBefore = countHistory(dogs);
    c.send("Muted attempt", dogs); // should NOT add to chatHistory
    expectEq("dogs.historyCount after muted c.send", countHistory(dogs), dogsBefore, fails);

    cout << "\n=== State: Reactivate then send ===" << endl;
    c.setState(new ActiveState());
    c.send("Now I can speak!", dogs);
    expectEq("dogs.historyCount after c re-activated", countHistory(dogs), dogsBefore + 1, fails);
    expectStrEndsWith("dogs.last ends with payload",
                      lastHistory(dogs), "Name3: Now I can speak!", fails);

    cout << "\n=== State: Banned cannot send or receive ===" << endl;
    a.setState(new BannedState());
    size_t catsBefore = countHistory(cats);
    a.send("should be blocked", cats);  // no chatHistory change
    expectEq("cats.historyCount after banned a.send", countHistory(cats), catsBefore, fails);

    // While banned, a also should not receive; b sends, which saves to chatHistory, but a's receive is suppressed.
    b.send("Only b should see this (a is banned)", cats);
    expectEq("cats.historyCount after b sends while a banned", countHistory(cats), catsBefore + 1, fails);

    // Bring a back to life for more tests
    a.setState(new ActiveState());

    cout << "\n=== Iterators over users & history ===" << endl;
    printUsers(cats);
    printUsers(dogs);
    printHistory(cats);
    printHistory(dogs);

    cout << "\n=== Remove users (Mediator removeUser) ===" << endl;
    dogs.removeUser(&c);
    expectEq("dogs.userCount after removing c", countUsers(dogs), 1, fails);

    cats.removeUser(&b);
    expectEq("cats.userCount after removing b", countUsers(cats), 1, fails);

    cout << "\n=== Post-removal send ===" << endl;
    a.send("Just me here now", dogs);
    expectEq("dogs.history keeps growing", countHistory(dogs), 3, fails);

    cout << "\n=== SUMMARY ===" << endl;
    if (fails == 0) cout << "All checks passed." << endl;
    else            cout << fails << " check(s) failed — review output above." << endl;

    return fails ? 1 : 0;
}
