#include <iostream>

#include "ActiveTripIterator.h"
#include "CompletedState.h"
#include "CompleteHierarchyIterator.h"
#include "DriverAssignedState.h"
#include "InTransitState.h"
#include "OperationIterator.h"
#include "PriorityTripFeature.h"
#include "Region.h"
#include "RequestedState.h"
#include "Trip.h"
#include "TripFeature.h"
#include "TripState.h"
#include "UberBlackFeature.h"
#include "UberOperation.h"

int main()
{

    // Setting up all the locations
    Region *Gauteng = new Region("Gauteng");
    Region *Pretoria = new Region("Pretoria");
    Region *Hatfield = new Region("Hatfield");
    Region *UP_Campus = new Region("UP_Campus");
    Region *Brooklyn = new Region("Brooklyn");
    Region *Johannesburg = new Region("Johannesburg");

    Gauteng->setDescription("Gauteng province");
    Pretoria->setDescription("City of Pretoria");
    Johannesburg->setDescription("City of Johannesburg");
    Hatfield->setDescription("Suburb in Pretoria");
    Brooklyn->setDescription("Suburb in Preoria");
    UP_Campus->setDescription("Main Campus of UP");

    Hatfield->add(UP_Campus);
    Pretoria->add(Hatfield);
    Pretoria->add(Brooklyn);
    Gauteng->add(Pretoria);
    Gauteng->add(Johannesburg);

    // setting up all the trips

    UberOperation *Sudud = new Trip();
    UberOperation *Motheo = new Trip();
    UberOperation *Tshego = new Trip();

    Tshego->setCost(30.0);
    Sudud->setCost(60.0);
    Motheo->setCost(90.0);

    UberOperation *UBMotheo = new UberBlackFeature(Motheo);
    UberOperation *PSudud = new PriorityTripFeature(Sudud);

    UP_Campus->add(UBMotheo);
    Brooklyn->add(PSudud);
    Hatfield->add(Tshego);

    Tshego->add(Motheo);
    Tshego->remove(Motheo);

    // CompleteHierarchyIterator Traversal
    OperationIterator *allIt = Gauteng->createIterator();
    for (allIt->first(); !allIt->isDone(); allIt->next())
    {
        UberOperation *op = allIt->currentItem();
        if (op)
        {
            std::cout << op->getDescription() << " | Cost: " << op->getCost() << std::endl;
        }
    }
    delete allIt;

    Trip *tripTshego = dynamic_cast<Trip *>(Tshego);
    Trip *tripSudud = dynamic_cast<Trip *>(Sudud);
    Trip *tripMotheo = dynamic_cast<Trip *>(Motheo);

    tripMotheo->rideStatus();
    tripMotheo->startRide();
    tripMotheo->endRide();
    tripMotheo->assignDriver("Alice");

    Trip *dummyTrip = new Trip();
    RequestedState *rs = new RequestedState();
    rs->setContext(dummyTrip);
    rs->cancelRide();
    rs->assignDriver("Alice");
    rs->getDriver();
    delete rs;

    tripMotheo->changeState(new DriverAssignedState());
    tripMotheo->assignDriver("Alice");
    tripMotheo->rideStatus();
    tripMotheo->endRide();

    DriverAssignedState *das = new DriverAssignedState();
    das->assignDriver("AliceTest");
    das->getDriver();
    delete das;

    tripMotheo->startRide();

    tripMotheo->rideStatus();
    tripMotheo->assignDriver("Bob");
    tripMotheo->startRide();

    // ActiveTripIterator traversal
    ActiveTripIterator activeTripIt(Gauteng);
    for (activeTripIt.first(); !activeTripIt.isDone(); activeTripIt.next())
    {
        UberOperation *op = activeTripIt.currentItem();
        if (op)
        {
            std::cout << op->getDescription() << " | Cost: " << op->getCost() << std::endl;
        }
    }
    activeTripIt.currentItem();

    InTransitState *its = new InTransitState();
    its->getDriver();
    delete its;

    tripMotheo->endRide();

    tripMotheo->rideStatus();
    tripMotheo->assignDriver("Charlie");
    tripMotheo->startRide();
    tripMotheo->endRide();

    CompletedState *cs_cancel = new CompletedState();
    cs_cancel->cancelRide();
    delete cs_cancel;

    CompletedState *cs = new CompletedState();
    cs->getDriver();
    delete cs;

    DriverAssignedState *das_cancel = new DriverAssignedState();
    das_cancel->setContext(tripSudud);
    das_cancel->assignDriver("Dave");
    das_cancel->cancelRide();
    delete das_cancel;

    InTransitState *its_cancel = new InTransitState();
    its_cancel->setContext(tripTshego);
    its_cancel->assignDriver("Eve");
    its_cancel->cancelRide();
    delete its_cancel;

    ActiveTripIterator nullIt(nullptr);
    nullIt.first();
    nullIt.next();

    Gauteng->remove(Pretoria);
    delete Pretoria;

    delete dummyTrip;
    delete Gauteng;

    return 0;
}