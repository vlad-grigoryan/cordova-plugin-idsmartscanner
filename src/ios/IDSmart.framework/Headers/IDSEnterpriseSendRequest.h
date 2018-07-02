//
//  IDSEnterpriseSendRequest.h
//  IDSWebServices
//
//  Created by Edvardas Maslauskas on 03/03/2017.
//  Copyright © 2017 IDscan Biometrics Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>
#import "IDSEnterpriseCredentials.h"
#import "IDSEnterpriseInputImage.h"
#import "IDSEnterpriseAdditionalDataEntry.h"

/**
 Enum that depicts whether the document being submitted is either an identity or utility document

 - IDSEnterpriseDocumentTypeIdentity: The document should be scanned by IDscan Enterprise as an identity document
 - IDSEnterpriseDocumentTypeUtility:  The document should be scanned by IDscan Enterprise as a utility document
 */
typedef NS_ENUM(NSInteger, IDSEnterpriseDocumentType) {
    /// The document should be scanned by IDscan Enterprise as an identity document
    IDSEnterpriseDocumentTypeIdentity = 2,

    /// The document should be scanned by IDscan Enterprise as a utility document
    IDSEnterpriseDocumentTypeUtility = 3
};

/**
 Enterprise service class, which allows to construct the request to the backend
 */
@interface IDSEnterpriseSendRequest : NSObject

/**
 Credentials property used for authenticating the request
 */
@property (nonatomic, assign, nullable) IDSEnterpriseCredentials *credentials;

/**
 Entry unique GUID id of the entry. In order to continue the initial journey it should be set accordingly. 
 If it wasn't set, random GUID will be generated for the request.
 */
@property (nonatomic, strong, nonnull) NSString *journeyID;

/**
 The source of the document. Default value is IDSEnterpriseDocumentTypeIdentity.
 */
@property (nonatomic, assign) IDSEnterpriseDocumentType documentSource;

/**
 Method that allows user to add document image
 @param image - document image that user captured that should be passed to the enterprise server
 */
- (void)addDocument:(UIImage *_Nonnull)image;

/**
 Method that allows user to add selfie image to the request in order to perform the face match

 @param image captured selfie photo
 */
- (void)addSelfieImage:(UIImage *_Nonnull)image;

/**
 Inserts input image to the send request
 @param image - document image that user captured to pass to the enterprise server
 */
- (void)addInputImage:(IDSEnterpriseInputImage *_Nonnull)inputImage;

/**
 Method that allows the user to add additional data entry
 @param dataEntry - such as platform 
 */
- (void)addAdditionalData:(IDSEnterpriseAdditionalDataEntry *_Nonnull)dataEntry;

/**
 Method which generates request's payload dictionary
 
 @param completionHandler returns parameters and error object if mandatory fields were not set
 */
- (void)generateRequestParameters:(void (^_Nonnull)(NSDictionary *_Nullable parameters, NSError *_Nullable error))completionHandler;

/**
 Method which generates JSON string of the request's payload
 
 @param completionHandler completionHandler returns parameters and error object if mandatory fields were not set
 */
- (void)generateRequestJSON:(void (^_Nonnull)(NSString *_Nullable jsonString, NSError *_Nullable error))completionHandler;

@end
