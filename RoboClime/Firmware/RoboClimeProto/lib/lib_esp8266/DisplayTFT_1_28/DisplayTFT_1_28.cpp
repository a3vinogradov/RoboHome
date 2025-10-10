#include "DisplayTFT_1_28.h"

DisplayTFT_1_28::DisplayTFT_1_28() : _tft_espi()
{
    _tft_espi.init();
    _tft_espi.setRotation(0);
}
void DisplayTFT_1_28::DrawProgressCircle(unsigned short percent)
{
    // Очищаем область
    //_tft_espi.fillCircle(CENTER_X, CENTER_Y, RADIUS + 5, COLOR_BG);
    
    // Рисуем фоновую дорожку (полная окружность)
    _tft_espi.drawCircle(CENTER_X, CENTER_Y, RADIUS, COLOR_TRACK);
    _tft_espi.drawCircle(CENTER_X, CENTER_Y, RADIUS - 1, COLOR_TRACK);
    _tft_espi.drawCircle(CENTER_X, CENTER_Y, RADIUS - 2, COLOR_TRACK);
    
    // Рисуем прогресс
    drawArc(percent, COLOR_PROGRESS, COLOR_PROGRESS_BG);
}

void DisplayTFT_1_28::drawAngleLine(int angle, uint16_t color)
{
    // Конвертируем угол в радианы (смещаем на -90° чтобы начиналось сверху)
    float rad = (angle - 90) * 3.14159 / 180.0;
    
    // Внутренний и внешний радиус для толстой линии
    int innerRadius = RADIUS - 8;
    int outerRadius = RADIUS - 2;
    
    // Вычисляем координаты
    int x1 = CENTER_X + innerRadius * cos(rad);
    int y1 = CENTER_Y + innerRadius * sin(rad);
    int x2 = CENTER_X + outerRadius * cos(rad);
    int y2 = CENTER_Y + outerRadius * sin(rad);
    
    // Рисуем линию
    _tft_espi.drawLine(x1, y1, x2, y2, color);
    _tft_espi.drawLine(x1, y1, x2, y2, color);  // Двойная для толщины
}
void DisplayTFT_1_28::drawArc(unsigned short percent, uint16_t colorActive, uint16_t colorInactive)
{
    if (percent > 100) percent = 100;
    
    // Угол прогресса (0° = сверху, по часовой стрелке)
    float endAngle = 360.0 * percent / 100.0;
    
    // Рисуем арку от 0° до endAngle
    for (int angle = 0; angle < 360; angle += 1) {  // Шаг 2° для скорости
        bool isActive = angle <= endAngle;
        uint16_t color = isActive ? colorActive : colorInactive;
        
        if (isActive || angle % 10 == 0) {  // Для фона рисуем реже
            drawAngleLine(angle, color);
        }
    }
}

void DisplayTFT_1_28::Refresh()
{
    _tft_espi.fillScreen(TFT_BLACK);
    _tft_espi.setTextColor(TFT_WHITE, TFT_BLACK);
    _tft_espi.setTextSize(1);
    
    if (_NewData.SheetNumber == 1)
    {
        for (int i = 0; i<4; ++i)
        {
            String min = _NewData.MinLog[i] == DisplayConstants::TEMP_NOT_SET?" --- ":String(_NewData.MinLog[i]) ;
            _tft_espi.drawString(min, 45, 48+(38*i) , 4);
            String max = _NewData.MaxLog[i] == DisplayConstants::TEMP_NOT_SET?" --- ":String(_NewData.MaxLog[i]) ;
            _tft_espi.drawString(max, 130, 48+(38*i) , 4);
        }
        // _tft_espi.drawString(String(_NewData.MinLog[0]), 45, 40, 4);
        // _tft_espi.drawString(String(_NewData.MinLog[0]), 130, 40, 4);
        // _tft_espi.drawString(String(_NewData.MinLog[1]), 45, 90, 4);
        // _tft_espi.drawString(String(_NewData.MinLog[1]), 130, 90, 4);
        // _tft_espi.drawString(String(_NewData.MinLog[2]), 45, 140, 4);
        // _tft_espi.drawString(String(_NewData.MinLog[2]), 130, 140, 4);
    } 
    else
    {
        _tft_espi.drawString(String(_NewData.MaxTemperature), 90, 40, 4);
        _tft_espi.drawString(String(_NewData.CurrentTemperature), 50, 90, 7);
        _tft_espi.drawString(String(_NewData.MinTemperature), 90, 170, 4);
    } 
    
    DrawProgressCircle(_NewData.ElapsedDayPercent);
    return;
}
