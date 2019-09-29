#include <memory>


class Controller;
class ProxyController;
class ServerController;
class StandaloneController;

using ControllerPtr = std::shared_ptr<Controller>;
using ProxyControllerPtr = std::shared_ptr<ProxyController>;
using ServerControllerPtr = std::shared_ptr<ServerController>;
using StandaloneControllerPtr = std::shared_ptr<StandaloneController>;
