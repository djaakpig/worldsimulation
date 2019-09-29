#include <memory>
#include <list>


class Component;
class MovementComponent;
class RemoteSessionComponent;
class InputComponent;
class AIComponent;
class RemoteInputComponent;
class UserInputComponent;

using ComponentPtr = std::shared_ptr<Component>;
using MovementComponentPtr = std::shared_ptr<MovementComponent>;
using RemoteSessionComponentPtr = std::shared_ptr<RemoteSessionComponent>;
using InputComponentPtr = std::shared_ptr<InputComponent>;
using AIComponentPtr = std::shared_ptr<AIComponent>;
using RemoteInputComponentPtr = std::shared_ptr<RemoteInputComponent>;
using UserInputComponentPtr = std::shared_ptr<UserInputComponent>;

using ComponentList = std::list<ComponentPtr>;
