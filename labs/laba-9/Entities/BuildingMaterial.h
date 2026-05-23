// BuildingMaterial.h
#ifndef OOPAD_2026_BUILDINGMATERIAL_H
#define OOPAD_2026_BUILDINGMATERIAL_H

#include "Product.h"

class BuildingMaterial : public Product {
    std::string unit_;
public:
    BuildingMaterial() : Product(), unit_("") {}
    BuildingMaterial(int id, const std::string &, double,
                     int, const std::string  &);
    ~BuildingMaterial() override;

    const std::string& getUnit() const;

    std::string getCategory() const override;
    void print() const override;

};


#endif //OOPAD_2026_BUILDINGMATERIAL_H