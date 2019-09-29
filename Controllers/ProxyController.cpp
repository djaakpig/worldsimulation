#include "ProxyController.h"
#include "RemoteInputComponent.h"


ProxyController::ProxyController()
{
	SetInput(std::make_shared<RemoteInputComponent>());
}

ProxyController::~ProxyController()
{
}
