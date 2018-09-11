//
//  IDSBase.h
//  IDSmart SDK
//
//  Created by Stanislav Kozyrev <s.kozyrev@idscan.co.uk>.
//  Copyright (c) 2014 IDScan Biometrics Ltd. All rights reserved.
//

#ifndef IDSBASE_H_
#define IDSBASE_H_

#import <Availability.h>
#import <Foundation/Foundation.h>

#ifdef __cplusplus
#define IDS_EXTERN_C_BEGIN      extern "C" {
#define IDS_EXTERN_C_END        }
#else
#define IDS_EXTERN_C_BEGIN
#define IDS_EXTERN_C_END
#endif

#define IDS_STATIC_INLINE       static inline

#ifdef __cplusplus
#define IDSMART_EXPORT          extern "C" __attribute__((visibility ("default")))
#else
#define IDSMART_EXPORT          extern __attribute__((visibility ("default")))
#endif

#define IDSMART_HIDDEN          extern __attribute__((visibility("hidden")))

#define IDSMART_CLASS_EXPORT    __attribute__((visibility("default")))

/**
 SDK's error domain
 */
IDSMART_EXPORT NSString *const IDSmartErrorDomain;

/**
 IDSmartErrorCode Defines where you indicate the Error

 - IDSmartInvalidArgumentError: occurs when authentication Error, Invalid URL or nil image etc.
 - IDSmartInternalError: occurs when internal errors. E.g. When we fail to extract image or one of our modules fail.
 */
typedef NS_ENUM(NSUInteger, IDSmartErrorCode) {
    /// It occurs when authentication Error, Invalid URL or nil image etc.
    IDSmartInvalidArgumentError = 1,
    
    /// It occurs when internal errors. E.g. When we fail to extract image or one of our modules fail
    IDSmartInternalError
};

/**
 Application token used for licensing
 @deprecated The method is deprecated. First deprecated in v1.5.0
 */
IDSMART_EXPORT NSString *const IDSmartApplicationToken DEPRECATED_MSG_ATTRIBUTE("c");

#endif // #define IDSBASE_H_
