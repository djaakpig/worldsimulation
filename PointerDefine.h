#include <memory>


class Actor;
class Controller;
class Component;
class MovementComponent;
class InputComponent;

using ActorPtr = std::shared_ptr<Actor>;
using ControllerPtr = std::shared_ptr<Controller>;
using ComponentPtr = std::shared_ptr<Component>;
using MovementComponentPtr = std::shared_ptr<MovementComponent>;
using InputComponentPtr = std::shared_ptr<InputComponent>;
