#include "Header.h"
#import <XCTest/XCTest.h>

@interface teest : XCTestCase

@end

@implementation teest

- (void)testLab {
    
    Student* p = new Student;
    p->prizv = "Petrenko";
    p->kurs = SECOND;
    p->spec = KN;
    p->fiz = 5;
    
    double t = DisplayAverageGrades(p, 1)
    
    XCTAssertEqual(t, 100.);
    
}



@end
