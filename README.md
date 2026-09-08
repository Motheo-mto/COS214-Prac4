# COS214-Prac4

#### Patterns

- **Composite Pattern:**
	- **Component:** `UberOperation:`- Defines the interface for all operations, including cost calculations and status checks.
	- **Composite:** `Region`- Contains a collection of `UberOperation` pointers (which can be smaller regions or individual trips)
	- **Leaf:** `Trip` - The individual work item representing a single passenger ride.

- **State Pattern**
	- **Context:** `Trip` - Maintains a pointer to its current state.
	- **State:** `TripState` - The abstract base class defining valid state transitions (e.g., `assignDriver()`, `startRide()`).
	- **ConcreteState:** `RequestedState`, `InTransitState`, `CompletedState`, `CancelledState`.

- **Decorator Pattern**
	- **Component:** `UberOperations`
	- **Concrete Component:** `Trip`
	- **Decorator:** `TripFeature` - Holds a pointer to an `UberOperation`.
	- **ConcreteDecorators:** `UberBlackFeature`, `PriorityTripFeature`. The modify the cost and description dynamically and can be stacked.

- **Iterator Pattern**
	- **Aggregate:** `Region`.
	- **Iterator:** `OperationIterator` - Abstract base class for traversal
	- **ConcreteIterator:** 
		- `CompleteHierarchyIterator`: Visits every nested region and trip.
		- `ActiveTripIterator`: Filters the traversal to only return `Trip` objects that are currently in the `InTransitState`.
