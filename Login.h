#ifndef LOGIN_H
#define LOGIN_H

#include <string>

// Logs in the user and returns true if credentials match
bool login(std::string &loggedInUser);

// Changes the password after validating current password
void changePassword(const std::string &user);

// Reads password with masking using _getch()
std::string getMaskedInput();

#endif // LOGIN_H
