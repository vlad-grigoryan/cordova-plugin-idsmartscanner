//
//  IDSEnterpriseProcessedDocumentField.h
//  IDSWebServices
//
//  Created by David Okun on 10/11/2016.
//  Copyright © 2016 IDscan Biometrics Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Depicts whether the front or the back side of the document is depicted

 - IDSEnterpriseProcessedDocumentSideFront: Front side of the document
 - IDSEnterpriseProcessedDocumentSideBack: Back side of the document
 */
typedef NS_ENUM(NSInteger, IDSEnterpriseProcessedDocumentSide) {
    IDSEnterpriseProcessedDocumentSideFront = 0,
    IDSEnterpriseProcessedDocumentSideBack
};

/**
 Metadata relevant to the field scanned on a particular document. All bounding rectangle values are referring to the 'WhiteImage' image processed by the IDSEnterpriseProcessedDocument object.
 */
@interface IDSEnterpriseProcessedDocumentField : NSObject

/**
 The height of the bounding rectangle of the depicted field.
 */
@property (nonatomic, nonnull, readonly) NSNumber *boundsHeight;

/**
 Which image this bounding rectangle came from.
 */
@property (nonatomic, nonnull, readonly) NSString *boundsSource;

/**
 The width of the bounding rectangle of the depicted field.
 */
@property (nonatomic, nonnull, readonly) NSNumber *boundsWidth;

/**
 The x-origin of the bounding rectangle of the depicted field.
 */
@property (nonatomic, nonnull, readonly) NSNumber *boundsXPosition;

/**
 The y-origin of the bounding rectangle of the depicted field.
 */
@property (nonatomic, nonnull, readonly) NSNumber *boundsYPosition;

/**
 Whether the image of this scanned document is the front or backside of the physical document.
 */
@property (nonatomic, assign, readonly) IDSEnterpriseProcessedDocumentSide documentSide;

/**
 An identifier for this particular field.
 */
@property (nonatomic, nonnull, readonly) NSString *identityMeansScanID;

/**
 The name of the extracted field.
 */
@property (nonatomic, nonnull, readonly) NSString *name;

/**
 The value of the extracted field text.
 */
@property (nonatomic, nonnull, readonly) NSString *value;

@end
