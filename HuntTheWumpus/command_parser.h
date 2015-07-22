#ifndef _COMMAND_PARSER_H__
#define _COMMAND_PARSER_H__
#include <string>
#include <vector>

class CommandParser
{
public:
	enum CommandType{ Move, Shot };
	bool Parse(const std::string& _command);
	CommandType getCommand() const;
	const std::vector<int>& getParameters() const;
	std::string ToString() const;
private:
	CommandType command;
	std::vector<int> parameters;
};  
#endif // !_COMMAND_PARSER_H__
