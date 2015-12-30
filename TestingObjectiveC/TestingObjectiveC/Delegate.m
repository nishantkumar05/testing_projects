//
//  Delegate2.m
//  TestingObjectiveC
//

#import <Foundation/Foundation.h>
#import "Delegate.h"



@implementation Dad

-(void) WorkStarted:(NSString *)myTask
{
    NSLog(@"baby: kid says he started to work on '%@'",myTask);
}

- (void) WorkFinished:(NSString *)myTask
{
    NSLog(@"baby: the house is finished '%@'",myTask);
}

-(void) WifeWantHouse:(NSString *)myTask FromChild:(Child *)kid
{
    NSLog(@"Baby: you requested house named '%@' from our kid '%@'",myTask, kid.name);

    [kid SetDelegate:self];
    
    NSLog(@"baby asking kid to start work on our house project");
    [kid StartHouseProject:myTask];
}

@end



@implementation Child

@synthesize name;
@synthesize task;

-(id) initWithName:(NSString *)kidName
{
    self = [super init];
    if (self) {
        name = kidName;
    }
    return self;
}


-(void) SetDelegate:(id<DadProtocol>)myDad
{
    dad = myDad;
}

-(void) StartHouseProject:(NSString *)myTask
{
    task = myTask;
    NSLog(@"Starting house project: %@",task);
    [dad WorkStarted:task];
    NSLog(@"Working on house project 5 secss");
    [dad WorkFinished:task];
}

@end