// Tool.h
#ifndef OOPAD_2026_TOOL_H
#define OOPAD_2026_TOOL_H

#include "Product.h"

class Tool : public Product {
    std::string brand_;
public:
    Tool() : Product(), brand_("") {}
    Tool(int, const std::string &, double, int, const std::string &);
    ~Tool() override;

    const std::string& getBrand() const;

    std::string getCategory() const override;
    void print() const override;
};


#endif //OOPAD_2026_TOOL_H