#pragma once
#include "IEnvironment.hpp"

class CTimer
{
  private:
  IEnvironment* _Env;
  uint32_t _Period;
  uint32_t _LastTime;
  bool _Active;

  public:
	CTimer(IEnvironment* aEnv);
	void SetDelay(uint32_t value);
  void Start();
  void ReStart();
	bool IsActive();
};


