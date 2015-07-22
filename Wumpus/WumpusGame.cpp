#include "WumpusGame.h"
#include <iostream>

WumpusGame::WumpusGame(void):lastCmd(NONE)
{
}


WumpusGame::~WumpusGame(void)
{
}

int WumpusGame::Initialize( int caveRoom )
{
	cave.ConstructRooms(caveRoom);

#ifdef _DEBUG
	for (int i = 0; i < caveRoom; ++i)
	{
		std::cout << "Roomid=" << i+1 << " connected with Room {"<< cave.At(i).ShowConnectRoomId() << "}\r\n";
	}
#endif

	int room_id = cave.RandRoom();
	wumpus.Initialize(room_id);
	cave.At(room_id).SpriteEnter(&wumpus);

#ifdef _DEBUG
	std::cout << "wumpus is in room" << room_id + 1;
#endif
	int hunter_room = -1;
	while (true)
	{
		hunter_room = cave.RandRoom();
		if (room_id != hunter_room)
		{
			hunter.Initialize(hunter_room - 1);
			cave.At(hunter_room - 1).SpriteEnter(&hunter);
			std::cout << "You are in " << caveRoom << " room!";
			break;
		}
	}

	int bat_room = -1;
	while (true)
	{
		bat_room = cave.RandRoom();
		if (room_id != bat_room && bat_room != hunter_room)
		{
			break;
		}
	}
	
	return 0;
}

int WumpusGame::Start()
{
	while( hunter.Alive() || wumpus.Alive() )
	{
		int roomId = PraseCommand(lastCmd);
		ExcetuCommand(lastCmd, roomId);		
	}

	Stop();

	return 0;
}

int WumpusGame::Stop()
{
	return 0;
}

void WumpusGame::ExcetuCommand( CMD command, int roomId )
{
	switch (command)
	{
	case MOVE:
		{
			cave.At(hunter.AtRoom()).SpriteLeave();
			hunter.Move(roomId);
			if( !cave.At(roomId).SpriteEnter(&hunter) )
			{
				//room has something;
				if( WumpusEatHunter() || DroptoTrap(roomId) )
				{
					std::cout << "game over!\r\n";
					hunter.Dead();
				}
				else
				{
					//蝙蝠将玩家随机传送进一个房间,然后蝙蝠回到原房间
					roomId = cave.RandRoom();
					std::cout << "Meet a bat! It had catched you to Room" << roomId;
					ExcetuCommand(MOVE, roomId);
				}
			}
		}
		break;
	case SHOOT:
		{
			if(hunter.Shoot())
			{
				if(cave.Hit(roomId))
				{
					std::cout << "Congratulation, you killed the wumpus!\r\n"
						"Would you try again?(Y/N)";
					char c = '0';
					std::cin >> c;
					GameOver( c == 'Y' || c == 'y' );
				}
				else
				{
					wumpus.Move();
					if(WumpusEatHunter())
					{
						hunter.Dead();
					}
				}
			}
			else
			{
				std::cout << "It's a pity, you have no more than one arrow that can kill the wumpus!\r\n"
					"Would you try again?(Y/N)";
				char c = '0';
				std::cin >> c;
				GameOver( c == 'Y' || c == 'y' );
			}
		}
		break;
	default:
		break;
	}
	
}

int WumpusGame::PraseCommand( CMD& lastCmd )
{
	Prompt();
	std::cout << "Input command:>";

	char c;
	int id;
	std::cin >> c >> id;
	if (c == 'm')
	{
		lastCmd = MOVE;

		//将移动到的房间不是与当前房间相连时应重新输入
		if (!cave.At(hunter.AtRoom()).Connected(cave.At(id - 1)))
		{
			PraseCommand(lastCmd);
		}
	}
	if (c == 's')
	{
		lastCmd = SHOOT;
	}

	return id - 1;
}

void WumpusGame::GameOver(bool reAgain)
{
	if (reAgain)
	{
		Initialize(20);
	}
	else
	{
		exit(0);
	}
}

bool WumpusGame::WumpusEatHunter()
{
	return wumpus.AtRoom() == hunter.AtRoom();
}

void WumpusGame::Prompt()
{
	std::string ostring = cave.At(hunter.AtRoom()).ShowConnectRoomId();
	std::string prompt = "for each room,you can hear ";
	std::cout << "your room connected with rooms : " << ostring << "\r\n";
	std::string warnning = cave.At(hunter.AtRoom()).OnWarn();
	if (!warnning.empty())
	{
		std::cout << prompt << warnning;
	}
}

bool WumpusGame::DroptoTrap(int roomId)
{
	return false;
}
