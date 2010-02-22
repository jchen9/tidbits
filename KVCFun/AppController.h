//
//  AppController.h
//  KVCFun
//
//  Created by Julian on 2/22/10.
//  Copyright 2010 Julian Yu-Chung Chen. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface AppController : NSObject {
	int fido;
}

@property (readwrite, assign) int fido;

/*
 // @property elimates the calls below
-(int) fido;
-(void) setFido:(int) anInt;
*/

-(IBAction) increment:(id)sender;
@end
