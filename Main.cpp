#include <iostream>
#include <list>
#include <vector>
#include "Component.h"
#include "Object.h"
#include "Shape.h"
using namespace std;

using ObjectPtr = shared_ptr<Object>;

class Cell final
{
private:
	list<ObjectPtr> _objects;
public:
	bool Create()
	{
		return true;
	}
	void Destroy()
	{
	}
};
class Zone final
{
private:
	Point32i _start;
	Rectangle32i _size;
	Rectangle32i _numCells;
	vector<Cell> _cells;
public:
	Zone(
		const Point32i &start,
		const Rectangle32i &size,
		const Rectangle32i &numCells) :
		_start(start), _size(size), _numCells(numCells)
	{
	}
	~Zone() = default;
	bool Create()
	{
		_cells.resize(_numCells.GetWidth() * _numCells.GetHeight());
		return true;
	}
	void Destroy()
	{
		for (auto &cell : _cells)
		{
			cell.Destroy();
		}
		_cells.clear();
	}
	bool Spawn(const ObjectPtr &object)
	{
		return true;
	}
};

ObjectPtr NewCharacter(const string &name);
ObjectPtr NewMonster(const string &name);
ObjectPtr NewObstacle(const string &name);

int main()
{
	/*
	#include "Component.h"
	#include "Actor.h"
	#include "ServerController.h"
	#include "RemoteSessionComponent.h"
	#include "RemoteSessionComponent.h"


	////////////////////////////////////////
	// MAIN
	////////////////////////////////////////
	int main(int argc, char **args)
	{
		auto s1 = std::make_shared<RemoteSessionComponent>();
		auto s2 = std::make_shared<RemoteSessionComponent>();

		auto c1 = std::make_shared<ServerController>();
		auto c2 = std::make_shared<ServerController>();

		c1->SetRemoteSession(s1);
		c2->SetRemoteSession(s2);

		auto a1 = std::make_shared<Actor>();
		auto a2 = std::make_shared<Actor>();

		c1->Possess(a1);
		c2->Possess(a2);

		Timestamp prev;

		for(int32_t i = 0; 5 > i; ++i)
		{
			Timestamp now;
			const auto delta = now - prev;

			a1->Update(delta);
			a2->Update(delta);

			prev = now;
		}

		c1->Unpossess();
		c2->Unpossess();

		return 0;
	}
	*/

	const auto zone1 = make_shared<Zone>(
		Point32i{1, 1},
		Rectangle32i{1000, 1000},
		Rectangle32i{100, 100});
	const auto chr1 = NewCharacter("chr1");
	const auto chr2 = NewCharacter("chr2");
	const auto mon1 = NewMonster("mon1");
	const auto mon2 = NewMonster("mon2");
	const auto obs1 = NewObstacle("obs1");
	const auto obs2 = NewObstacle("obs2");
	zone1->Spawn(chr1);
	zone1->Spawn(chr2);
	zone1->Spawn(mon1);
	zone1->Spawn(mon2);
	zone1->Spawn(obs1);
	zone1->Spawn(obs2);
	return 0;
}

ObjectPtr NewCharacter(const string &name)
{
	const auto components = make_shared<Components>(
		name + ".components");
	const auto character = make_shared<Object>(
		name,
		components);
	return character;
}

ObjectPtr NewMonster(const string &name)
{
	const auto components = make_shared<Components>(
		name + ".components");
	const auto monster = make_shared<Object>(
		name,
		components);
	return monster;
}

ObjectPtr NewObstacle(const string &name)
{
	const auto components = make_shared<Components>(
		name + ".components");
	const auto obstacle = make_shared<Object>(
		name,
		components);
	return obstacle;
}
