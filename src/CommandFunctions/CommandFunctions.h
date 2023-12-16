#ifndef __GET_COMMAND_H__
#define __GET_COMMAND_H__

#include <string>
#include <string_view>
static std::string_view EXIT = "exit";
static std::string_view EDIT = "edit";
static std::string_view REVIEW = "review";
static std::string_view RECITE = "recite";
static std::string_view ADD = "add";
static std::string_view DELETE = "delete";
static std::string_view FIND = "find";
static std::string_view EMPTY = "empty";
static std::string_view CREATE = "create";
static std::string_view LIST = "list";
static std::string_view LOAD = "load";
static std::string_view UNLOAD = "unload";
static std::string_view HELP = "help";
static std::string_view LISTWORDS = "listwords";
static std::string_view DELETELIST = "deletelist";
static const int BUFSIZE = 1024;

void GetCommand();
int ConvertCommandToCode(const std::string& BUF);
void JumpToCertainMode();
void EditMode();
void ReviewMode();
void ReciteMode();
#endif