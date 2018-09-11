//
//  IDSDocumentScannerController.h
//  IDSmart SDK
//
//  Created by Stanislav Kozyrev <s.kozyrev@idscan.co.uk>.
//  Modified by Tomas Zemaitis <t.zemaitis@idscan.co.uk>.
//  Modified by Edvardas Maslauskas <e.maslauskas@idscan.com>
//  Copyright (c) 2014 IDScan Biometrics Ltd. All rights reserved.
//

#import "IDSBase.h"
#import <UIKit/UIKit.h>

@class IDSDocumentScannerController;
@class IDSFeature;

#pragma mark - Scanner delegate protocol

/**
 * The metadata object containing document scanning result. The
 * value is of type IDSMetadataDocumentObject if scanner type is
 * IDSDocumentScannerTypeDocument
 */
IDSMART_EXPORT NSString *const IDSDocumentScannerInfoMetadataObject;

/**
 * @brief The extracted image on which scanner procedure was performed. The
 * Value is of type UIImage.
 */
IDSMART_EXPORT NSString *const IDSDocumentScannerInfoImage;

/**
 * @brief The extracted image information about possible recognition quality.
 */
IDSMART_EXPORT NSString *const IDSDocumentScannerInfoFeature;

/**
 * The IDSDocumentCaptureControllerDelegate protocol defines methods
 * that your delegate object must implement to interact with the document
 * capture interface.
 */
IDSMART_CLASS_EXPORT
@protocol IDSDocumentScannerControllerDelegate <NSObject>

@optional
/**
 * Tells the delegate that the scanner recognized a document object
 * in the image.
 * @deprecated The method is deprecated. First deprecated in v1.5.0
 */
- (void)documentScannerController:(IDSDocumentScannerController *)scanner didExtractImage:(CGImageRef)image DEPRECATED_MSG_ATTRIBUTE("The method is deprecated. First deprecated in v1.5.0");

@optional
/**
 * Tells the delegate that the scanner is unable to perform its duties.
 */
- (void)documentScannerController:(IDSDocumentScannerController *)scanner didFailWithError:(NSError *)error;

@optional
/**
 * Tells the delegate that the user cancelled the scan operation.
 */
- (void)documentScannerControllerDidCancel:(IDSDocumentScannerController *)scanner;

@optional
/**
 * Tells the delegate that the scanner recognized a document object
 * in the image.
 */
- (void)documentScannerController:(IDSDocumentScannerController *)scanner didFinishScanningWithInfo:(NSDictionary *)info;

@end

#pragma mark - Scanner class interface
/**
 *  The initial image that is passed to the document scanner controller,
 *  in case the user just wants to pass an image from the camera roll for cropping
 */
IDSMART_EXPORT NSString *const IDSDocumentScannerOptionImage;

/**
 *  This is where you indicate the type of scanner you want to instantiate.
 */
typedef NS_ENUM(NSInteger, IDSDocumentScannerControllerType) {
    /**
     *  For general document scanning and extraction
     */
    IDSDocumentScannerControllerTypeDocument = 0
};

/**
 * The IDSDocumentScannerController class manages framework-supplied user
 * interfaces for scanning documents. A document scanner controller manages user
 * interactions and delivers the results of those interactions to a delegate
 * object.
 */
IDSMART_CLASS_EXPORT
@interface IDSDocumentScannerController : UIViewController

/**
 * The document scanner’s delegate object.
 */
@property (weak, nonatomic) id<IDSDocumentScannerControllerDelegate> delegate;

/**
 *  Returns a new instance of the document scanner initialized according to the specified options
 *
 *  @param type    IDSDocumentScannerType enum to indicate what kind of scanner to use
 *  @param options NSDictionary of options to configure the scanner. Can be nil.
 */
- (instancetype)initWithScannerType:(IDSDocumentScannerControllerType)type options:(NSDictionary *)options;

@end
