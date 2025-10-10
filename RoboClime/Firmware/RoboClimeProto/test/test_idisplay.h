#pragma once
#include "unity.h"
#include "TypeDef.h"
#include "CLogDisplay.h"
#include "CStringLog.h"

DisplayData GetTestDisplayData() {
    static_assert(LOG_LENGTH==5, "Длинна логов должна быть равна 5");
    DisplayData data;
    data.SheetNumber = 0;
    data.ElapsedDayPercent = 45;
    data.CurrentTemperature = 12.34f;
    data.MinTemperature = -1.23f;
    data.MaxTemperature = 23.45f;
    data.MinLog[0] = 17.8f;
    data.MinLog[1] = 16.5f;
    data.MinLog[2] = 15.9f;
    data.MinLog[3] = 18.2f;
    data.MinLog[4] = 19.1f;
    data.MaxLog[0] = 27.3f;
    data.MaxLog[1] = 29.1f;
    data.MaxLog[2] = 26.8f;
    data.MaxLog[3] = 28.7f;
    data.MaxLog[4] = 25.9f;
    return data;
}


void test_create_display_console(void) {
    CStringLog log;
    CLogDisplay display(&log);
    // Просто проверяем, что объект создается без ошибок
    TEST_PASS();
}

void test_display_show_page0(void) {
    CStringLog log(";");
    CLogDisplay display(&log);
    IDisplay* pDisplay = &display;
    DisplayData data = GetTestDisplayData();
    pDisplay->Draw(data);
    TEST_ASSERT_EQUAL_STRING("0;45;12.34;23.45;-1.23;", log.GetBuffer().c_str());
}

void test_display_show_page1(void) {
    CStringLog log(";");
    CLogDisplay display(&log);
    IDisplay* pDisplay = &display;
    DisplayData data = GetTestDisplayData();
    data.SheetNumber = 1;
    pDisplay->Draw(data);
    TEST_ASSERT_EQUAL_STRING("1;45;17.80;16.50;15.90;18.20;19.10;27.30;29.10;26.80;28.70;25.90;", log.GetBuffer().c_str());
}

void test_display_draw_pointer(){
    CStringLog log(";");
    CLogDisplay display(&log);
    IDisplay* pDisplay = &display;
    DisplayData data = GetTestDisplayData();
    pDisplay->Draw(&data);
    TEST_ASSERT_EQUAL_STRING("0;45;12.34;23.45;-1.23;", log.GetBuffer().c_str());
}

void test_display_draw_void()
{
    CStringLog log(";");
    CLogDisplay display(&log);
    IDisplay* pDisplay = &display;
    DisplayData data = GetTestDisplayData();
    pDisplay->UpdateData(data);
    pDisplay->Draw();
    TEST_ASSERT_EQUAL_STRING("0;45;12.34;23.45;-1.23;", log.GetBuffer().c_str());
}