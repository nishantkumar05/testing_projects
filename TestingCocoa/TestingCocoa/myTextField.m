//
//  myTextField.m
//  TestingCocoa
//
//  Created by nishant kumar on 7/16/13.
//  Copyright (c) 2013 F5 Networks Inc. All rights reserved.
//

#import "myTextField.h"

@implementation myTextField;

@synthesize myDataSource;

- (id)initWithFrame:(NSRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code here.
    }
    
    return self;
}

- (void)drawRect:(NSRect)dirtyRect
{
    // Drawing code here.
}

- (void) awakeFromNib {
	//Set background color by default
	
    /*	[out_LogoImage setImage:[NSImage imageNamed:@"banner_logo"]];
     
     [out_StatusCaption setTextColor:[NSColor colorWithCalibratedRed:1. green:1. blue:1. alpha:0.9]];
     [out_StatusCaption setFont:[NSFont titleBarFontOfSize:22]];
     [out_StatusCaption setStringValue:edgeLocalizedStringForKey(@"Not configured.", @"banner view")];
     */
	[IB_myTextView setTextColor:[NSColor colorWithCalibratedRed:0.1 green:8.3 blue:0.3 alpha:(CGFloat)1.]];
	[IB_myTextView setFont:[NSFont titleBarFontOfSize:25]];
	[IB_myTextView setStringValue:@"Hellow World!"];
}

- (IBAction)saveAction:(id)sender {
  //  [IB_myTextView setStringValue:@"Hellow New World!"];
}

- (IBAction)performClick:(id)sender {
    [IB_myTextView setStringValue:@"Hellow New World!"];
}


@end
