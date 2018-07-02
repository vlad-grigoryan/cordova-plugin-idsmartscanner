//
//  IDSEnterpriseCredentials.h
//  IDSWebServices
//
//  Created by Edvardas Maslauskas on 03/03/2017.
//  Copyright © 2017 IDscan Biometrics Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Enumerated value to show application area, used to check if the user is authorised to access the required resource

 - IDSEnterpriseAuthenticationAreaScanning: Upload application area, used for scanning purposes
 - IDSEnterpriseAuthenticationAreaInvestigation: Retrieval applicatipm area, used for investigation purposes
 */
typedef NS_ENUM(NSInteger, IDSEnterpriseAuthenticationArea) {
    /// IDSEnterpriseAuthenticationAreaScanning: Upload application area, used for scanning purposes
    IDSEnterpriseAuthenticationAreaScanning = 0,
    
    /// Retrieval applicatipm area, used for investigation purposes
    IDSEnterpriseAuthenticationAreaInvestigation
};

/**
 Credentials object, which is used for enterprise API authentication
 */
@interface IDSEnterpriseCredentials : NSObject

/**
 User login name
 */
@property (nonatomic, nullable, readonly) NSString *username;

/**
 User password
 */
@property (nonatomic, nullable, readonly) NSString *password;

/**
 User token
 */
@property (nonatomic, nullable, readonly) NSString *token;

/**
 Backend API url prefix, example: https://yourServer
 */
@property (nonatomic, nonnull, readonly) NSString *urlPrefix;

/**
 Authentication area
 */
@property (nonatomic, assign, readonly) IDSEnterpriseAuthenticationArea area;

/**
 IDSEnterpriseCredentials constructor

 @param username User login name
 @param password User password
 @param urlPrefix Backend API url prefix, example: https://yourServer
 @param area Authentication area
 @return IDSEnterpriseCredentials object
 */
- (instancetype _Nonnull)initWithUsername:(NSString * _Nonnull)username
                        password:(NSString * _Nonnull)password
                       urlPrefix:(NSString * _Nonnull)urlPrefix
                            area:(IDSEnterpriseAuthenticationArea)area;

/**
 IDSEnterpriseCredentials constructor
 
 @param token for login
 @param urlPrefix Backend API url prefix, example: https://yourServer
 @param area Authentication area
 @return IDSEnterpriseCredentials object
 */
- (instancetype _Nonnull)initWithToken:(NSString * _Nonnull)token
                                urlPrefix:(NSString * _Nonnull)urlPrefix
                                     area:(IDSEnterpriseAuthenticationArea)area;

/**
 Method which returns json string of credentials using Enterprise API authenticate structure

 @return JSON string
 */
- (NSString * _Nonnull)getCredentialsRequestJSON;

@end
