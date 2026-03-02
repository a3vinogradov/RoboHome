#include "CTimer.h"
CTimer::CTimer(IEnvironment* aEnv)
{
  _Env = aEnv;
  _Period = 2000;
  _LastTime = aEnv->Millis();
  _Active = false;
}

void CTimer::SetDelay(uint32_t value)
{
  _Period = value;
}

void CTimer::Start()
{
  _LastTime = millis();
  _Active = true;
}

void CTimer::ReStart()
{
  Start();
}

bool CTimer::IsActive()
{
  return ((millis() - _LastTime) < _Period);
}
