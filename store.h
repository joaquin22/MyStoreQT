#ifndef STORE_H
#define STORE_H


#include "Product.h"
#include "json.hpp"

using json = nlohmann::json;



class Store
{

public:
    Store();
    void saveJson(const Product & product, const std::string& fileName);

private:
    std::string name;
    std::string stock;
    std::string price;
};

#endif // STORE_H
