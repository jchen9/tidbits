//
//  AppController.m
//  KVCFun
//
//  Created by Julian on 2/22/10.
//  Copyright 2010 Julian Yu-Chung Chen. All rights reserved.
//

#import "AppController.h"

@implementation AppController

@synthesize fido;

/*
 // @synthesize fido elimates the calls below
-(int) fido
{
	return fido;
}

-(void) setFido:(int) anInt
{
	fido = anInt;
}
*/

-(id) init
{
	[super init];
	fido = 34;

	return self;
}

-(IBAction) increment:(id)sender
{
		// Use properties + Obj-C 2.0 dot syntax
		// NSNumber *number = [NSNumber numberWithInt:(fido+1)];
		// [self setValue:number forKey:@"fido"];
	self.fido++;
}

@end
