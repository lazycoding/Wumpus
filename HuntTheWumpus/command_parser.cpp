#include "command_parser.h"
#include <sstream>
using namespace std;

bool CommandParser::Parse(const string& _command)
{
	stringstream ss(_command);
	parameters.clear();
	switch(_command[0])
	{
	case 'm':
		{
			char cmd;
			int param;
			ss >> cmd >> param;
			if(!ss)
				return false;
			command = Move;
			parameters.push_back(param);
			break;
		}
	case 's':
		{
			char cmd;
			char c1;
			char c2;
			int p1,p2,p3;
			ss >> cmd >> p1;
			if(!ss)
				break; 		
			command = Shot;
			parameters.push_back(p1);
			ss >> c1 >> p2;
			if(c1 != '-' || !ss)
				break;
			parameters.push_back(p2);
			ss >> c2 >> p3;
			if(c2 != '-' || !ss)
				break;
			parameters.push_back(p3);			
			break;
		}
	default:
		return false;
	}
	return true;
}

CommandParser::CommandType CommandParser::getCommand() const
{
	return command;
}

const vector<int>& CommandParser::getParameters() const
{
	return parameters;
}

string CommandParser::ToString() const
{
	string log;
	ostringstream ss;
	if(command == Move)
	{
		ss << "you are moving to the cavern#" << parameters[0];
	}
	else
	{
		ss << "you shot to ";
		for(vector<int>::size_type i = 0; i < parameters.size(); ++i)
		{
			ss << parameters[i] << ' ';
		}
	}
	log = ss.str();
	return log;
}
