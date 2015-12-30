//
//  myTextView.h
//  throwaway2
//
//  Created by nishant kumar on 7/16/13.
//  Copyright (c) 2013 F5 Networks Inc. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#include "myProtocol.h"

@interface myTextField: NSTextField {
    
    IBOutlet NSTextField * IB_myTextView;
}
@property (nonatomic,retain)id <myProtocol> myDataSource;
- (IBAction)saveAction:(id)sender;
- (IBAction)performClick:(id)sender;
@end
