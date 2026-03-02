#include "CDisplayManager.h"

bool CDisplayManager::Setup()
{
  //tft.initDMA();
  //Serial.println("init successfuly");
  _TFT->setRotation(2);
  _TFT->fillScreen(TFT_BROWN);
  _TFT->setTextColor(TFT_WHITE, TFT_BROWN);
  _TFT->setTextSize(2);
  _TFT->drawString("Init", 40, 100, 2);
  return true;
}

CDisplayManager::CDisplayManager(IEnvironment *aEnv, TFT_eSPI *aTFT)
{
    _Env = aEnv;
    _TFT = aTFT;
    _TFT->init();
}

void CDisplayManager::Draw(DisplayData aData)
{
    DisplayData* data = &aData;
    /* Холодные цвета */
    // --- Базовый цвет фона (верхняя и нижняя части) ---
    uint16_t bgColor = _TFT->color565(30, 60, 100);   // был (0,30,70) -> светлее

    // --- Цвета для средней зоны ---
    uint16_t leftBg = _TFT->color565(40, 70, 115);    // левая (OUT), чуть светлее базового
    uint16_t rightBg = _TFT->color565(30, 50, 85);    // правая (IN), чуть темнее базового

    // Остальные цвета оставляем без изменений (можно тоже при желании осветлить, но не обязательно)
    uint16_t humColor = _TFT->color565(0, 255, 255);  // яркий голубой (циан)
    uint16_t tempColor = TFT_WHITE;                    // белый
    uint16_t heaterOnColor = _TFT->color565(0, 200, 0); // зелёный
    uint16_t heaterOffColor = _TFT->color565(80, 80, 80); // тёмно-серый
    uint16_t lineColor = _TFT->color565(70, 110, 150);   // линию тоже чуть осветлим для гармонии
    
   /* Зеленые цвета
    // --- Базовый цвет фона (верхняя и нижняя части) ---
    uint16_t bgColor = _TFT->color565(40, 80, 20);       // тёплый тёмно-зелёный (оливковый)

    // --- Цвета для средней зоны ---
    uint16_t leftBg = _TFT->color565(60, 110, 30);       // левая (OUT), светлее базового
    uint16_t rightBg = _TFT->color565(30, 60, 15);       // правая (IN), темнее базового

    // --- Остальные элементы в тёплой гамме ---
    uint16_t humColor = _TFT->color565(180, 220, 100);   // салатовый (для влажности)
    uint16_t tempColor = TFT_WHITE;                       // белый (для текста температур)
    uint16_t heaterOnColor = _TFT->color565(100, 200, 50); // тёплый зелёный (ON)
    uint16_t heaterOffColor = _TFT->color565(100, 100, 80); // серо-бежевый (OFF)
    uint16_t lineColor = _TFT->color565(80, 100, 60);     // приглушённый серо-зелёный (линии)
    */
    _TFT->fillScreen(bgColor);

    // --- Границы разделительных линий ---
    int yTopLine = 55;
    int yBottomLine = 175;
    int xCenter = 120;

    // --- Заливка фона средней зоны ---
    _TFT->fillRect(0, yTopLine, xCenter, yBottomLine - yTopLine, leftBg);   // левая (OUT)
    _TFT->fillRect(xCenter, yTopLine, 240 - xCenter, yBottomLine - yTopLine, rightBg); // правая (IN)

    // --- Рисуем линии поверх заливки ---
    _TFT->drawLine(0, yTopLine, 240, yTopLine, lineColor);
    _TFT->drawLine(0, yBottomLine, 240, yBottomLine, lineColor);
    _TFT->drawLine(xCenter, yTopLine, xCenter, yBottomLine, lineColor);

    // --- Верхняя строка: капля и влажность ---
    uint8_t dropX = 100, dropY = 40;
    uint8_t r1 = 7, r2 = 5, r3 = 3;

    _TFT->fillCircle(dropX, dropY, r1, humColor);
    _TFT->fillCircle(dropX, dropY - 6, r2, humColor);
    _TFT->fillCircle(dropX, dropY - 12, r3, humColor);

    int16_t topY = dropY - 12 - r3;
    int16_t bottomY = dropY + r1;
    _TFT->drawLine(dropX + r1, topY, dropX - r1, bottomY, TFT_WHITE);

    _TFT->setTextColor(humColor, bgColor);
    _TFT->drawString(String(data->Haht) + "%", 120, 30, 1);

    // --- Центр: температуры OUT (слева) и IN (справа) ---
    float tin = float(data->Tds) / 100.0;
    float tout = float(data->Taht) / 100.0;

    _TFT->setTextColor(tempColor, leftBg);
    _TFT->drawString("OUT", 45, 60, 2);
    _TFT->setTextColor(tempColor, rightBg);
    _TFT->drawString("IN", 160, 60, 2);

    String strOut = String(tout, 1);
    String strIn  = String(tin, 1);

    _TFT->setTextColor(tempColor, leftBg);
    _TFT->drawString(strOut, 15, 105, 4);
    _TFT->setTextColor(tempColor, rightBg);
    _TFT->drawString(strIn, 130, 105, 4);

    // --- Нижняя строка: статус подогрева ---
    _TFT->setTextColor(humColor, bgColor);
    _TFT->drawString("Heater:", 60, 190, 1);
    if (data->HeartStatus)
    {
        _TFT->setTextColor(heaterOnColor, bgColor);
        _TFT->drawString("ON", 150, 190, 1);
    }
    else
    {
        _TFT->setTextColor(heaterOffColor, bgColor);
        _TFT->drawString("OFF", 150, 190, 1);
    }
}
