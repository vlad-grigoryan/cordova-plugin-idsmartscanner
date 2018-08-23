/* IDSmartScanner.m */

#import "IDSmartScanner.h"
#import <Cordova/CDV.h>
@import IDSmart;

typedef NS_ENUM(NSInteger, ScanningPhase) {
    /// Depicts journey phase when capturing front of the document
    ScanningPhaseFront = 0,
    
    /// Depicts journey phase when capturing back of the document
    ScanningPhaseBack,
    
    /// Depicts journey phase when capturing selfie photo
    ScanningPhaseSelfie,
    
    /// Depicts journey phase when capturing address document
    ScanningPhaseAddressDocument
};

////////////////////////////////////////////////////////////////////////////
@implementation UIImage (IDSImage)
- (UIImage *)fixToLandscape {
    if (self == UIImageOrientationUp)
        return self;
    
    UIGraphicsBeginImageContextWithOptions(self.size, NO, self.scale);
    [self drawInRect:(CGRect){0, 0, self.size}];
    UIImage *normalizedImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    return normalizedImage;
}
@end

////////////////////////////////////////////////////////////////////////////
/// https://gist.github.com/software-mariodiana/f69f238cbd0dbbb47e8da7381152729e
@implementation NSDate (Json)
- (NSString *)xyz_jsonDate {
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setTimeZone:[NSTimeZone timeZoneWithName:@"UTC"]];
    [dateFormatter setDateFormat:@"yyyy-MM-dd'T'HH:mm:ssZZZZZ"];
    return [dateFormatter stringFromDate:self];
}
@end

////////////////////////////////////////////////////////////////////////////
///https://stackoverflow.com/questions/13810875/inserting-nil-objects-into-an-nsdictionary
static id ObjectOrNull(id object) {
    return object ?: [NSNull null];
}

////////////////////////////////////////////////////////////////////////////
static id DateStringOrNull( NSDate * _Nullable date) {
    return date ? [date xyz_jsonDate] : [NSNull null];
}

////////////////////////////////////////////////////////////////////////////
///https://stackoverflow.com/questions/6127638/nsarray-equivalent-of-map
@implementation NSArray (Map)
- (NSArray *)mapObjectsUsingBlock:(id (^)(id obj, NSUInteger idx))block {
    NSMutableArray *result = [NSMutableArray arrayWithCapacity:[self count]];
    [self enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
        [result addObject:block(obj, idx)];
    }];
    return result;
}
@end

////////////////////////////////////////////////////////////////////////////
///https://stackoverflow.com/questions/19873038/how-to-convert-a-objective-c-class-into-json-object
@implementation IDSEnterpriseResponse (ConversionToJSON)
- (NSDictionary *)convertSelfToDictionary {
    return @{
             @"scanResult" :                  [[NSNumber alloc] initWithInteger:self.scanResult],
             @"highLevelResult" :             [[NSNumber alloc] initWithInteger:self.highLevelResult],
             @"requiredAction" :              ObjectOrNull(self.requiredAction),
             @"branchCode" :                  ObjectOrNull(self.branchCode),
             @"customerNumber" :              ObjectOrNull(self.customerNumber),
             @"documentType" :                ObjectOrNull(self.documentType),
             @"extractedFields" :             ObjectOrNull(self.extractedFields),
             @"scanReason" :                  ObjectOrNull(self.scanReason),
             @"scanReference" :               ObjectOrNull(self.scanReference),
             @"scanUsername" :                ObjectOrNull(self.scanUsername),
             @"scanDateTime" :                DateStringOrNull(self.scanDateTime),
             @"journeyID" :                   ObjectOrNull(self.journeyID),
             @"identityMeansID" :             ObjectOrNull(self.identityMeansID),
             @"requestID" :                   ObjectOrNull(self.requestID),
             @"authenticationResultDetails" : ObjectOrNull(self.authenticationResultDetails),
             @"responsePayload" :             ObjectOrNull(self.responsePayload)
             };
}
@end

@implementation IDSEnterpriseProcessedDocumentField (ConversionToJSON)
- (NSDictionary *)convertSelfToDictionary {
    return @{
             @"boundsHeight" :        ObjectOrNull(self.boundsHeight),
             @"boundsSource" :        ObjectOrNull(self.boundsSource),
             @"boundsWidth" :         ObjectOrNull(self.boundsWidth),
             @"boundsXPosition" :     ObjectOrNull(self.boundsXPosition),
             @"boundsYPosition" :     ObjectOrNull(self.boundsYPosition),
             @"documentSide" :        [[NSNumber alloc] initWithInteger:self.documentSide],
             @"identityMeansScanID" : ObjectOrNull(self.identityMeansScanID),
             @"name" :                ObjectOrNull(self.name),
             @"value" :               ObjectOrNull(self.value)
             };
}
@end

@implementation IDSEnterpriseProcessedDocument (ConversionToJSON)
- (NSDictionary *)convertSelfToDictionary {
    return @{
             @"countryCode" :             ObjectOrNull(self.countryCode),
             @"countryName" :             ObjectOrNull(self.countryName),
             @"documentCategory" :        ObjectOrNull(self.documentCategory),
             @"documentImages" :          ObjectOrNull(self.documentImages),
             @"documentName" :            ObjectOrNull(self.documentName),
             @"documentNumber" :          ObjectOrNull(self.documentNumber),
             @"documentType" :            ObjectOrNull(self.documentType),
             @"expiryDate" :              DateStringOrNull(self.expiryDate),
             @"extractedFields" :         [self.extractedFields mapObjectsUsingBlock:^id(id obj, NSUInteger idx) {
                 IDSEnterpriseProcessedDocumentField *extractedField = (IDSEnterpriseProcessedDocumentField *) obj;
                 return [extractedField convertSelfToDictionary];
             }],///@"NSArray<IDSEnterpriseProcessedDocumentField *>",
             @"highLevelResult" :         [[NSNumber alloc] initWithInteger:self.highLevelResult],
             @"isRecognized" :            [[NSNumber alloc] initWithBool:self.isRecognized],
             @"issueDate" :               DateStringOrNull(self.issueDate),
             @"page" :                    [[NSNumber alloc] initWithInteger:self.page],
             @"processFinishedDateTime" : DateStringOrNull(self.processFinishedDateTime),
             @"processStartedDateTime" :  DateStringOrNull(self.processStartedDateTime),
             @"side" :                    [[NSNumber alloc] initWithInteger:self.side],
             @"subtype" :                 ObjectOrNull(self.subtype),
             @"workflowAttempt" :         [[NSNumber alloc] initWithInteger:self.workflowAttempt]
             };
}
@end

@implementation IDSEnterpriseDetailResponse (ConversionToJSON)
- (NSDictionary *)convertSelfToDictionary {
    return @{
             @"additionalData" :         ObjectOrNull(self.additionalData),
             @"age" :                    [[NSNumber alloc] initWithInteger:self.age],
             @"entryDateTime" :          DateStringOrNull(self.entryDateTime),
             @"evaluatedPersonEntryID" : ObjectOrNull(self.evaluatedPersonEntryID),
             @"firstName" :              ObjectOrNull(self.firstName),
             @"fullName" :               ObjectOrNull(self.fullName),
             @"gender" :                 ObjectOrNull(self.gender),
             @"highLevelResult" :        [[NSNumber alloc] initWithInteger:self.highLevelResult],
             @"lastName" :               ObjectOrNull(self.lastName),
             @"personProfileID" :        ObjectOrNull(self.personProfileID),
             @"processedDocuments" :     [self.processedDocuments mapObjectsUsingBlock:^id(id obj, NSUInteger idx) {
                 IDSEnterpriseProcessedDocument *processedDocument = (IDSEnterpriseProcessedDocument *) obj;
                 return [processedDocument convertSelfToDictionary];
             }],///@"NSArray<IDSEnterpriseProcessedDocument *>",
             @"referenceNumber" :        ObjectOrNull(self.referenceNumber),
             @"scanReason" :             ObjectOrNull(self.scanReason)
             };
}
@end

////////////////////////////////////////////////////////////////////////////
@implementation NSError (ConversionToJSON)
- (NSDictionary *)convertSelfToDictionary {
    return @{
             @"code" :                [[NSNumber alloc] initWithInteger:self.code],
             @"localizedDescription" : ObjectOrNull(self.localizedDescription)
             };
}
@end
////////////////////////////////////////////////////////////////////////////

@interface IDSmartScanner() <IDSDocumentScannerControllerDelegate, UIImagePickerControllerDelegate, UINavigationControllerDelegate>
/// credentials
@property (nonatomic, strong) NSString *urlPrefix;
@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong) NSString *password;
/// scanning response
@property (nonatomic, assign) BOOL credentialsHasBeenRetrieved;
@property (nonatomic, strong) IDSEnterpriseResponse *lastDocumentScanResponse;
@property (nonatomic, strong) NSError               *lastDocumentScanResponseError;

@property (nonatomic, strong) IDSEnterpriseDetailResponse *detailResponse;
@property (nonatomic, strong) NSError                     *detailResponseError;
/// scanning result
@property (nonatomic, strong) NSDictionary *scanningResult;
///
@property (nonatomic, strong) IDSEnterpriseCredentials *credentials;
@property (nonatomic, assign) ScanningPhase scanningPhase;

/// store plugin command
@property (nonatomic, strong) CDVInvokedUrlCommand *command;
@end

@implementation IDSmartScanner

static NSString *const kUrlPrefixKey = @"urlPrefix";
static NSString *const kUsernameKey = @"username";
static NSString *const kPasswordKey = @"password";

#pragma mark - cordova main method

- (void)scan:(CDVInvokedUrlCommand*)command
{
    _command = command;
    
    if (command.arguments.count < 1) {
        [self returnCredentialsError];
    }
    
    BOOL success = [self trySetupCredentialsFrom:command.arguments[0]];
    
    if (success) {
        [self openCamera];
    } else {
        [self returnCredentialsError];
    }
    
}

#pragma mark - credentials error

- (void) returnCredentialsError {
    [self returnScanningResultWithError:YES];
}

#pragma mark - credentials setup

- (BOOL)trySetupCredentialsFrom:(NSDictionary *)credentials {
    
    NSLog(@"Credentials %@", credentials);
    
    NSString* urlPrefix = credentials[kUrlPrefixKey];
    NSString* username = credentials[kUsernameKey];
    NSString* password = credentials[kPasswordKey];

    BOOL URLPrefixFailure = (urlPrefix == nil || [urlPrefix length] == 0);
    BOOL usernameFailure = (username == nil || [username length] == 0);
    BOOL passwordFailure = (password == nil || [password length] == 0);
    
    if (!URLPrefixFailure && !usernameFailure && !passwordFailure)
    {
        _urlPrefix = urlPrefix;
        _username = username;
        _password = password;
        
        _credentialsHasBeenRetrieved = YES;
        
        return YES;
    }
    
    return NO;
}


#pragma mark - web driven journey

- (void)openNativeCameraFront:(BOOL)front {
    UIImagePickerController *imagePicker = [[UIImagePickerController alloc] init];
    imagePicker.delegate = self;
    imagePicker.sourceType = UIImagePickerControllerSourceTypeCamera;
    imagePicker.cameraDevice = front? UIImagePickerControllerCameraDeviceFront:UIImagePickerControllerCameraDeviceRear;
    [self.viewController presentViewController:imagePicker animated:YES completion:nil];
}

- (void)openCamera {
    
    //    UIImage *img = [UIImage imageNamed:@"cameraOutput.png"];
    //    [self sendImage:img];
    
    IDSDocumentScannerController *controller = [self scannerControllerWithOptions:nil];
    [self.viewController presentViewController:controller animated:YES completion:nil];
}

#pragma mark - Getters

- (IDSEnterpriseCredentials *)credentials {
    if (!_credentials) {
        // If token specified, we skip username/password authentication
//        if (kToken.length > 0) {
//            _credentials = [[IDSEnterpriseCredentials alloc] initWithToken:kToken urlPrefix:kURLPrefix area:IDSEnterpriseAuthenticationAreaScanning];
//        } else {
            _credentials = [[IDSEnterpriseCredentials alloc] initWithUsername:_username password:_password urlPrefix:_urlPrefix area:IDSEnterpriseAuthenticationAreaScanning];
//        }
    }
    return _credentials;
}

- (IDSDocumentScannerController*)scannerControllerWithOptions:(NSDictionary*)options {
    IDSDocumentScannerController *controller = [[IDSDocumentScannerController alloc] initWithScannerType:IDSDocumentScannerControllerTypeDocument options:options];
    controller.delegate = self;
    return controller;
}

#pragma mark - Web Service Method

- (void)sendImage:(UIImage*)image {
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"Please wait" message:@"Uploading the document..." preferredStyle:UIAlertControllerStyleAlert];
    [self.viewController presentViewController:alertController animated:YES completion:nil];
    
    [IDSEnterpriseService submitDocumentConstructingWithBlock:^(IDSEnterpriseSendRequest * _Nonnull request) {
        [request setCredentials:self.credentials];
        [request setDocumentSource:IDSEnterpriseDocumentTypeIdentity];
        
        // Check if selfie sending
        if (self.scanningPhase == ScanningPhaseSelfie) {
            [request addSelfieImage:image];
        } else {
            [request addDocument:image];
        }
        
        // Set proper source if it's address document
        if (self.scanningPhase == ScanningPhaseAddressDocument) {
            [request setDocumentSource:IDSEnterpriseDocumentTypeUtility];
        }
        
        // Set journeyID if we following the journey
        if (self.lastDocumentScanResponse) {
            [request setJourneyID:self.lastDocumentScanResponse.journeyID];
        }
        
    }  progress:nil
                                                   completion:^(IDSEnterpriseResponse * _Nullable response, NSError * _Nullable error) {
                                                       [alertController dismissViewControllerAnimated:YES completion:nil];
                                                       if (error) {
                                                           [self handleEnterpriseError:error];
                                                       } else {
                                                           [self handleEnterpriseResponse:response];
                                                       }
                                                   }];
}

- (void)handleEnterpriseResponse: (IDSEnterpriseResponse *)enterpriseResponse {
    _lastDocumentScanResponse = enterpriseResponse;
    
    /* Parse required action
     // It's possible that required action would ask to perform additional actions for current step, example ADDRESSDOCUMENT:SECONDSCAN
     */
    NSArray *actions = [enterpriseResponse.requiredAction componentsSeparatedByString:@":"];
    NSString *action = actions.firstObject;
    
    if ([action isEqualToString:kIDSEnterpriseRequiredActionSecondScan] ||
        [action isEqualToString:kIDSEnterpriseRequiredActionThirdScan]) {
        [self openCamera];
        [self displayCameraMessage:@"Please re-scan the document"];
    } else if ([action isEqualToString:kIDSEnterpriseRequiredActionScanBackside]) {
        _scanningPhase = ScanningPhaseBack;
        [self openCamera];
        [self displayCameraMessage:@"Please scan back side of the document"];
    } else if ([action isEqualToString:kIDSEnterpriseRequiredActionCaptureSelfie]) {
        _scanningPhase = ScanningPhaseSelfie;
        [self openNativeCameraFront:YES];
    } else if ([action isEqualToString:kIDSEnterpriseRequiredActionAddressDocument]) {
        _scanningPhase = ScanningPhaseAddressDocument;
        [self openNativeCameraFront:NO];
    } else {
        [self retrieveDetailResults:enterpriseResponse];
    }
}

- (void)handleEnterpriseError:(NSError *)error {
    _lastDocumentScanResponseError = error;
    
    UIAlertController *controller = [UIAlertController alertControllerWithTitle:nil message:error.localizedDescription preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *closeAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleCancel handler:nil];
    [controller addAction:closeAction];
    [self.viewController presentViewController:controller animated:YES completion:nil];
    
    [self returnScanningResultWithError:YES];
}

- (void)retrieveDetailResults:(IDSEnterpriseResponse *)enterpriseResponse {
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"Loading.." message:@"" preferredStyle:UIAlertControllerStyleAlert];
    [self.viewController presentViewController:alertController animated:YES completion:^{
        // Get journey results
        [IDSEnterpriseService getDetails:enterpriseResponse.scanReference overrideUsername:_username overridePassword:_password overrideUrlPrefix:_urlPrefix progress:nil
                              completion:^(IDSEnterpriseDetailResponse * _Nullable detailResponse, NSError * _Nullable error) {
                                  [alertController dismissViewControllerAnimated:YES completion:^{
                                      if (error) {
                                          [self handleDetailError:error];
                                      } else {
                                          [self handleDetailResponse:detailResponse];
                                      }
                                  }];
                              }];
    }];
}

- (void)handleDetailResponse: (IDSEnterpriseDetailResponse *)detailResponse {
    _detailResponse = detailResponse;
    [self returnScanningResultWithError:NO];
}

- (void)handleDetailError:(NSError *)error {
    _detailResponseError = error;
    
    UIAlertController *controller = [UIAlertController alertControllerWithTitle:nil message:error.localizedDescription preferredStyle:UIAlertControllerStyleAlert];
    UIAlertAction *closeAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleCancel handler:^(UIAlertAction *action){
        [self returnScanningResultWithError:NO];
    }];
    [controller addAction:closeAction];
    [self.viewController presentViewController:controller animated:YES completion:nil];
}


-(void)returnScanningResultWithError:(BOOL)isError {
    
    _scanningResult = @{
                        @"credentialsHasBeenRetrieved": [[NSNumber alloc]initWithBool:_credentialsHasBeenRetrieved],
                        @"enterpriseResult": ObjectOrNull([_lastDocumentScanResponse convertSelfToDictionary]),
                        @"enterpriseError": ObjectOrNull([_lastDocumentScanResponseError convertSelfToDictionary]),
                        @"detailResult": ObjectOrNull([_detailResponse convertSelfToDictionary]),
                        @"detailError": ObjectOrNull([_detailResponseError convertSelfToDictionary])
                        };
    
    NSLog(@"%@", _scanningResult);
    
    CDVCommandStatus status = (isError) ? CDVCommandStatus_ERROR : CDVCommandStatus_OK;
    CDVPluginResult*pluginResult = [CDVPluginResult resultWithStatus: status
                                                 messageAsDictionary:_scanningResult];
    [self.commandDelegate sendPluginResult:pluginResult callbackId:_command.callbackId];
}

#pragma mark - Actions

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary<NSString *, id> *)info {
    UIImage *image = [info[UIImagePickerControllerOriginalImage] fixToLandscape];
    
    [picker dismissViewControllerAnimated:YES
                               completion:^{
                                   if (_scanningPhase == ScanningPhaseAddressDocument) {
                                       IDSDocumentScannerController *controller = [self scannerControllerWithOptions:@{IDSDocumentScannerOptionImage:image}];
                                       [self.viewController presentViewController:controller animated:YES completion:nil];
                                   } else {
                                       [self sendImage:image];
                                   }
                               }];
}


- (void)displayCameraMessage:(NSString *)message {
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 2 * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
        [[NSNotificationCenter defaultCenter] postNotificationName:@"IDSAlertViewShowNotification"
                                                            object:nil
                                                          userInfo:@{
                                                                     @"title" : @"Capture the document",
                                                                     @"message" : message,
                                                                     @"dismissTime" : @0.0f,
                                                                     @"useVoice" : @(YES)
                                                                     }];
    });
}

#pragma mark - IDSDocumentScannerControllerDelegate Methods

- (void)documentScannerController:(IDSDocumentScannerController *)scanner didFailWithError:(NSError *)error {
    [scanner dismissViewControllerAnimated:YES
                                completion:^{ [[[UIAlertView alloc] initWithTitle:@"Error" message:error.localizedDescription delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show]; }];
}

- (void)documentScannerControllerDidCancel:(IDSDocumentScannerController *)scanner {
    [scanner dismissViewControllerAnimated:YES completion:^{
        if ([_lastDocumentScanResponse.requiredAction isEqualToString:kIDSEnterpriseRequiredActionSecondScan] ||
            [_lastDocumentScanResponse.requiredAction isEqualToString:kIDSEnterpriseRequiredActionThirdScan]) {
            self.lastDocumentScanResponse = nil;
        };
    }];
}

- (void)documentScannerController:(IDSDocumentScannerController *)scanner didFinishScanningWithInfo:(NSDictionary *)info {
    // Classification output
    IDSMetadataObject *metadata = info[IDSDocumentScannerInfoMetadataObject];
    UIImage *extractedImage = nil;
    if (!metadata) {
        extractedImage = info[IDSDocumentScannerInfoImage]; // if an image was manually captured, the image is all you get
    } else {                                                     // otherwise, the image is accompanied with some metadata
        if ([metadata isKindOfClass:[IDSMetadataClassificationObject class]]) {
            IDSMetadataClassificationObject *classificationMetadata = (IDSMetadataClassificationObject *) metadata;
            extractedImage = [UIImage imageWithCGImage:classificationMetadata.documentImage];
        } else if ([metadata isKindOfClass:[IDSMetadataMachineReadableZoneObject class]]) {
            IDSMetadataMachineReadableZoneObject *mrzMetadata = (IDSMetadataMachineReadableZoneObject *) metadata;
            extractedImage = [UIImage imageWithCGImage:mrzMetadata.documentImage];
        }
    }
    [scanner dismissViewControllerAnimated:YES completion:^{
        [self sendImage:extractedImage];
    }];
}

@end




