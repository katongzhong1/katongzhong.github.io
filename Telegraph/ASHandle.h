/*
 * This is the source code of Telegram for iOS v. 1.1
 * It is licensed under GNU GPL v. 2 or later.
 * You should have received a copy of the license in this archive (see LICENSE).
 *
 * Copyright Peter Iakovlev, 2013.
 */

#import <Foundation/Foundation.h>

@protocol ASWatcher;

@interface ASHandle : NSObject

/*! 协议 */
@property (nonatomic, weak) id<ASWatcher> delegate;
/*! 是否在主线程 */
@property (nonatomic) bool releaseOnMainThread;

#pragma mark - Init
///=============================================================================
/// @name 初始化
///=============================================================================

/*! 初始化方法
 *  @param delegate
 */
- (id)initWithDelegate:(id<ASWatcher>)delegate;
- (id)initWithDelegate:(id<ASWatcher>)delegate releaseOnMainThread:(bool)releaseOnMainThread;

#pragma mark - Function
///=============================================================================
/// @name Function
///=============================================================================

/*! 重置 action 的 delegate 为 nil */
- (void)reset;
/*! 判断是否有 delegate */
- (bool)hasDelegate;

/*! 执行代理方法 actionStageActionRequested:options: */
- (void)requestAction:(NSString *)action options:(id)options;
- (void)receiveActorMessage:(NSString *)path messageType:(NSString *)messageType message:(id)message;
- (void)notifyResourceDispatched:(NSString *)path resource:(id)resource;
- (void)notifyResourceDispatched:(NSString *)path resource:(id)resource arguments:(id)arguments;

@end
