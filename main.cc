#include <drogon/drogon.h>

int main() {
    // 设置 HTTP 监听地址和端口
    drogon::app().addListener("0.0.0.0", 5555);

    // 注册根路径 handler
    drogon::app().registerHandler("/",
        [](const drogon::HttpRequestPtr &req,
           std::function<void (const drogon::HttpResponsePtr &)> &&callback) {
            auto resp = drogon::HttpResponse::newHttpResponse();
            resp->setBody("Hello World");
            callback(resp);
        });

    // 运行框架
    drogon::app().run();
    return 0;
}

