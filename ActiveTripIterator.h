#ifndef ACTIVETRIPITERATOR_H
#define ACTIVETRIPITERATOR_H

#include "OperationIterator.h"
#include <vector>

class ActiveTripIterator : public OperationIterator
{
private:
    std::vector<UberOperation *> allNodes;
    int pos;
    UberOperation *root;

public:
    ActiveTripIterator(UberOperation *root);
    void first() override;
    void next() override;
    bool isDone() override;
    UberOperation *currentItem() override;
};

#endif // ACTIVETRIPITERATOR_H
