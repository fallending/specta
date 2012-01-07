#import <Foundation/Foundation.h>
#import "SpectaSupport.h"

@class SPTExample;

@interface SPTExampleGroup : NSObject {
  NSString *_name;
  SPTExampleGroup *_root;
  SPTExampleGroup *_parent;
  NSMutableArray *_children;
  NSMutableArray *_beforeAllBlock;
  NSMutableArray *_afterAllBlock;
  NSMutableArray *_beforeEachBlock;
  NSMutableArray *_afterEachBlock;
  unsigned int _exampleCount;
  unsigned int _ranExampleCount;
}

@property (nonatomic, copy) NSString *name;
@property (nonatomic, assign) SPTExampleGroup *root;
@property (nonatomic, assign) SPTExampleGroup *parent;
@property (nonatomic, retain) NSMutableArray *children;
@property (nonatomic, retain) NSMutableArray *beforeAllArray;
@property (nonatomic, retain) NSMutableArray *afterAllArray;
@property (nonatomic, retain) NSMutableArray *beforeEachArray;
@property (nonatomic, retain) NSMutableArray *afterEachArray;
@property (nonatomic) unsigned int exampleCount;
@property (nonatomic) unsigned int ranExampleCount;

- (id)initWithName:(NSString *)name parent:(SPTExampleGroup *)parent root:(SPTExampleGroup *)root;
- (SPTExampleGroup *)addExampleGroupWithName:(NSString *)name;
- (SPTExample *)addExampleWithName:(NSString *)name block:(SPTVoidBlock)block;
- (void)addBeforeAllBlock:(SPTVoidBlock)block;
- (void)addAfterAllBlock:(SPTVoidBlock)block;
- (void)addBeforeEachBlock:(SPTVoidBlock)block;
- (void)addAfterEachBlock:(SPTVoidBlock)block;
- (unsigned int)compileExamples:(Class)testClass index:(unsigned int)index;

@end

