#include "CStringLog.h"

CStringLog::CStringLog(const String eol)
{
    EOL = eol;
}

void CStringLog::Write(String text)
{
    Buffer += text;
    return;
}

void CStringLog::WriteLn(String text)
{
    Write(text);
    Write(EOL);
    return;
}

void CStringLog::Clear()
{
    Buffer = "";
    return;
}

String CStringLog::GetBuffer()
{
    return Buffer;
}
