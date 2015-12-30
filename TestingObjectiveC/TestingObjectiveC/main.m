
//
//  main.m
//  TestingObjectiveC
//

#import "car.h"
#import "Car+CarCateogory.h"
#import "Delegate.h"

int main(int argc, const char * argv[])
{
    //==============================================================
    //Delegate
    //==============================================================
    Child *sunny = [[Child alloc] initWithName:@"sunny"];
    Dad *Tom = [Dad new];
    NSString *task = @"TomsResidence";
    
    [Tom dealloc];
//    Tom = nil;
    
    [Tom WifeWantHouse:task FromChild:sunny];
    
//    [Tom release];
    [sunny release];
    exit(0);
    
    //==============================================================
    int idleConfig = 2 * 24 * 60 * 60;
    int ttl = (28 * 60 * 60 ) + 122;
    int hours = ttl/(60*60);
    int mins = (ttl%(60*60))/60;
    int sec= ((ttl%(60*60))%60);
    NSLog(@"idl config (s)= %d, time=%d:%d:%d",idleConfig, hours,mins,sec);
//==============================================================================
// calling init twice
    
    NSString *s = [[NSString alloc] init];
    //It will crash at following argument
//    [s initWithString:@"WTF"];
    NSLog(@"initialized twice");
    
//==============================================================================
//  NSURL

    NSURL *url=[NSURL URLWithString:@"https://172.31.54.22/thisispath/thisisSecondPath.php?xml=1"];
    
    NSLog(@"URL=%@ \n scheme=%@ \n host=%@ \n path=%@", url, [url scheme], [url host], [url path]);
    
    NSLog(@"new url=%@",[url URLByDeletingPathExtension]);
    
//==============================================================================
// Values & collections
   NSDictionary *dic = @{@"first" : @1L, @"second": @2.3f, @"third" : @"T"};
    
   // NSLog(@"dic=%@",dic);
    
    //NSArray *arr = @[@"first" , @"second", @"third", @"T"];
    
    //NSLog(@"array=%@",arr);

    NSLog(@"===========");
    [dic enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {
        NSLog(@"%@ : %@",key, obj);
    }];
    NSLog(@"===========");
    
   // [arr writeToFile:@"/tmp/testing" atomically:YES];
    
//==============================================================================
//  Cateogories
    
    Car *myCar = [[Car alloc] init];
    NSMutableString * tmpMake = [[NSMutableString alloc] initWithString:@"randomBrand"];
    NSMutableString * tmpModel = [[NSMutableString alloc] initWithString:@"randomModel"];
    [myCar setMyMake:tmpMake];
    [myCar setModel:tmpModel];

    NSLog(@"My car = %@ %@, has mileage = %ld",[myCar Make],[myCar model],
          [myCar mileage:2000 modelType:1]);
    NSLog(@"country of origin of (%@ %@) is %@", [myCar Make], [myCar model], [myCar cc_origin]);
    
    [tmpMake appendString:@"ly"];
    [tmpModel release];
    NSLog(@"Updated ---- My car = %@ %@, has mileage = %ld", [myCar Make],
          [myCar model], [myCar mileage:2000 modelType:1]);
    
    Car *superCar = [[SuperCar alloc] init];
    
    [superCar setMyMake:@"Lamborghini"];
    [superCar setModel:@"phantom"];
    
    NSLog(@"Somebody else super car = %@ %@, has mileage = %ld",
          [superCar Make],[superCar model],
          [superCar mileage:2000 modelType:1]);
    
    
    NSLog(@"country of origin of (%@) is %@", [superCar Make], [superCar cc_origin]);

    
//==============================================================================
//  Block
    
    __block int  d = 10;
    mySimpleBlockType msb = ^(int a, int b){
        NSLog(@"I AM INSIDE THE BLOCK");
        return a * b * d;
    };
    NSLog(@"value from simple block=%i",[myCar myBlockAddition:msb]);
    d = 20 ;
    NSLog(@"value from simple block=%i",[myCar myBlockAddition:msb]);
   // NSLog(@"value from simple block=%i",msb(3,5));;
    
    
    
    return 0;
}
