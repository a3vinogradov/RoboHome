#pragma once
#include <TFT_eSPI.h>
#include "IDisplay.h"

class DisplayTFT_1_28: public CBaseDisplay
{
protected: 
    virtual void Refresh() override;

public:
    DisplayTFT_1_28();

private:
    TFT_eSPI _tft_espi;

    const uint16_t SCREEN_WIDTH = 240;
    const uint16_t SCREEN_HEIGHT = 240;
    const uint16_t CENTER_X = 120;
    const uint16_t CENTER_Y = 120;
    const uint16_t RADIUS = 110;  // Радиус основной окружности
    
    // Цвета (зависит от вашей палитры)
    const uint16_t COLOR_BG = TFT_BLACK;
    const uint16_t COLOR_TRACK = TFT_DARKGREY;    // Фоновая дорожка
    const uint16_t COLOR_PROGRESS = TFT_CYAN;     // Активный прогресс
    const uint16_t COLOR_PROGRESS_BG = TFT_NAVY;  // Фон прогресса    
    
    void DrawProgressCircle(unsigned short percent) ;
    void drawAngleLine(int angle, uint16_t color) ;

    void drawArc(unsigned short percent, uint16_t colorActive, uint16_t colorInactive); 

};