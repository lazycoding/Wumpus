#include "commandFactory.h"
#include "agentmove.h"
#include "agentshot.h"

 Command* CommandFactory::Create(CommandParser::CommandType command_type)
 {
	 if(command_type == CommandParser::Move)
	 {
		 return new AgentMove;
	 }
	 if(command_type == CommandParser::Shot)
	 {
		 return new AgentShot;
	 }
	 return nullptr;
 }
