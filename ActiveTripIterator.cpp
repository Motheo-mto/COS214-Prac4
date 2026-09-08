#include "ActiveTripIterator.h"
#include "Trip.h"
#include "TripFeature.h"
#include "TripState.h"
#include "CompleteHierarchyIterator.h"
#include "InTransitState.h"

ActiveTripIterator::ActiveTripIterator(UberOperation *root) : pos(0), root(root)
{
}

void ActiveTripIterator::first()
{
    allNodes.clear();
    pos = 0;
    if (!root)
        return;
    CompleteHierarchyIterator it(root);
    for (it.first(); !it.isDone(); it.next())
    {
        UberOperation *current = it.currentItem();
        // Unpack decorator if present
        TripFeature *feature = dynamic_cast<TripFeature *>(current);
        UberOperation *baseOp = current;
        while (feature)
        {
            baseOp = feature->operation;
            feature = dynamic_cast<TripFeature *>(baseOp);
        }
        Trip *trip = dynamic_cast<Trip *>(baseOp);
        if (trip)
        {
            if (dynamic_cast<InTransitState *>(trip->currentState))
            {
                // If the trip is InTransit, we can push the current
                allNodes.push_back(current);
            }
        }
    }
}

void ActiveTripIterator::next()
{
    if (!isDone())
    {
        pos++;
    }
}

bool ActiveTripIterator::isDone()
{
    return (size_t)pos >= allNodes.size();
}

UberOperation *ActiveTripIterator::currentItem()
{
    if (isDone())
        return nullptr;
    return allNodes[pos];
}
