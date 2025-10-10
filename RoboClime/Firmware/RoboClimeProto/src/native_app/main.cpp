#include <httplib.h>
#include "TypeDef.h"
#include "FSManagerNative.h"
#include "common.h"
#include "IMainController.h"

int main() {
    httplib::Server svr;  // Создаём сервер

    // Обработчик для корневого пути "/"
    String content;

    FSManagerNative fsManager;
    if (fsManager.Exists("index.html"))
    {
        content = fsManager.ReadFile("index.html");
    }
    else
    {
        content = "Error 404"; 
    }

    svr.Get("/", [&content](const httplib::Request&, httplib::Response& res) {
        res.set_content(content.c_str(), "text/html");
    });

    // Запуск сервера на порту 8080
    std::cout << "Server started at http://localhost:8080\n";
    svr.listen("localhost", 8080);

    return 0;
}