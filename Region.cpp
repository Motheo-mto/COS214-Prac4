#include "Region.h"
#include "CompleteHierarchyIterator.h"

double Region::getCost()
{
    double total = 0;
    for (auto *op : operations)
    {
        total += op->getCost();
    }
    return total;
}

std::string Region::getDescription()
{
    std::string desc = "Region (";
    bool first = true;
    for (auto *op : operations)
    {
        if (!first)
            desc += ", ";
        desc += op->getDescription();
        first = false;
    }
    desc += ")";
    return desc;
}

OperationIterator *Region::createIterator()
{
    return new CompleteHierarchyIterator(this);
}

void Region::add(UberOperation *a)
{
    operations.push_back(a);
}

void Region::remove(UberOperation *r)
{
    operations.remove(r);
}

Region::~Region()
{
    for (auto *op : operations)
    {
        delete op;
    }
    operations.clear();
}
