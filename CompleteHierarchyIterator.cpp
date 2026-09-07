#include "CompleteHierarchyIterator.h"
#include "Region.h"

CompleteHierarchyIterator::CompleteHierarchyIterator(UberOperation *root) : root(root)
{
}

void CompleteHierarchyIterator::first()
{
    while (!stack.empty())
    {
        stack.pop();
    }
    if (root)
    {
        stack.push(root);
    }
}

void CompleteHierarchyIterator::next()
{
    if (isDone())
        return;
    UberOperation *current = stack.top();
    stack.pop();
    Region *region = dynamic_cast<Region *>(current);
    if (region)
    {
        for (auto it = region->operations.rbegin(); it != region->operations.rend(); ++it)
        {
            stack.push(*it);
        }
    }
}

bool CompleteHierarchyIterator::isDone()
{
    return stack.empty();
}

UberOperation *CompleteHierarchyIterator::currentItem()
{
    if (isDone())
        return nullptr;
    return stack.top();
}
