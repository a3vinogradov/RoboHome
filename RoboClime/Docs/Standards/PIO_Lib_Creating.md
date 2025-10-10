# Руководство по созданию библиотек в PlatformIO

## 🎯 **Основные принципы**

### 1. **Структура библиотеки**
```
MyLibrary/
├── library.json          # Обязательно!
├── MyLibrary.h           # Главный заголовок
├── src/                  # Исходные файлы
│   ├── Class1.h
│   ├── Class2.cpp
│   └── ...
└── examples/             # Примеры использования
    └── BasicExample/
        └── BasicExample.ino
```

### 2. **Критически важные моменты**
- **library.json** - должен быть в корне библиотеки
- **MyLibrary.h** - главный заголовок должен быть в корне
- **Платформа** - указывайте поддерживаемые платформы

## 📝 **Пошаговое создание библиотеки**

### Шаг 1: Создаем структуру папок
```bash
# В папке lib/ вашего проекта
mkdir MyLibrary
cd MyLibrary
mkdir src examples
```

### Шаг 2: Создаем library.json
```json
{
    "name": "MyLibrary",
    "version": "1.0.0",
    "description": "Описание вашей библиотеки",
    "keywords": "keyword1, keyword2",
    "authors": [
        {
            "name": "Ваше имя",
            "email": "email@example.com"
        }
    ],
    "frameworks": "arduino",
    "platforms": "espressif8266, espressif32",
    "build": {
        "includeDir": ".",
        "srcDir": "src"
    }
}
```

**Ключевые параметры:**
- `"includeDir": "."` - указывает, где искать заголовочные файлы
- `"srcDir": "src"` - указывает, где исходные файлы

### Шаг 3: Создаем главный заголовок (MyLibrary.h)
```cpp
#pragma once

// Главный заголовок библиотеки
#include "src/MyClass.h"
#include "src/MyConfig.h"

namespace MyLibrary {
    // Объявления или using-директивы
}
```

### Шаг 4: Создаем исходные файлы в src/
**src/MyClass.h:**
```cpp
#pragma once
#include <Arduino.h>

namespace MyLibrary {
    class MyClass {
    public:
        void begin();
        void update();
    private:
        // поля класса
    };
}
```

**src/MyClass.cpp:**
```cpp
#include "MyClass.h"

namespace MyLibrary {
    void MyClass::begin() {
        // инициализация
    }
    
    void MyClass::update() {
        // основная логика
    }
}
```

### Шаг 5: Создаем пример использования
**examples/BasicExample/BasicExample.ino:**
```cpp
#include <MyLibrary.h>

MyLibrary::MyClass myObject;

void setup() {
    Serial.begin(115200);
    myObject.begin();
}

void loop() {
    myObject.update();
    delay(100);
}
```

## ⚙️ **Конфигурация platformio.ini**
```ini
[env:nodemcuv2]
platform = espressif8266
board = nodemcuv2
framework = arduino

; Библиотека автоматически подхватится из lib/
; Явное указание не требуется, но можно добавить:
lib_deps = 
    MyLibrary
```

## 🔧 **Работа с зависимостями**

### Зависимость от другой библиотеки
**library.json:**
```json
{
    "name": "MyLibrary",
    "version": "1.0.0",
    "dependencies": {
        "SomeOtherLibrary": "*"
    },
    "build": {
        "includeDir": ".",
        "srcDir": "src"
    }
}
```

### Вложенные зависимости
Если ваша библиотека зависит от другой вашей же библиотеки:
```json
{
    "dependencies": {
        "EventLib": "*",
        "ButtonLib": "*"
    }
}
```

## 🐛 **Диагностика проблем**

### 1. Библиотека не находится
**Симптом:** `fatal error: MyLibrary.h: No such file or directory`

**Решение:**
- Проверьте наличие `library.json`
- Убедитесь, что `MyLibrary.h` в корне библиотеки
- Добавьте в `platformio.ini`:
  ```ini
  lib_extra_dirs = lib/MyLibrary
  build_flags = -Ilib/MyLibrary
  ```

### 2. Файлы внутри библиотеки не находятся
**Симптом:** Ошибки компиляции файлов внутри src/

**Решение:**
- В `MyLibrary.h` используйте правильные пути:
  ```cpp
  #include "src/MyClass.h"    // если файлы в src/
  #include "MyClass.h"        // если файлы в корне
  ```

### 3. Проверка видимости библиотеки
```bash
# Убедитесь, что PlatformIO видит библиотеку
pio lib list

# Принудительно обновить кэш библиотек
pio pkg update
```

## 🚀 **Продвинутые настройки**

### Многофайловая библиотека
```
MyLibrary/
├── library.json
├── MyLibrary.h
├── src/
│   ├── Core/
│   │   ├── Core.h
│   │   └── Core.cpp
│   ├── Network/
│   │   ├── Network.h
│   │   └── Network.cpp
│   └── Sensors/
│       ├── Sensor.h
│       └── Sensor.cpp
└── examples/
    ├── BasicExample/
    └── AdvancedExample/
```

**MyLibrary.h:**
```cpp
#pragma once

// Подключаем все компоненты
#include "src/Core/Core.h"
#include "src/Network/Network.h"
#include "src/Sensors/Sensor.h"

namespace MyLibrary {
    // Объединяем все пространства имен
    using namespace Core;
    using namespace Network;
    using namespace Sensors;
}
```

## 💡 **Лучшие практики**

1. **Именование** - используйте осмысленные имена, избегайте пробелов
2. **Версионирование** - следуйте семантическому версионированию (1.0.0, 1.0.1, etc.)
3. **Документация** - добавляйте комментарии и примеры
4. **Тестирование** - создавайте примеры в папке examples/
5. **Совместимость** - явно указывайте поддерживаемые платформы

## 📋 **Чеклист создания библиотеки**

- [ ] Создана папка библиотеки в `lib/`
- [ ] Добавлен `library.json` с правильными путями
- [ ] Создан главный заголовок `MyLibrary.h`
- [ ] Исходные файлы размещены в `src/`
- [ ] Добавлены примеры в `examples/`
- [ ] Протестирована компиляция
- [ ] Указаны зависимости (если есть)

Теперь вы можете создавать хорошо структурированные библиотеки в PlatformIO! 🎉