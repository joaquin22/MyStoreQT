#ifndef STORE_H
#define STORE_H


#include "Product.h"
#include "json.hpp"

using json = nlohmann::json;



class Store
{

public:
    Store(const Store&) = delete;
    Store& operator=(const Store&) = delete;

    static Store* getInstance();

    void saveJson(const Product & product, const std::string& fileName);
    json readJson(const std::string& fileName);


private:
    inline static Store* instance{nullptr};
    Store() = default;
    ~Store() = default;
};

#endif // STORE_H
