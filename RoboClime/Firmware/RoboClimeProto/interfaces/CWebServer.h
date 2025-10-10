#include <httplib.h>

namespace esp8266lib{
    
    // Платформонезависимые определения
    
    enum class HttpMethod {
        Get,
        Post,
        Put,
        Delete,
        Patch,
        Options,
        Any
    };

    class CWebServer {
    public:
        virtual ~CWebServer() = default;
        
        // Основные методы
        virtual void start(uint16_t port) = 0;
        virtual void processRequests() = 0;
        
        // Роутинг
        virtual void addRoute(const char* path, HttpMethod method, void (*handler)()) = 0;
        virtual void setNotFoundHandler(void (*handler)()) = 0;
        
        // Управление ответом
        virtual void sendResponse(int statusCode, const char* contentType, const char* content) = 0;
        virtual void addHeader(const char* name, const char* value) = 0;
        
        // Доступ к запросу
        virtual const char* getQueryParam(const char* name) = 0;
        virtual const char* getRequestMethod() = 0;
    };
}