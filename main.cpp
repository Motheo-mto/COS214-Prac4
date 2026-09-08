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

    std::cout<<std::endl;
    std::cout<<"----- Add/Remove Trip object to another Trip object -----"<<std::endl;
    std::cout<<std::endl;

    Tshego->add(Motheo);
    Tshego->remove(Motheo);
    std::cout<<std::endl;
    // -------------------------------------------------------------

    // CompleteHierarchyIterator Traversal

    std::cout<< "----- Complete Hierarchy Iterator Traversal -----" <<std::endl;
    std::cout<<std::endl;

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

    std::cout<<std::endl;
    // -------------------------------------------------------------

    Trip *tripTshego = dynamic_cast<Trip *>(Tshego);
    Trip *tripSudud = dynamic_cast<Trip *>(Sudud);
    Trip *tripMotheo = dynamic_cast<Trip *>(Motheo);

    // -------------------------------------------------------------

    std::cout<<"----- Motheo Ride Status -----"<<std::endl;
    std::cout<<std::endl;

    tripMotheo->rideStatus();
    tripMotheo->startRide();
    tripMotheo->endRide();
    tripMotheo->assignDriver("Alice");

    std::cout<<std::endl;
    // -------------------------------------------------------------

    std::cout<<"----- Dummy Trip Testing -----"<<std::endl;
    std::cout<<std::endl;

    Trip *dummyTrip = new Trip();
    RequestedState *rs = new RequestedState();
    rs->setContext(dummyTrip);
    rs->cancelRide();
    rs->assignDriver("Alice");
    rs->getDriver();
    delete rs;

    std::cout<<std::endl;

    std::cout<<"----- Motheo Testing -----"<<std::endl;
    std::cout<<std::endl;


    tripMotheo->changeState(new DriverAssignedState());
    tripMotheo->assignDriver("Alice");
    tripMotheo->rideStatus();
    tripMotheo->endRide();
    std::cout<<"--------"<<std::endl;
    DriverAssignedState *das = new DriverAssignedState();
    das->assignDriver("AliceTest");
    das->getDriver();
    delete das;
    std::cout<<"--------"<<std::endl;
    tripMotheo->startRide();

    tripMotheo->rideStatus();
    tripMotheo->assignDriver("Bob");
    tripMotheo->startRide();

    std::cout<<std::endl;

    std::cout<<"----- Active Trip Iterator Traversal -----"<<std::endl;
    std::cout<<std::endl;

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

    std::cout<<std::endl;
    std::cout<<"----- Motheo Completed Ride Testing -----"<<std::endl;
    std::cout<<std::endl;

    tripMotheo->endRide();
    tripMotheo->rideStatus();
    tripMotheo->assignDriver("Charlie");
    tripMotheo->startRide();
    tripMotheo->endRide();
    std::cout<<std::endl;

    std::cout<<"----- Ride cancelling testing -----"<<std::endl;
    std::cout<<std::endl;

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

    std::cout<<std::endl;
    std::cout<<"----- Active Iterator, with no active trips -----"<<std::endl;
    std::cout<<std::endl;

    ActiveTripIterator nullIt(nullptr);
    nullIt.first();
    nullIt.next();

    std::cout<<std::endl;
    std::cout<<"----- Setting up more trips -----"<<std::endl;
    std::cout<<std::endl;

    UberOperation *Belle = new Trip();
    UberOperation *Finn = new Trip();
    UberOperation *David = new Trip();

    Belle->setCost(100.0);
    Finn->setCost(160.0);
    David->setCost(290.0);

    Brooklyn->add(Belle);
    UP_Campus->add(Finn);
    Johannesburg->add(David);

    Trip *tBelle = dynamic_cast<Trip *>(Belle);
    Trip *tFinn = dynamic_cast<Trip *>(Finn);
    Trip *tDavid = dynamic_cast<Trip *>(David);

    tBelle->changeState(new DriverAssignedState());
    tFinn->changeState(new DriverAssignedState());
    tDavid->changeState(new DriverAssignedState());

    DriverAssignedState *das1 = new DriverAssignedState();
    DriverAssignedState *das2 = new DriverAssignedState();
    DriverAssignedState *das3 = new DriverAssignedState();

    tBelle->assignDriver("Bella");
    tFinn->assignDriver("Ferran");
    tDavid->assignDriver("Lucy");

    tBelle->startRide();
    tFinn->startRide();
    tDavid->startRide();

    std::cout<<std::endl;
    std::cout<<"----- Iterators with 3 active rides -------------------------------------------------"<<std::endl;
    std::cout<<std::endl;
    std::cout<<"---Hierarchy"<<std::endl;
    std::cout<<std::endl;

    OperationIterator *HIt = Gauteng->createIterator();
    for (HIt->first(); !HIt->isDone(); HIt->next())
    {
        UberOperation *op = HIt->currentItem();
        if (op)
        {
            std::cout << op->getDescription() << " | Cost: " << op->getCost() << std::endl;
        }
    }
    delete HIt;

    std::cout<<std::endl;
    std::cout<<"---Active Trips"<<std::endl;
    std::cout<<std::endl;
    ActiveTripIterator ATI(Gauteng);
    for (ATI.first(); !ATI.isDone(); ATI.next())
    {
        UberOperation *op = ATI.currentItem();
        if (op)
        {
            std::cout << op->getDescription() << " | Cost: " << op->getCost() << std::endl;
        }
    }
    ATI.currentItem();

    std::cout<<std::endl;
    std::cout<<"----- Iterators End -------------------------------------------------"<<std::endl;
    std::cout<<std::endl;

    std::cout<<"----- Ride Status and Ending active trips -----"<<std::endl;
    std::cout<<std::endl;

    tBelle->rideStatus();
    tFinn->rideStatus();
    tDavid->rideStatus();

    tBelle->endRide();
    tFinn->endRide();
    tDavid->endRide();

    //=========================================

    delete das1;
    delete das2;
    delete das3;
    Gauteng->remove(Pretoria);
    delete Pretoria;
    delete dummyTrip;
    delete Gauteng;

    return 0;
}