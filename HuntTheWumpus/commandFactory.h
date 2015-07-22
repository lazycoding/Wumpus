#pragma once
#include "command_parser.h"
class Command;
class CommandFactory
{
public:
	static Command* Create(CommandParser::CommandType);
};

