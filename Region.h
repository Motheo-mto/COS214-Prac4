#ifndef REGION_H
#define REGION_H

#include "UberOperation.h"
#include <list>
#include <string>

class Region : public UberOperation
{
    friend class CompleteHierarchyIterator;

private:
    std::string name;
    std::string description;
    std::list<UberOperation *> operations;

public:
    Region(const std::string &name);
    void setCost(double cost) override;
    double getCost() override;
    std::string setDescription(std::string desc);
    std::string getDescription() override;
    OperationIterator *createIterator() override;
    void add(UberOperation *a) override;
    void remove(UberOperation *r) override;
    ~Region() override;
};

#endif // REGION_H
