//
//  Delegate.h
//  TestingObjectiveC
//

#ifndef TestingObjectiveC_Delegate_h
#define TestingObjectiveC_Delegate_h


/*
 *
 */
@protocol DadProtocol <NSObject>
- (void) WorkStarted:(NSString *)task;
- (void) WorkFinished:(NSString *)task;
@end


/*
 *
 */
@interface Child : NSObject {
    id <DadProtocol> dad;
}
@property (retain, nonatomic) NSString *task;
@property (retain, nonatomic) NSString *name;

-(id) initWithName:(NSString *)name;
-(void) StartHouseProject: (NSString *)task;
-(void) SetDelegate:(id <DadProtocol>) kid;
@end


/*
 *
 */
@interface Dad : NSObject <DadProtocol>
-(void) WifeWantHouse:(NSString *)task FromChild:(Child *) kid;
@end


#endif
