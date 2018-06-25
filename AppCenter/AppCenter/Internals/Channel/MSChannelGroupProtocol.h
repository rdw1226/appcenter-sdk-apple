#import <Foundation/Foundation.h>

#import "MSChannelProtocol.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MSSender;
@protocol MSChannelUnitProtocol;
@class MSChannelUnitConfiguration;

/**
 * `MSChannelGroupProtocol` represents a kind of channel that contains
 * constituent MSChannelUnit objects. When an operation from the `MSChannelProtocol`
 * is performed on the group, that operation should be propagated to its
 * constituent MSChannelUnit objects.
 */
@protocol MSChannelGroupProtocol <MSChannelProtocol>

/**
 * Initialize a channel unit with the given configuration.
 *
 * @param configuration channel configuration.
 *
 * @return The added `MSChannelUnitProtocol`. Use this object to enqueue logs.
 */
- (id<MSChannelUnitProtocol>)addChannelUnitWithConfiguration:(MSChannelUnitConfiguration *)configuration;

/**
 * Initialize a channel unit with the given configuration.
 *
 * @param configuration channel configuration.
 * @param sender The alternative ingestion object
 *
 * @return The added `MSChannelUnitProtocol`. Use this object to enqueue logs.
 */
- (id<MSChannelUnitProtocol>)addChannelUnitWithConfiguration:(MSChannelUnitConfiguration *)configuration
                                                  withSender:(nullable id<MSSender>)sender;

/**
 * Attach an App Center sender to a channel group if a channel group started without an app secret.
 *
 * @param appSecret A unique and secret key used to identify the application.
 * @param installId A unique installation identifier.
 * @param logUrl A base URL to use for backend communication.
 */
- (void)attachSenderWithAppSecret:(NSString *)appSecret installId:(NSUUID *)installId logUrl:(NSString *)logUrl;

/**
 * Change the base URL (schema + authority + port only) used to communicate with the backend.
 *
 * @param logUrl base URL to use for backend communication.
 */
- (void)setLogUrl:(NSString *)logUrl;

@end

NS_ASSUME_NONNULL_END
