#pragma once
#include "IObserver.hpp"


template<typename T = void>
class CSubjectArray: public ISubject<T>
{
    private:
    IObserver<T>* observers_[ISubject<T>::MAX_OBSERVERS];
    uint8_t _count = 0;

    public:
    bool attach(IObserver<T>* observer) override {
        if (!observer || _count >= ISubject<T>::MAX_OBSERVERS) {
            return false;
        }
        
        // Проверка на дубликат
        for (uint8_t i = 0; i < _count; ++i) {
            if (observers_[i] == observer) {
                return false;
            }
        }
        
        observers_[_count++] = observer;
        return true;    
    };

    bool detach(IObserver<T>* observer) override {
        for (uint8_t i = 0; i < _count; ++i) {
            if (observers_[i] == observer) {
                // Сдвигаем остальных
                for (uint8_t j = i; j < _count - 1; ++j) {
                    observers_[j] = observers_[j + 1];
                }
                observers_[--_count] = nullptr;
                return true;
            }
        }
        return false;
    }
    
    void notify(T* data = nullptr) override {
        for (uint8_t i = 0; i < _count; ++i) {
            if (observers_[i]) {
                observers_[i]->update(data);
            }
        }
    }
   
};