//
//  test.h
//  TestingObjectiveC

#import <Foundation/Foundation.h>


typedef int(^mySimpleBlockType)(int,int);



@interface Car : NSObject {
    NSString * _finish;
}

@property (readonly, copy) NSString * Make;
@property (assign) NSString * model;
@property (readonly, getter = isHybrid ) BOOL hybrid;

- (id) init : (NSString*)new;

- (void) setMyMake : (NSString *) myMake;

- (NSInteger) mileage:(NSInteger)year modelType:(NSInteger)modelType;

- (int) myBlockAddition: (mySimpleBlockType) block;

+ (Car *) newCar;

@end

@interface SuperCar : Car
- (NSInteger) mileage:(NSInteger)year modelType:(NSInteger)modelType;
@end



//Objective-C objects ( Memory management )
// Allocation: always dynmaically allocated via: alloc, assign other object
// deallocation: automatically, whenever reference count goes to zero
//
// In general allocation is just like pointers and modification of object follows pointers arithmetic too.
//  but de-allocation is different, its automatic and depeneds upon reference count.
//  And reference count in turn can be changed by:
//      -> _weak or _strong reference
//      -> copy property



//Instance variable
// - properties instance variable is of the same name. Strong reference unless property is weak
// - synthesized automatically for property
// - is private by default if synthesized
// - (Inheritence) Derived class cannot use synthesized instance variable because its private
// - (Inheritence) Cateogory is "type-of-derived-class", hence private variables cannot be used in it. Can only use public methods of base class


//Setters an Getters
// - always prefer these. Except in initializer because setter creates some KVO notification unecessary when object is not initialized properly
// - are public methods hence cateogory can/must use them


//Class Extension(Anonymous cateogory): Used when:
// - Need to define private methods to the class only accessible within same translation unit for ease, so that you dont have to define them as a function for this translation unit.
// - Need to change attribute of existing property (NOT the type) altogether though
// Class cateogory: Used when:
// - You DONT HAVE THE SOURCE CODE and want to extend the behavior of that class.
// - should be used when whole project needs the extended interface and that interface
//      doesnt change depending on situation (runtime or static).
// *Class cateogory extends a class by adding more public methods, and "Class extensions"
//   extends the class by adding more private methods
// * Cateogory is "type-of-dereived-class" hence the private variables cannot be used in it.
