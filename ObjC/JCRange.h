/*
 *  JCRange.h
 *  Similar to NSRange but use double instead of NSUInteger
 *
 *  Created by Julian on 10/15/10.
 *
 */

#import <Cocoa/Cocoa.h>

#define USE_JCRANGE (true)

typedef struct _JCRange {
    double location;
	double length;
} JCRange;

typedef JCRange *JCRangePointer;

NS_INLINE JCRange JCMakeRange(double loc, double len) {
    JCRange r;
    r.location = loc;
    r.length = len;
    return r;
}

NS_INLINE double JCMaxRange(JCRange range) {
    return (range.location + range.length);
}

NS_INLINE BOOL JCLocationInRange(double loc, JCRange range) {
    return ( (loc - range.location) < range.length);
}

NS_INLINE BOOL JCEqualRanges(JCRange range1, JCRange range2) {
    return (range1.location == range2.location && range1.length == range2.length);
}

NS_INLINE BOOL JCRangeIntersect(JCRange range1, JCRange range2)
{
	BOOL r = NO;
	
	double largeLocation = range2.location;
	JCRange range = range1;
	
	if(range1.location > range2.location)
	{
		largeLocation = range1.location;
		range = range2;
	}
	
	if(JCLocationInRange(largeLocation, range))
	{
		r = YES;
	}
	
	return r;
}

NS_INLINE JCRange JCUnionRange(JCRange range1, JCRange range2) 
{
	JCRange r;
	r.location = 0;
	r.length = 0;
	
	if(JCRangeIntersect(range1, range2))
	{
		r.location = (range1.location < range2.location) ? range1.location : range2.location;
		double max = ( JCMaxRange(range1) > JCMaxRange(range2) ) ? JCMaxRange(range1) : JCMaxRange(range2);
		r.length = max - r.location;
	}

	return r;
}

NS_INLINE NSString *NSStringFromJCRange(JCRange range)
{
	NSString *s = [NSString stringWithFormat:@"{location=%f, length=%f}", range.location, range.length];
	
	return s;
}

NS_INLINE JCRange JCRangeFromString(NSString *aString)
{
	JCRange r;
	r.location = 0;
	r.length = 0;
	
	NSArray *strs = [aString componentsSeparatedByString:@"="];
	
	NSString *locationStr = [[[strs objectAtIndex:1] componentsSeparatedByString:@","] objectAtIndex:0];
	NSString *lengthStr = [[[strs objectAtIndex:2] componentsSeparatedByString:@"}"] objectAtIndex:0];
		
	double location = [locationStr doubleValue];
	double length = [lengthStr doubleValue];

	r.location = location;
	r.length   = length;
	
	return r;
}

// FOUNDATION_EXPORT JCRange JCUnionRange(JCRange range1, JCRange range2);
// FOUNDATION_EXPORT NSString *NSStringFromJCRange(JCRange range);
// FOUNDATION_EXPORT JCRange JCRangeFromString(NSString *aString);
// FOUNDATION_EXPORT NSRange NSIntersectionRange(NSRange range1, NSRange range2);

/*
@interface NSValue (NSValueRangeExtensions)

+ (NSValue *)valueWithRange:(NSRange)range;
- (NSRange)rangeValue;

@end
*/
