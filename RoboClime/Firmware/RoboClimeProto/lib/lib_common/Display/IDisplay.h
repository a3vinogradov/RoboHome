#pragma once

#define LOG_LENGTH 5

namespace DisplayConstants {
    const float TEMP_NOT_SET = -273.17f;  // "Холоднее абсолютного нуля! ❄️"
}

struct DisplayData {
    DisplayData() { // Конструктор
        for (int i=0; i<LOG_LENGTH ; ++i)
        {
            MinLog[i] = DisplayConstants::TEMP_NOT_SET;
            MaxLog[i] = DisplayConstants::TEMP_NOT_SET;
        }
    };
    unsigned short int SheetNumber = 0;
    unsigned short int ElapsedDayPercent = 0;
    float CurrentTemperature = DisplayConstants::TEMP_NOT_SET;
    float MinTemperature = DisplayConstants::TEMP_NOT_SET;
    float MaxTemperature = DisplayConstants::TEMP_NOT_SET;
    float MinLog[LOG_LENGTH] = {DisplayConstants::TEMP_NOT_SET};
    float MaxLog[LOG_LENGTH] = {DisplayConstants::TEMP_NOT_SET}; 
};

/**
 * @brief Высокоуровневый интерфейс для работы с дисплеем с оптимизацией обновлений
 * 
 * Класс управляет буферизацией данных отображения и минимизирует количество
 * операций записи в дисплей, используя дифференциальное обновление только
 * изменившихся областей.*/

class IDisplay
{
    protected:
    virtual void Refresh() = 0;

    public:
    virtual void UpdateData(DisplayData data) = 0;
    virtual void Draw() = 0;
    virtual void Draw(DisplayData data) = 0;
    virtual void Draw(DisplayData* data) = 0;
    virtual void Draw(unsigned short int elapsedDayPercent) = 0;
    virtual void Draw(unsigned short int sheetNumber, unsigned short int elapsedDayPercent) = 0;
    virtual void Draw(float cur, unsigned short int elapsedDayPercent) = 0;
    virtual void Draw(float cur, float max, float min, unsigned short int elapsedDayPercent) = 0;
};

class CBaseDisplay: public IDisplay
{
protected:
    DisplayData _CurrentData;
    DisplayData _NewData;
    virtual void Refresh() = 0;
    
public:

    virtual void UpdateData(DisplayData data) override;
    void RefreshAndSwitch();
    virtual void Draw();    
    virtual void Draw(DisplayData data) override;
    virtual void Draw(DisplayData* data) override;
    virtual void Draw(unsigned short int elapsedDayPercent) override;
    virtual void Draw(unsigned short int sheetNumber, unsigned short int elapsedDayPercent) override;
    virtual void Draw(float cur, unsigned short int elapsedDayPercent) override;
    virtual void Draw(float cur, float max, float min, unsigned short int elapsedDayPercent) override;
};