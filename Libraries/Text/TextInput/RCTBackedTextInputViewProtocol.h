/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import <UIKit/UIKit.h>

@protocol RCTBackedTextInputDelegate;
@class RCTTextAttributes;

NS_ASSUME_NONNULL_BEGIN

@protocol RCTBackedTextInputViewProtocol <UITextInput>

@property (nonatomic, strong, nullable) UIColor *textColor; // TODO: T57162853 Merge with `defaultTextAttributes`.
@property (nonatomic, strong, nullable) UIFont *font; // TODO: T57162853 Merge with `defaultTextAttributes`.
@property (nonatomic, copy, nullable) NSAttributedString *attributedText;
@property (nonatomic, copy, nullable) NSString *placeholder;
@property (nonatomic, strong, nullable) UIColor *placeholderColor;
@property (nonatomic, assign) NSTextAlignment textAlignment; // TODO: T57162853 Merge with `defaultTextAttributes`.
@property (nonatomic, assign, readonly) BOOL textWasPasted;
@property (nonatomic, assign) UIEdgeInsets textContainerInset;
@property (nonatomic, strong, nullable) UIView *inputAccessoryView;
@property (nonatomic, weak, nullable) id<RCTBackedTextInputDelegate> textInputDelegate;
@property (nonatomic, readonly) CGSize contentSize;
@property (nonatomic, strong, nullable) NSDictionary<NSAttributedStringKey,id> *defaultTextAttributes;
@property (nonatomic, assign) BOOL contextMenuHidden;
@property (nonatomic, assign, getter=isEditable) BOOL editable;
@property (nonatomic, assign) BOOL caretHidden;
@property (nonatomic, assign) BOOL enablesReturnKeyAutomatically;
@property (nonatomic, assign) UITextFieldViewMode clearButtonMode;
@property (nonatomic, getter=isScrollEnabled) BOOL scrollEnabled;

// This protocol disallows direct access to `selectedTextRange` property because
// unwise usage of it can break the `delegate` behavior. So, we always have to
// explicitly specify should `delegate` be notified about the change or not.
// If the change was initiated programmatically, we must NOT notify the delegate.
// If the change was a result of user actions (like typing or touches), we MUST notify the delegate.
- (void)setSelectedTextRange:(nullable UITextRange *)selectedTextRange NS_UNAVAILABLE;
- (void)setSelectedTextRange:(nullable UITextRange *)selectedTextRange notifyDelegate:(BOOL)notifyDelegate;

// This protocol disallows direct access to `text` property because
// unwise usage of it can break the `attributeText` behavior.
// Use `attributedText.string` instead.
@property (nonatomic, copy, nullable) NSString *text NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
