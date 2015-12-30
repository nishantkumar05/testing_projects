//
//  NSObject+CarCateogory.m
//  TestingObjectiveC

#import "Car+CarCateogory.h"

@implementation Car (CarCateogory)

- (NSString *) cc_origin //: (NSString *) make
{
    NSString * origin = [NSString stringWithCString:"Unknown" encoding:1];
    if( NSOrderedSame == [self.Make compare:@"nissan"]) {
        origin = @"Japan";
    } else if ( NSOrderedSame == [self.Make compare:@"Lamborghini"]) {
        origin = @"Germany";
    }
    return origin;
}

@end
