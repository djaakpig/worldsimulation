#include <iostream>
#include "Actors/PtrDefine.h"
#include "World/Zone.h"
#include "Actors/Actor.h"


ActorPtr NewCharacter(const std::string& name);
ActorPtr NewMonster(const std::string& name);
ActorPtr NewObstacle(const std::string& name);

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

	const auto zone1 = std::make_shared<Zone>(
		Point32i{1, 1, 0},
		Rectangle32i{1000, 1000, 1000},
		Rectangle32i{100, 100, 100});
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

ActorPtr NewCharacter(const std::string& name)
{
	const auto character = std::make_shared<Actor>();
	return character;
}

ActorPtr NewMonster(const std::string& name)
{
	const auto monster = std::make_shared<Actor>();
	return monster;
}

ActorPtr NewObstacle(const std::string& name)
{
	const auto obstacle = std::make_shared<Actor>();
	return obstacle;
}
