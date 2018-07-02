//
//  IDSEnterpriseService.h
//  IDSWebServices
//
//  Created by David Okun on 15/09/2016.
//  Copyright © 2016 IDscan Biometrics Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>
#import "IDSEnterpriseResponse.h"
#import "IDSEnterpriseDetailResponse.h"
#import "IDSEnterpriseSendRequest.h"

/**
 Service class to communicate images back and forth between the instance of an IDscan Enterprise Server
 */
@interface IDSEnterpriseService : NSObject

/**
 Method that allows the user to submit an identity or an utility document to the enterprise server

 @param documentImage         UIImage that shows the document we are choosing to send.
 @param documentType          Enumerated value that chooses the type of scanning we will perform.
 @param overrideUsername      NSString depicting a username to override for authentication. Both the username and the password must be simultaneously overridden for these parameters to be used for
 authentication with the API.
 @param overridePassword      NSString depicting a password to override for authentication. Both the username and the password must be simultaneously overridden for these parameters to be used for
 authentication with the API.
 @param overrideUrlPrefix     NSString depicting a urlPrefix to override at runtime. Passing this at runtime will override whatever is set in the plist configuration file, even if it is nil.
 @param progressHandler       Asynchronous block that returns upload progress of the document being uploaded for UI purposes
 @param completionHandler     Asynchronous block that returns either the response of the server, or an error
 */
+ (void)submitDocument:(nonnull UIImage *)documentImage
          documentType:(IDSEnterpriseDocumentType)documentType
      overrideUsername:(nonnull NSString *)overrideUsername
      overridePassword:(nonnull NSString *)overridePassword
     overrideUrlPrefix:(nonnull NSString *)overrideUrlPrefix
              progress:(void (^_Nullable)(NSProgress *_Nonnull uploadProgress))progressHandler
            completion:(void (^_Nonnull)(IDSEnterpriseResponse *_Nullable response, NSError *_Nullable error))completionHandler;

/**
 Method that allows the user to submit an identity document to the enterprise server with the ability to construct request with custom data


 @param constructingBlock A block that takes a single argument and appends custom data for sending request.
 @param progressHandler Asynchronous block that returns upload progress of the document being uploaded for UI purposes
 @param completionHandler Asynchronous block that returns either the response of the server, or an error
 */
+ (void)submitDocumentConstructingWithBlock:(void (^_Nonnull)(IDSEnterpriseSendRequest *_Nonnull request))constructingBlock
                                   progress:(void (^_Nullable)(NSProgress *_Nonnull uploadProgress))progressHandler
                                 completion:(void (^_Nonnull)(IDSEnterpriseResponse *_Nullable response, NSError *_Nullable error))completionHandler;

/**
 Method that allows the user to get further details on a scanned journey. This method could return metadata for multiple image scans, but all related to one specific scan referenced journey.

 @param referenceNumber The scan reference number that you want to search by.
 @param overrideUsername String depicting a username to override for authentication. Both the username and the password must be simultaneously overridden for these parameters to be used for
 authentication with the API.
 @param overridePassword String depicting a password to override for authentication. Both the username and the password must be simultaneously overridden for these parameters to be used for
 authentication with the API.
 @param overrideUrlPrefix String depicting a urlPrefix to override at runtime. Passing this at runtime will override whatever is set in the plist configuration file, even if it is nil.
 @param progressHandler   Asynchronous block that returns download progress for the request being made.
 @param completionHandler Asynchronous block that returns either the response of the server, or an error
 */
+ (void)getDetails:(nonnull NSString *)referenceNumber
  overrideUsername:(nonnull NSString *)overrideUsername
  overridePassword:(nonnull NSString *)overridePassword
 overrideUrlPrefix:(nonnull NSString *)overrideUrlPrefix
          progress:(void (^_Nullable)(NSProgress *_Nonnull downloadProgress))progressHandler
        completion:(void (^_Nonnull)(IDSEnterpriseDetailResponse *_Nullable response, NSError *_Nullable error))completionHandler DEPRECATED_MSG_ATTRIBUTE("getDetails method is deprecated. It is highly unrecommended to use it.");;

@end
