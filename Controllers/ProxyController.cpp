#include "ProxyController.h"
#include "Components/RemoteInputComponent.h"


ProxyController::ProxyController()
{
	SetInput(std::make_shared<RemoteInputComponent>());
}

ProxyController::~ProxyController()
{
}
