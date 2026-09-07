#include "ActiveTripIterator.h"
#include "Trip.h"
#include "TripFeature.h"
#include "TripState.h"
#include "CompleteHierarchyIterator.h"

ActiveTripIterator::ActiveTripIterator(UberOperation *root) : root(root), pos(0)
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
    return pos >= allNodes.size();
}

UberOperation *ActiveTripIterator::currentItem()
{
    if (isDone())
        return nullptr;
    return allNodes[pos];
}
