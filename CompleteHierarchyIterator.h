#ifndef COMPLETEHIERARCHYITERATOR_H
#define COMPLETEHIERARCHYITERATOR_H

#include "OperationIterator.h"
#include <stack>

class CompleteHierarchyIterator : public OperationIterator
{
private:
    std::stack<UberOperation *> stack;
    UberOperation *root;

public:
    CompleteHierarchyIterator(UberOperation *root);
    void first() override;
    void next() override;
    bool isDone() override;
    UberOperation *currentItem() override;
};

#endif // COMPLETEHIERARCHYITERATOR_H
