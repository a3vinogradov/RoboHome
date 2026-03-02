#include "CCompositorLog.h"

void CCompositorLog::Write(String text)
{
    for(int i = 0; i < Capacity; i++)
    {
        if (Children[i] != NULL)
        {
            Children[i]->Write(text);
        };
    };
    return;
}

CCompositorLog::CCompositorLog()
{
    for(int i = 0; i < Capacity; i++)
    {
        Children[i] = NULL;
    };
    return;
}

void CCompositorLog::WriteLn(String text)
{
    for(int i = 0; i < Capacity; i++)
    {
        if (Children[i] != NULL)
        {
            Children[i]->WriteLn(text);
        };
    };
    return;
}

void CCompositorLog::Clear()
{
    for(int i = 0; i < Capacity; i++)
    {
        if (Children[i] != NULL)
        {
            Children[i]->Clear();
        };
    };
    return;
}

bool CCompositorLog::Add(ILog* logger)
{
    if(IsExists(logger)) 
    {
        return false;
    };

    if(logger == NULL) 
    {
        return false;
    };

    for(int i = 0; i < Capacity; i++)
    {
        if (Children[i] == NULL)
        {
            Children[i] = logger;
            return true;
        };
    };    
    
    return false;
}

bool CCompositorLog::Remove(ILog *logger)
{
    if (logger == NULL)
    {
        return false;
    };

    for(int i = 0; i < Capacity; i++)
    {
        if(logger == Children[i])
        {
            Children[i] = NULL;
            return true;
        }
    }; 

    return false;
}

bool CCompositorLog::IsExists(ILog *logger)
{
    if (logger == NULL)
    {
        return false;
    };

    for(int i = 0; i < Capacity; i++)
    {
        if(logger == Children[i])
        {
            return true;
        }
    };

    return false;
}

unsigned short int CCompositorLog::Count()
{
    unsigned short count = 0;
    for(int i = 0; i < Capacity; i++)
    {
        if (Children[i] != NULL)
        {
            count++;
        };
    };
    return count;
}
