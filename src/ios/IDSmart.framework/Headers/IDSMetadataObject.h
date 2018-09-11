//
//  IDSMetadataObject.h
//  IDSmart SDK
//
//  Created by Stanislav Kozyrev <s.kozyrev@idscan.co.uk>.
//  Copyright (c) 2014 IDScan Biometrics Ltd. All rights reserved.
//

#import "IDSBase.h"

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@class IDSMetadataDocumentObjectFields;

/**
 * @brief An IDSMetadataObjectTypeMachineReadableZone instance represents a
 * single detected machine readable zone in an image.
 */
IDSMART_EXPORT NSString *const IDSMetadataObjectTypeMachineReadableZone;
/**
 * @brief An IDSMetadataObjectTypeICAO instance represents a single
 * detected ICAO in an image.
 */
IDSMART_EXPORT NSString *const IDSMetadataObjectTypeICAO;
/**
 * @brief An IDSMetadataObjectTypeDocumentClassification instance represents a single
 * detected document classification.
 */
IDSMART_EXPORT NSString *const IDSMetadataObjectTypeDocumentClassification;

/**
 * @brief The IDSMetadataObject class defines the basic properties associated
 * with a piece of metadata. These attributes reflect information either about
 * the metadata itself or the media from which the metadata originated.
 * Subclasses are responsible for providing appropriate values for each of the
 * relevant properties.
 */
IDSMART_CLASS_EXPORT
@interface IDSMetadataObject : NSObject

/**
 * @brief The error corrected data decoded into a human-readable string or a nil
 * value if a string representation cannot be created.
 */
@property(readonly, nonatomic) NSString *stringValue;

/**
 * @brief The type of the metadata.
 */
@property(readonly, nonatomic) NSString *type;

@end

/**
 * @brief IDSMetadataMachineReadableZoneElementObject defines the chunk of
 * information read from machine readable zone. Defines its value, confidence
 * and location on the processed image.
 */
IDSMART_CLASS_EXPORT
@interface IDSMetadataMachineReadableZoneElementObject : NSObject

/**
 * @brief value of mrz element.
 */
@property(nonatomic) NSString *value;

/**
 * @brief confidence of mrz element value
 */
@property(nonatomic) NSInteger confidence;

/**
 * @brief top left corner of mrz element location
 */
@property(nonatomic) CGPoint topLeft;

/**
 * @brief top right corner of mrz element location
 */
@property(nonatomic) CGPoint topRight;

/**
 * @brief bottom left corner of mrz element location
 */
@property(nonatomic) CGPoint bottomLeft;

/**
 * @brief bottom right corner of mrz element location
 */
@property(nonatomic) CGPoint bottomRight;

@end

/**
 * @brief An IDSMetadataMachineReadableZoneObject instance defines a recognized
 * machine readable zone object in an image. It is an immutable object
 * describing some extracted document features.
 */
IDSMART_CLASS_EXPORT
@interface IDSMetadataMachineReadableZoneObject : IDSMetadataObject

/**
 * @brief A mandatory value that designates the holder's date of birth.
 */
@property (readonly, nonatomic) IDSMetadataMachineReadableZoneElementObject *dateOfBirth;

/**
 * @brief A mandatory value that designates the document's date of expiry or
 * valid until date.
 */
@property (readonly, nonatomic) IDSMetadataMachineReadableZoneElementObject *dateOfExpiryOrValidUntil;

/**
 * @brief A mandatory value that designates the document number.
 */
@property (readonly, nonatomic) IDSMetadataMachineReadableZoneElementObject *documentNumber;

/**
 * @brief A mandatory value that designates the particular type of the document.
 */
@property (readonly, nonatomic) IDSMetadataMachineReadableZoneElementObject *documentPrimaryType;

/**
 * @brief An optional value that is used to further identify the document at
 * the discretion of the issuing state or organization.
 */
@property (readonly, nonatomic) IDSMetadataMachineReadableZoneElementObject *documentSecondaryType;

/**
 * @brief A mandatory value that designates three-letter code (Alpha-3) used to
 * indicate the issuing state or organization.
 */
@property (readonly, nonatomic) IDSMetadataMachineReadableZoneElementObject *issuingStateOrOrganization;

/**
 * @brief A mandatory value that designates the first name of the holder.
 */
@property (readonly, nonatomic) IDSMetadataMachineReadableZoneElementObject *firstName;

/**
 * @brief A mandatory value that designates the middle name of the holder.
 */
@property (readonly, nonatomic) IDSMetadataMachineReadableZoneElementObject *middleName;

/**
 * @brief A mandatory value that designates the last name of the holder.
 */
@property (readonly, nonatomic) IDSMetadataMachineReadableZoneElementObject *lastName;

/**
 * @brief A mandatory value that designates three-letter code (Alpha-3) used to
 * indicate the nationality of the holder.
 */
@property (readonly, nonatomic) IDSMetadataMachineReadableZoneElementObject *nationalityCode;

/**
 * @brief A mandatory value that designates the sex of the holder.
 */
@property (readonly, nonatomic) IDSMetadataMachineReadableZoneElementObject *sex;

/**
 * @brief A mandatory value that designates the full text of machine readable zone.
 */
@property (readonly, nonatomic) IDSMetadataMachineReadableZoneElementObject *fullMRZ;

/**
 * @brief A mandatory value that designates the first line of machine readable
 * zone on the document.
 */
@property (readonly, nonatomic) IDSMetadataMachineReadableZoneElementObject *mrzLine1;

/**
 * @brief A mandatory value that designates the second line of machine readable
 * zone on the document.
 */
@property (readonly, nonatomic) IDSMetadataMachineReadableZoneElementObject *mrzLine2;

/**
 * @brief A optional value that designates the third line of machine readable
 * zone on the document.
 */
@property (readonly, nonatomic) IDSMetadataMachineReadableZoneElementObject *mrzLine3;

/**
 * @brief A mandatory value that designates the type of ICAO (International Civil
 * Aviation Organization) document.
 */
@property (readonly, nonatomic) NSString *mrzType;

/**
 * @brief A mandatory value that designates the rotation angle of the analyzed
 * document.
 */
@property (readonly, nonatomic) CGFloat deskewAngle;

/**
 * @brief A value that is used to confirm that the machine readable zone
 * values were extracted correctly.
 */
@property (readonly, nonatomic) BOOL valid;

/**
 * @brief Cropped document image.
 */
@property (readonly, assign, nonatomic) CGImageRef documentImage;

@end

/**
 * @typedef IDSMetadataICAOSourceType
 * @brief Defines posible types of icao element source.
 * - IDSICAOSourceTypeMRZ: Machine readable zone of the document.
 * - IDSICAOSourceTypeVIZ: Visual inspection zone of the document.
 */
typedef NS_ENUM(NSInteger, IDSMetadataICAOSourceType) {
    /// Machine readable zone of the document.
    IDSICAOSourceTypeMRZ = 0,
    
    /// Visual inspection zone of the document.
    IDSICAOSourceTypeVIZ
};

/**
 * @brief Source of ICAO document data element.
 */
IDSMART_CLASS_EXPORT
@interface IDSMetadataICAOElementSource : NSObject

/**
 * @brief Source type.
 */
@property(readonly, nonatomic) IDSMetadataICAOSourceType type;

/**
 * @brief Location on the processed document image.
 */
@property(readonly, nonatomic) CGRect location;

@end

/**
 * @brief ICAO document date element. Defines element value, confidence and
 * sources where this data was read.
 */
IDSMART_CLASS_EXPORT
@interface IDSMetadataICAOElementObject : NSObject

/**
 * @brief NSString showing value of detected element
 */
@property (readonly, nonatomic) NSString *value;

/**
 * @brief float value showing confidence on scale from 0-100, 100 being most
 * confident
 */
@property (readonly, nonatomic) float confidence;

/**
 * @brief array of IDSMetadataICAOElementSource object defining sources where
 * this element value was collected
 */
@property(readonly, nonatomic) NSArray *sources;

@end


/**
 * @brief An IDSMetadataICAOObject instance defines a recognized ICAO object
 * in an image. It is an immutable object describing some extracted document
 * features.
 */
IDSMART_CLASS_EXPORT
@interface IDSMetadataICAOObject : IDSMetadataObject

/**
 * @brief A value that designates the holder's first name.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *firstName;

/**
 * @brief A value that designates the holder's middle name.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *middleName;

/**
 * @brief A value that designates the holder's last name.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *lastName;

/**
 * @brief A value that designates the holder's birth date.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *dateOfBirth;

/**
 * @brief A value that designates the holder's expire date.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *dateOfExpiryOrValidUntil;

/**
 * @brief A value that designates the holder's issue date.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *issueDate;

/**
 * @brief A value that designates the holder's document number.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *documentNumber;

/**
 * @brief A value that designates the holder's personal number.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *personalNumber;

/**
 * @brief A value that designates the holder's sex.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *sex;

/**
 * @brief A value that designates the holder's birth place.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *birthPlace;

/**
 * @brief A value that designates the holder's country code.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *issuingStateOrOrganization;

/**
 * @brief A value that designates the holder's nationality code.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *nationalityCode;

/**
 * @brief A value that designates the holder's country name.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *countryName;

/**
 * @brief A value that designates the holder's nationality name.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *nationalityName;

/**
 * @brief A value that designates the first line of machine readable zone on the
 * document.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *MRZLine1;

/**
 * @brief A value that designates the second line of machine readable zone on
 * the document.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *MRZLine2;

/**
 * @brief A value that designates the third line of machine readable zone on the
 * document.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *MRZLine3;

/**
 * @brief A value that designates the full text of machine redable zone on the
 * document.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *fullMRZ;

/**
 * @brief A value that designates the document primary type.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *documentPrimaryType;

/**
 * @brief A value that designates the document secondary type.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *documentSecondaryType;

/**
 * @brief A value that designates the holder's birth date check digit.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *checkDigitBirthDate;

/**
 * @brief A value that designates the holder's expire date check digit.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *checkDigitExpireDate;

/**
 * @brief A value that designates the holder's document number check digit.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *checkDigitDocumentNumber;

/**
 * @brief A value that designates the holder's personal number check digit.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *checkDigitPersonalNumber;

/**
 * @brief A value that designates the machine readable zone composite check digit.
 */
@property (readonly, nonatomic) IDSMetadataICAOElementObject *checkDigitCompose;

/**
 * @brief Extracted document image.
 */
@property (readonly, assign, nonatomic) CGImageRef documentImage;

/**
 * @brief Location of the holder's face on the extracted document image.
 */
@property (readonly, nonatomic) CGRect face;

@end

IDSMART_CLASS_EXPORT

/**
 * @brief IDSMetadataClassificationObject defines the chunk of
 * information read from classified document. 
 */
@interface IDSMetadataClassificationObject : IDSMetadataObject

/**
 Three letter abbreviation of document type.
 */
@property (nonatomic, readonly) NSString *documentType;
/**
 Name of the country from which the document friendly name.
 */
@property (nonatomic, readonly) NSString *friendlyName;
/**
 The document rotration degree.
 */
@property (nonatomic, readonly) NSNumber *rotationDegree;
/**
 Classification score
 */
@property (nonatomic, readonly) NSNumber *score;
/**
 the confidence of document classification
 */
@property (nonatomic, readonly) NSNumber *confidence;
/**
 CGImageRef document image.
 */
@property (nonatomic, readonly) CGImageRef documentImage;

@end
