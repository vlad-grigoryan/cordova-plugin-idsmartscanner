//
//  IDSIDESOnline.h
//  IDSWebService
//
//  Created by david on 18/09/2015.
//  Copyright (c) 2015 IDScan Biometrics. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 * @typedef IDSAuthenticationResult
 * @brief Defines authentication result.
 * @constant IDSAuthenticationResultSuccessful if successfull authentication result exists.
 * @constant IDSAuthenticationResultInvalidCredentials if credentials are invalid or wrong.
 * @constant IDSAuthenticationResultError when there is no enterprise URL exists in configuration plist.
 */
typedef NS_ENUM(NSInteger, IDSAuthenticationResult) {
    ///  if successfull authentication result exists.
    IDSAuthenticationResultSuccessful = 0,
    
    /// if credentials are invalid or wrong.
    IDSAuthenticationResultInvalidCredentials,
    
    ///  when there is no enterprise URL exists in configuration plist.
    IDSAuthenticationResultError
};

/**
 * @typedef IDSScanResult
 * @brief Defines scan results.
 * @constant IDSScanResultPassed if scan result succesfully passed.
 * @constant IDSScanResultServerError if server error occurs.
 * @constant if an error such as internal occures.
 * @constant IDSScanResultNotAuthenticated when scanning result authentication is unsuccesfull.
 */
typedef NS_ENUM(NSInteger, IDSScanResult) {
    /// if scan result succesfully passed.
    IDSScanResultPassed = 0,
    
    /// if server error occurs.
    IDSScanResultServerError,
    
    /// if an error such as internal occures.
    IDSScanResultInternalError,
    
    /// when scanning result authentication is unsuccesfull.
    IDSScanResultNotAuthenticated
};

/**
 * @typedef IDSRequiredAction
 * @brief Defines required actions from server.
 * @constant IDSRequiredActionSecondScan when scanning needs to be done again.
 * @constant IDSRequiredActionThirdScan when third scanning has to be done.
 * @constant IDSRequiredActionScanBackside When backside of the document scan needed.
 * @constant IDSRequiredActionNone When journey finished.
 * @constant IDSRequiredActionInternalError
 */
typedef NS_ENUM(NSInteger, IDSRequiredAction) {
    ///  When scanning needs to be done again.
    IDSRequiredActionSecondScan = 0,
    
    /// When third scanning has to be done.
    IDSRequiredActionThirdScan,
    
    ///  When backside of the document scan needed.
    IDSRequiredActionScanBackside,
    
    /// When journey finished.
    IDSRequiredActionNone,
    
    /// When internal occures.
    IDSRequiredActionInternalError
};

/**
 IDSIDESOnline class responsible for sending document images to enterprise backend.
 */
DEPRECATED_MSG_ATTRIBUTE("The class is deprecated since v1.5.0. Use IDSEnterpriseService instead.")
@interface IDSIDESOnline : NSObject

/**
 *  Authenticates client with server for document recognition and authentication
 *
 *  @param completionHandler Returns IDSAuthenticationResult enum, NSString containing authentication token (handled automatically) and NSError if contained
 *  @deprecated The class is deprecated since v1.5.0. Use IDSEnterpriseService instead.
 */
+ (void)authenticateSessionWithCompletion:(void (^)(IDSAuthenticationResult result,
                                              NSString *authToken,
                                                    NSError *error))completionHandler DEPRECATED_MSG_ATTRIBUTE("The method is deprecated since v1.5.0. Use IDSEnterpriseService instead.");

/**
 *  Authenticates and recognizes document
 *
 *  @param identityDocumentImage UIImage of document youd like to scan - it's best to use IDSDocumentScannerController to capture a clean, cropped image.
 *  @param completionHandler     Returns IDSScanResult, IDSRequiredAction enums, along with an NSDictionary of the JSON payload returned, and an NSError if applicable.
 *  @deprecated The method is deprecated since v1.5.0. Use IDSEnterpriseService submitDocument: instead.
 */
+ (void)submitIdentityDocument:(UIImage *)identityDocumentImage completion:(void (^)(IDSScanResult result,
                                                                               IDSRequiredAction requiredAction,
                                                                               NSDictionary *responsePayload,
                                                                               NSError *error))completionHandler DEPRECATED_MSG_ATTRIBUTE("The method is deprecated since v1.5.0. Use IDSEnterpriseService submitDocument: instead.");

/**
 *  Authenticates and recognizes utility document
 *
 *  @param utilityDocumentImage UIImage of utility document youd like to scan - it's best to use IDSDocumentScannerController to capture a clean, cropped image.
 *  @param completionHandler    Returns IDSScanResult, IDSRequiredAction enums, along with an NSDictionary of the JSON payload returned, and an NSError if applicable.
 *  @deprecated The method is deprecated since v1.5.0. Use IDSEnterpriseService submitDocument: instead.
 */
+ (void)submitUtilityDocument:(UIImage *)utilityDocumentImage completion:(void (^)(IDSScanResult result,
                                                                                   IDSRequiredAction requiredAction,
                                                                                   NSDictionary *responsePayload,
                                                                                   NSError *error))completionHandler DEPRECATED_MSG_ATTRIBUTE("The method is deprecated since v1.5.0. Use IDSEnterpriseService submitDocument: instead.");

@end
