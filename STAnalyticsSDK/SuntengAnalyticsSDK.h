//
//  SuntengAnalyticsSDK.h
//  SuntengAnalyticsSDK
//
//  Created by DullFox on 15/6/19.
//  Copyright (c) 2015年 Sunteng Technology Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 *  @brief  统计SDK版本
 *
 *  @since v1.0.0
 */
extern NSString * const kSTMAnalyticsSDKVersion;


@interface SuntengAnalyticsSDK : NSObject

+ (instancetype)sharedInstance;

#pragma mark - 初始化 SDK

/**
 *  @brief  初始化统计 SDK 方法，使用默认渠道（渠道为 App Store）
 *
 *  @param aTrackingId 跟踪ID（必填，需要在『AppDelegate』方法中使用，开发者可以在 SDK 官网申请获取。）
 *
 *  @since V1.0.0
 */
- (void)startWithTrackingId:(NSString *)aTrackingId;

/**
 *  @brief  初始化统计 SDK 方法，用户自定义渠道
 *
 *  @param aTrackingId 跟踪ID（必填，需要在『AppDelegate』方法中使用，开发者可以在 SDK 官网申请获取。）
 *  @param aChannelId  渠道ID（用以区分不通发布渠道，如 App Store、91等。）
 *
 *  @since v1.0.0
 */
- (void)startWithTrackingId:(NSString *)aTrackingId channelId:(NSString *)aChannelId;

#pragma mark - 使用 ID 追踪用户

/**
 *  @brief  设置用户ID，默认用户ID为空
 *
 *  @param anUserId 用户ID（开发者使用如邮箱、手机号码等，用以追踪具体用户。需要每次初始化后设置，SDK 不保存用户 ID。切换用户，注销等直接设置新 ID 或者 nil。）
 *
 *  @since v1.0.0
 */
- (void)setUserId:(NSString *)anUserId;

#pragma mark - 页面统计

/**
 *  @brief  进入页面方法（在对应页面的『viewDidAppear』方法中使用。如需统计页面停留时长，需要跟『exitPage:』方法配对使用，否则只能统计到路径。）
 *
 *  @param aPageName 页面名称
 *
 *  @since v1.0.0
 */
- (void)enterPage:(NSString *)aPageName;

/**
 *  @brief  进入页面方法（在对应页面的『viewDidAppear』方法中使用。如需统计页面停留时长，需要跟『exitPage:url:』方法配对使用，否则只能统计到路径。）
 *
 *  @param aPageName 页面名称
 *  @param aPath 可选，页面其他第二维度
 *
 *  @since 1.0.0
 */
- (void)enterPage:(NSString *)aPageName path:(NSString *)aPath;

/**
 *  @brief  退出页面方法（在对应页面的『viewDidDisappear』方法中使用。）
 *
 *  @param aPageName 页面名称
 *
 *  @since 1.0.0
 */
- (void)exitPage:(NSString *)aPageName;

/**
 *  @brief  退出页面方法（在对应页面的『viewDidDisappear』方法中使用。）
 *
 *  @param aPageName 页面名称
 *  @param aPath 可选，页面其他第二维度
 *
 *  @since 1.0.0
 */
- (void)exitPage:(NSString *)aPageName path:(NSString *)aPath;

#pragma mark - 行为事件统计

/**
 *  @brief  行为事件统计方法
 *
 *  @param aCategory 事件分类（必填）
 *  @param aAction   事件动作（必填）
 *  @param aLabel    事件标签（可选）
 *  @param aValue    事件价值（可选）
 *
 *  @since 1.0.0
 */
- (void)eventWithCategory:(NSString *)aCategory action:(NSString *)aAction label:(NSString *)aLabel value:(float)aValue;

@end
