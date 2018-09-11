//
//  IDSEnterpriseInputImage.h
//  IDSWebServices
//
//  Created by Edvardas Maslauskas on 03/03/2017.
//  Copyright © 2017 IDscan Biometrics Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIImage.h>

/**
 Input image name const, used for visible image of the document
 */
extern NSString *const _Nonnull kIDSEnterpriseInputImageNameWhiteImage;

/**
 Input image name const, used for selfie photo
 */
extern NSString *const _Nonnull kIDSEnterpriseInputImageNameSelfiePhoto;
/**
 Enterprise API input image object, which is used to specify captured images for the request.
 */
@interface IDSEnterpriseInputImage : NSObject

/**
 Captured imge
 */
@property (nonatomic, nonnull, readonly) UIImage *image;

/**
 Captured image name, should specify type of the image
 */
@property (nonatomic, nonnull, readonly) NSString *name;

/**
 Constructor for IDSEnterpriseInputImage

 @param name  Captured image name, should specify type of the image
 @param image Captured image
 @return IDSEnterpriseInputImage object
 */
- (instancetype _Nonnull)initWithName:(NSString *_Nonnull)name image:(UIImage *_Nonnull)image;
@end
