//
//  test.m
//  TestingObjectiveC
//

#import "car.h"

@interface Car ()
@property (readwrite) NSString * Make;
@end

@implementation Car

//@synthesize model;
//@synthesize Make;

- (NSInteger) mileage:(NSInteger)year modelType:(NSInteger)modelType
{
    NSLog(@"mileage() API");
    NSInteger _mileage = 0;
    
    switch (year) {
        case 2000:
            NSLog(@"case 2000");
            switch (modelType) {
                case 1: //diesel
                    _mileage = 40; //mpg
                    break;
                default:
                    break;
            }
            break;
            
        default:
            NSLog(@"default");
            break;
    }
    return _mileage;
}

- (BOOL) isHybrid
{
    return YES;
}

- (void) setMyMake : (NSString *) myMake
{
    self.Make = myMake;
}

- (id) init : (NSString*)new
{
    self = [super init];
    if(!self)
        return self;
    
    self.model = new;
    return self;
}

//factory method: method that can be called on an class (not on object)
+ (Car *) newCar
{
    Car *t = [Car alloc];
    return t;
}


- (int) myBlockAddition: (mySimpleBlockType) block
{
    int add = 1;
    return (add + block(4,4));
}

@end


@implementation SuperCar

- (NSInteger) mileage:(NSInteger)year modelType:(NSInteger)modelType
{
    NSLog(@"HAHAHAHAHAHAHA!!!!!");
    return 5;
}

@end