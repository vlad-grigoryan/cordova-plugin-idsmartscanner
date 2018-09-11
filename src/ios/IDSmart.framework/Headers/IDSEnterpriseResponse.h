//
//  IDSEnterpriseResponse.h
//  IDSWebServices
//
//  Created by David Okun on 15/09/2016.
//  Copyright © 2016 IDscan Biometrics Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSString+IDSEnterpriseService.h"

/**
 Authentication passed state constant
 */
extern NSString * _Nonnull const kIDSEnterpriseAuthenticationResultPassed;

/**
 Authentication failed state constant
 */
extern NSString * _Nonnull const kIDSEnterpriseAuthenticationResultFailed;

/**
 Authentication skipped state constant
 */
extern NSString * _Nonnull const kIDSEnterpriseAuthenticationResultSkipped;

/**
 Authentication unknown state constant
 */
extern NSString * _Nonnull const kIDSEnterpriseAuthenticationResultUnknown DEPRECATED_MSG_ATTRIBUTE("kIDSEnterpriseAuthenticationResultUnknown is deprecated");;

/**
 Authentication check is enabled and the result of it will affect the HighLevelResult of the journey.
 */
extern NSString * _Nonnull const kIDSEnterpriseAuthenticationResultSuccessNeeded;

/**
 Authentication check is enabled and the result of it won't affect the HighLevelResult of the journey.
 */
extern NSString * _Nonnull const kIDSEnterpriseAuthenticationResultNeeded;

/**
 Authentication check is disabled for this type of document.
 */
extern NSString * _Nonnull const kIDSEnterpriseAuthenticationResultNotNeeded;

/**
 Constant indicating that the backend has been configured to request the document image to 
 be recaptured again when the first document image was not validated successfully.
 */
extern NSString * _Nonnull const kIDSEnterpriseRequiredActionSecondScan;

/**
 Constant indicating that the backend has been configured to request the document
 image to be recaptured again when the second document image was not validated successfully.
 */
extern NSString * _Nonnull const kIDSEnterpriseRequiredActionThirdScan;

/**
 Constant indicating that the backend has been configured to require backside
 scanning for the document that has been captured in current journey.
 */
extern NSString * _Nonnull const kIDSEnterpriseRequiredActionScanBackside;

/**
 Constant indicating that the backend has been configured to require selfie image
 scanning for the document that has been captured in current journey.
 @since 1.6.21
 */
extern NSString * _Nonnull const kIDSEnterpriseRequiredActionCaptureSelfie;

/**
 Constant indicating that the backend has been configured to require address document
 scanning for the document that has been captured in current journey.
 @since 1.6.22
 */
extern NSString * _Nonnull const kIDSEnterpriseRequiredActionAddressDocument;

/**
 Constant indicating Indicates that the journey has finished
 and there is no further steps to perform.
 */
extern NSString * _Nonnull const kIDSEnterpriseRequiredActionNone;

/**
 Enumerated value to show the high level result of the scan, as processed by a designated enterprise server.
 */
typedef NS_ENUM(NSInteger, IDSEnterpriseScanResult) {
    /**
     Shows that the scan passed the acceptance criteria for enterprise.
     */
    IDSEnterpriseScanResultPassed = 0,
    
    /**
     Shows that there was a server error.
     */
    IDSEnterpriseScanResultServerError,
    
    /**
      Shows that there was an internal API error.
     */
    IDSEnterpriseScanResultInternalError,
    
    /**
      Shows that the scan was not able to be authenticated for some reason.
     */
    IDSEnterpriseScanResultNotAuthenticated
};

/**
 Object depicting the response from an IDscan Enterprise server when a scan of an identity or utility document is completed.
 */
@interface IDSEnterpriseResponse : NSObject

/**
 IDSEnterpriseScanResult showing the result of the previously completed scan.
 */
@property (nonatomic, assign, readonly) IDSEnterpriseScanResult scanResult;
    
/**
 The high level result of the journey's processing result.
 */
@property (nonatomic, assign, readonly) IDSEnterpriseResponseHighLevelResult highLevelResult;

/**
 IDSEnterpriseRequiredAction showing what is needed to continue in the scanning journey, as depicted by IDscan Enterprise.
 */
@property (nonatomic, nullable, readonly) NSString *requiredAction;

/**
 NSString depicting the branch code, which is simply an identifier of which server processed the request.
 */
@property (nonatomic, nullable, readonly) NSString *branchCode;

/**
 NSString depicting the customer number, which is an identifier for the device making the scan attempt.
 */
@property (nonatomic, nullable, readonly) NSString *customerNumber;

/**
 NSString depicting the type of document that was detected by IDscan Enterprise.
 */
@property (nonatomic, nullable, readonly) NSString *documentType;

/**
 NSDictionary containing a map of extracted fields from the document. These are only fields that can be optionally extracted from high level processing. Please contact IDscan if you require access to an API that returns more in-depth data about completed scans.
 */
@property (nonatomic, nullable, readonly) NSDictionary<NSString *, NSString *> *extractedFields;

/**
 NSString depicting the reason for a particular scan, if one is specified by the server.
 */
@property (nonatomic, nullable, readonly) NSString *scanReason;

/**
 NSString depicting the reference number of the completed scan.
 */
@property (nonatomic, nonnull, readonly) NSString *scanReference;

/**
 NSString depicting the username of the user who attempted the scan.
 */
@property (nonatomic, nullable, readonly) NSString *scanUsername;

/**
 NSDate showing the time and date that the scan was registered and completed on the server.
 */
@property (nonatomic, nonnull, readonly) NSDate *scanDateTime;

/**
 NSString depicting the personEntryID. The person entry ID is to bind multiple images together as part of one journey. Please refer to the IDSEnterpriseService documentation for more information on how this string is used.
 */
@property (nonatomic, nullable, readonly) NSString *personEntryID DEPRECATED_MSG_ATTRIBUTE("personEntryID is deprecated. Please use journeyID property instead.");

/**
 NSString depicting the personEntryID. The journey ID is to bind multiple images together as part of one journey. Please refer to the IDSEnterpriseService documentation for more information on how this string is used.
*/
@property (nonatomic, nullable, readonly) NSString *journeyID;

/**
 NSString depicting the identityMeansID. The identity means ID is to bind multiple images together as part of one document, for example, the front and back of a driver's license. Please refer to the IDSEnterpriseService documentation for more information on how this string is used.
 */
@property (nonatomic, nullable, readonly) NSString *identityMeansID;

/**
 NSString depicting the unique request ID for the scan that was completed.
 */
@property (nonatomic, nonnull, readonly) NSString *requestID;

/**
 NSString depicting the results of the business rules applied to the document on the server.
 */
@property (nonatomic, nullable, readonly) NSDictionary<NSString *, NSString *> *authenticationResultDetails;

/**
 NSDictionary depicting raw response dictionary from the server.
 */
@property (nonatomic, nonnull, readonly) NSDictionary *responsePayload;

@end
