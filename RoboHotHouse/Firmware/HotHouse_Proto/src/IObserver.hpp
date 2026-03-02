#pragma once

template<typename T>
class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void update(T* data = nullptr) = 0;
};

template<typename T>
class ISubject {
public:
    static const uint8_t MAX_OBSERVERS = 5;
    
    virtual ~ISubject() {}
    
    virtual bool attach(IObserver<T>* observer) = 0;
    virtual bool detach(IObserver<T>* observer) = 0;
    virtual void notify(T* data = nullptr) = 0;
};