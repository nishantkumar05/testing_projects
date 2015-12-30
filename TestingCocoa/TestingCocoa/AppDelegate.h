//
//  AppDelegate.h
//  TestingCocoa
//
//  Created by nishant kumar on 7/16/13.
//  Copyright (c) 2013 F5 Networks Inc. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "myTextField.h"

@interface AppDelegate : NSObject <NSApplicationDelegate> {
    IBOutlet NSButton * out_button;
}

@property (assign) IBOutlet NSWindow *window;
@property (assign) IBOutlet NSButton * out_button;

@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;

@property (assign) NSTextField * myTextFieldDelegate;

- (IBAction)act_changeLabel:(id)sender;

@end
