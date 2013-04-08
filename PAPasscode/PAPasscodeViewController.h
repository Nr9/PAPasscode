//
//  PAPasscodeViewController.h
//  PAPasscode
//
//  Created by Denis Hennessy on 15/10/2012.
//  Copyright (c) 2012 Peer Assembly. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    PasscodeActionSet,
    PasscodeActionEnter,
    PasscodeActionChange
} PasscodeAction;

@class PAPasscodeViewController;

typedef void (^ChallengeSucceedBlock)();
typedef void (^ChallengeCanceledBlock)();
typedef void (^ChallengeFailedBlock)(NSInteger attempts);
typedef BOOL (^ChallengeVerifyPasswordBlock)(NSString* entry);

@protocol PAPasscodeViewControllerDelegate <NSObject>

@optional

- (void)PAPasscodeViewControllerDidCancel:(PAPasscodeViewController *)controller;
- (void)PAPasscodeViewControllerDidChangePasscode:(PAPasscodeViewController *)controller;
- (void)PAPasscodeViewControllerDidEnterAlternativePasscode:(PAPasscodeViewController *)controller;
- (void)PAPasscodeViewControllerDidEnterPasscode:(PAPasscodeViewController *)controller;
- (void)PAPasscodeViewControllerDidSetPasscode:(PAPasscodeViewController *)controller;
- (void)PAPasscodeViewController:(PAPasscodeViewController *)controller didFailToEnterPasscode:(NSInteger)attempts;
- (BOOL)PAPasscodeViewController:(PAPasscodeViewController *)controller checkPasscodeValidityWithEntry:(NSString *)entry;
@end

@interface PAPasscodeViewController : UIViewController 

@property (strong) UIView *backgroundView;
@property (readonly) PasscodeAction action;
@property (weak) id<PAPasscodeViewControllerDelegate> delegate;
@property (strong) NSString *alternativePasscode;
@property (strong) NSString *passcode;
@property (assign) BOOL simple;
@property (assign) NSInteger failedAttempts;
@property (strong) NSString *enterPrompt;
@property (strong) NSString *confirmPrompt;
@property (strong) NSString *changePrompt;
@property (strong) NSString *message;
@property (strong) ChallengeSucceedBlock success;
@property (strong) ChallengeFailedBlock failure;
@property (strong) ChallengeCanceledBlock cancel;
@property (strong) ChallengeVerifyPasswordBlock verify;


- (instancetype)initForAction:(PasscodeAction)action;

- (instancetype)initForChallenge:(ChallengeSucceedBlock)success failure:(ChallengeFailedBlock)failure cancel:(ChallengeCanceledBlock)cancel verify:(ChallengeVerifyPasswordBlock)verify;

@end
