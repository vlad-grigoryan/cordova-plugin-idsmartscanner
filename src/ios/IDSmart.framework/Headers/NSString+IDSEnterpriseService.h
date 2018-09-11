//
//  NSString+IDSEnterpriseService.h
//  IDSWebServices
//
//  Created by David Okun on 10/11/2016.
//  Copyright © 2016 IDscan Biometrics Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Depicts the high level result of the object it is encapsulated in.

 - IDSEnterpriseResponseHighLevelResultPassed: The document or journey satisfied the requirements of the enterprise service.
 - IDSEnterpriseResponseHighLevelResultRefer: The document or journey contains elements that may be of concern to the enterprise service.
 - IDSEnterpriseResponseHighLevelResultNotSupported: The document or journey contains elements that are not supported by the enterprise service.
 - IDSEnterpriseResponseHighLevelResultNotAccepted: The document or journey contains elements that, per the business rules, are not accepted by the enterprise service.
 - IDSEnterpriseResponseHighLevelResultUndefined: The document or journey cannot be defined by the images provided.
 - IDSEnterpriseResponseHighLevelResultExpired: The document or journey contains documents that are expired.
 */
typedef NS_ENUM(NSInteger, IDSEnterpriseResponseHighLevelResult) {
    IDSEnterpriseResponseHighLevelResultPassed = 0,
    IDSEnterpriseResponseHighLevelResultRefer,
    IDSEnterpriseResponseHighLevelResultNotSupported,
    IDSEnterpriseResponseHighLevelResultNotAccepted,
    IDSEnterpriseResponseHighLevelResultUndefined,
    IDSEnterpriseResponseHighLevelResultExpired
};

@interface NSString (IDSEnterpriseService)

- (nullable NSDate *)IDSEnterprise_getDateFromStringBasic;

- (nullable NSDate *)IDSEnterprise_getDateFromString;

- (IDSEnterpriseResponseHighLevelResult)IDSEnterprise_getHighLevelResult;

@end
