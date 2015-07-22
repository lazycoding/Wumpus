#include <string>
#include <vector>
#include <iostream>
#include <memory>
using namespace std;

#include "hunt_game.h"
#include "command_parser.h"

int main()
{
	try
	{
		HuntGame& game = HuntGame::getHuntGame();
		game.Initialize();
		CommandParser cmd_parser;
		while (!game.IsOver())
		{
			string s = game.PromptDanger();
			cout << s << endl;		
			bool success_parse = false;
			bool valid_param = true;
			while (!success_parse || !valid_param)
			{				
				cin >> s;
				success_parse = cmd_parser.Parse(s);	
				valid_param = game.ValidParam(cmd_parser);
				if(!success_parse)
					cout << "wrong command-format, re-input:";
				if(!valid_param)
					cout << "wrong command-parameters, input again:";
			}					
			s = cmd_parser.ToString();
			cout << s << endl;
			game.AgentAct(cmd_parser);
		}
		if( game.IsWin() )
			cout << "Greate, you win!\n";
		else
			cout << "regrettably, you were eaten by wumpus!\n";
	}
	catch(...)
	{

	}
	system("Pause");
	return 0;
}
