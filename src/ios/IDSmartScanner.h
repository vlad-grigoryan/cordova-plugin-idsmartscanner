/* IDSmartScanner.h */

#import <Cordova/CDV.h>
typedef NS_ENUM(NSUInteger, IDSmartScannerSource) {
    IDSmartScannerSourceDocument,
    IDSmartScannerSourceSelfie
};

extern NSString * const IDSmartScannerScanCommandTypeArgument;

extern NSString *IDSmartScannerSourceRawValue(IDSmartScannerSource source);

@interface IDSmartScanner : CDVPlugin

- (void)scan:(CDVInvokedUrlCommand *)command;

@end
