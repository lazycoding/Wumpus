#ifndef _ANGENT_H__
#define _ANGENT_H__
class Cavern;
class Agent
{
public:
	Agent():number_of_arrow(3),current_cavern_index(-1)
	{
	}

	~Agent()
	{
	}
	void Move(int);
	bool Shot(int);
	int getCurrentCavern() const;
	void setCurrentCavern(int cavern_of_index);
	bool IsExhaustArrow() const;
	bool IsAlive() const;
	void BeKilled();
private:
	int number_of_arrow;
	int current_cavern_index;
	bool alive;
};  
#endif // !_ANGENT_H__
