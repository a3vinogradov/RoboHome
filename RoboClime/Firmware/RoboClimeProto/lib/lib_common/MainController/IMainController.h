#pragma once

class IMainController
{
public:
    virtual void Setup() = 0;
    virtual void Exec() = 0;
};

class CMainController: public IMainController
{
public:
    virtual void Setup() override;
    virtual void Exec() override;
};
