//
//  IDSEnterpriseAdditionalDataEntry.h
//  IDSWebServices
//
//  Created by Edvardas Maslauskas on 03/03/2017.
//  Copyright © 2017 IDscan Biometrics Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Enterprise API additional data object, which is used to associate it with specific case
 */
@interface IDSEnterpriseAdditionalDataEntry : NSObject

/**
 Key for additional data
 */
@property (nonatomic, nonnull, readonly) NSString *name;

/**
 Value of additional data
 */
@property (nonatomic, nonnull, readonly) NSString *value;

/**
 Contructor for IDSEnterpriseAdditionalDataEntry

 @param name  Key for additional data
 @param value Value of additional data
 @return IDSEnterpriseAdditionalDataEntry object
 */
- (instancetype _Nonnull)initWithName:(NSString *_Nonnull)name value:(NSString *_Nonnull)value;
@end
