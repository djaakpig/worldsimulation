#include <list>
#include <memory>


class Actor;

using ActorPtr = std::shared_ptr<Actor>;
using ActorList = std::list<ActorPtr>;
