//
//  IDSEnterpriseDetailResponse.h
//  IDSWebServices
//
//  Created by David Okun on 10/11/2016.
//  Copyright © 2016 IDscan Biometrics Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IDSEnterpriseProcessedDocument.h"
#import "IDSEnterpriseProcessedDocumentField.h"
#import "NSString+IDSEnterpriseService.h"


/**
 This object is depicting the details of an IDscan Enterprise scan journey, and all relevant documents.
 */
@interface IDSEnterpriseDetailResponse : NSObject

/**
 Shows additional data relevant to the particular scan.
 */
@property (nonatomic, nullable, readonly) NSDictionary *additionalData;

/**
 Age of the person who completed the journey. Will default to 0 if age cannot be determined from journey.
 */
@property (nonatomic, assign, readonly) NSInteger age;

/**
 The date and time when the entry was created and the journey was started.
 */
@property (nonatomic, nonnull, readonly) NSDate *entryDateTime;

/**
 The identifier for this person internally to the onboarding suite.
 */
@property (nonatomic, nonnull, readonly) NSString *evaluatedPersonEntryID;

/**
 The first name of the person. Can be nil if the first name is not able to be read from the journey.
 */
@property (nonatomic, nullable, readonly) NSString *firstName;

/**
 The full name of the person, which is usually the first name and last name joined together. Can be nil if the name is not able to be read from any images in the journey.
 */
@property (nonatomic, nullable, readonly) NSString *fullName;

/**
 The gender of the person who has engaged in the journey. Can be nil if the gender is not discernable from any images in the journey.
 */
@property (nonatomic, nullable, readonly) NSString *gender;

/**
 The high level result of the journey as a whole. Keep in mind that multiple documents within the journey could have different results, but the business logic of the journey contributes to how this journey is graded.
 */
@property (nonatomic, assign, readonly) IDSEnterpriseResponseHighLevelResult highLevelResult;

/**
 The last name of the person. Can be nil if the last name is not able to be read from the journey.
 */
@property (nonatomic, nullable, readonly) NSString *lastName;

/**
 The personProfileID depicts a specific person with an identifier.
 */
@property (nonatomic, nonnull, readonly) NSString *personProfileID;

/**
 An array of processed documents within the journey. See documentation for specific object.
 */
@property (nonatomic, nullable, readonly) NSArray<IDSEnterpriseProcessedDocument *> *processedDocuments;

/**
 The reference number, which was used to determine which journey would be detailed.
 */
@property (nonatomic, nonnull, readonly) NSString *referenceNumber;

/**
 Reason for the scan. Can be nil if this was not listed or detailed.
 */
@property (nonatomic, nullable, readonly) NSString *scanReason;

@end
