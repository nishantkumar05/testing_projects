//
//  myProtocol.h
//  TestingCocoa
//
//  Created by nishant kumar on 7/17/13.
//  Copyright (c) 2013 F5 Networks Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol myProtocol <NSObject>

@property (nonatomic, retain) NSTextField* myDataSourceText;

+ (NSString *) newValue;
@end
