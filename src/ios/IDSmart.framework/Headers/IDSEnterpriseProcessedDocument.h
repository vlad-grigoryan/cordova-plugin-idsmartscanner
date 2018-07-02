//
//  IDSEnterpriseProcessedDocument.h
//  IDSWebServices
//
//  Created by David Okun on 10/11/2016.
//  Copyright © 2016 IDscan Biometrics Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDSEnterpriseProcessedDocumentField.h"
#import "NSString+IDSEnterpriseService.h"

/**
 Depicts the details of a processed document by the onboarding suite, contained within an IDSEnterpriseDetailResponse object. Many fields have the potential to be nil, as this object could potentially represent either an identity document or a utility document.
 */
@interface IDSEnterpriseProcessedDocument : NSObject

/**
 The three letter country code that represents the country that this document originates from.
 */
@property (nonatomic, nullable, readonly) NSString *countryCode;

/**
 The name of the country that this document originates from.
 */
@property (nonatomic, nullable, readonly) NSString *countryName;

/**
 The category of the scanned document.
 */
@property (nonatomic, nullable, readonly) NSString *documentCategory;

/**
 A map of the images, with the name of the image and the URL that it can be downloaded from.
 */
@property (nonatomic, nullable, readonly) NSDictionary<NSString *, NSURL *> *documentImages;

/**
 The name of the document that has been scanned.
 */
@property (nonatomic, nullable, readonly) NSString *documentName;

/**
 The identifying document number of the document that has been scanned.
 */
@property (nonatomic, nullable, readonly) NSString *documentNumber;

/**
 The type of document that has been scanned.
 */
@property (nonatomic, nullable, readonly) NSString *documentType;

/**
 The date when the document that has been scanned will no longer be valid.
 */
@property (nonatomic, nullable, readonly) NSDate *expiryDate;

/**
 An array of extracted fields and relevant metadata. See documentation for IDSEnterpriseProcessedDocumentField for more information.
 */
@property (nonatomic, nullable, readonly) NSArray<IDSEnterpriseProcessedDocumentField *> *extractedFields;

/**
 The high level result of this particular scanned document. It is important to note that a document can be expired and yet still be contained within a passing journey.
 */
@property (nonatomic, assign, readonly) IDSEnterpriseResponseHighLevelResult highLevelResult;

/**
 Whether the document was recognized by the IDscan Enterprise server or not.
 */
@property (nonatomic, assign, readonly) BOOL isRecognized;

/**
 The date when this document was issued by its governing authority.
 */
@property (nonatomic, nullable, readonly) NSDate *issueDate;

/**
 Which page of the document this is. For example, if this is the second page of a utility bill, this will be reflected in this value. Identity documents always show 0 except in exceptional circumstances, such as an ID booklet or otherwise.
 */
@property (nonatomic, assign, readonly) NSInteger page;

/**
 When the document expert system finished processing this document.
 */
@property (nonatomic, nonnull, readonly) NSDate *processFinishedDateTime;

/**
 When the document expert system started processing this document.
 */
@property (nonatomic, nonnull, readonly) NSDate *processStartedDateTime;

/**
 Whether the image represented in this scan is the frontside or backside of the physical document.
 */
@property (nonatomic, assign, readonly) IDSEnterpriseProcessedDocumentSide side;

/**
 The subtype of the scanned document.
 */
@property (nonatomic, nullable, readonly) NSString *subtype;

/**
 Attempt number for the workflow. This is relevant if something like Triple Scan Mode is in effect, to give the client an idea of how many times this document was scanned trying to satisfy the business rules.
 */
@property (nonatomic, assign, readonly) NSInteger workflowAttempt;

@end
