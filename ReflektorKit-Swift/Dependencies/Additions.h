//
// UIView+REFLAdditions.h
// ReflektorKit
//
// Created by Alex Usbergo on 22/04/15.
// Copyright (c) 2015 Alex Usbergo. All rights reserved.
//

#import <objc/runtime.h>

@import UIKit;

@interface UIView (REFLAdditions)

///Redirects to 'layer.cornerRadius'
@property (nonatomic, assign) CGFloat cornerRadius;

///Redirects to 'layer.borderWidth'
@property (nonatomic, assign) CGFloat borderWidth;

///Redirects to 'layer.borderColor'
@property (nonatomic, strong) UIColor *borderColor;

///Frame helper (self.frame.origin.x)
@property (nonatomic, assign) CGFloat x;

///Frame helper (self.frame.origin.y)
@property (nonatomic, assign) CGFloat y;

///Frame helper (self.frame.size.width)
@property (nonatomic, assign) CGFloat width;

///Frame helper (self.frame.size.height)
@property (nonatomic, assign) CGFloat height;

///The opacity of the shadow. Defaults to 0. Specifying a value outside the
@property (nonatomic, assign) CGFloat shadowOpacity;

///The blur radius used to create the shadow. Defaults to 3.
@property (nonatomic, assign) CGFloat shadowRadius;

///The shadow offset. Defaults to (0, -3)
@property (nonatomic, assign) CGSize shadowOffset;

///The color of the shadow. Defaults to opaque black.
@property (nonatomic, strong) UIColor *shadowColor;


- (BOOL)refl_hasKey:(NSString*)key;

@end

@interface UIScreen (RLFKAddtions)

@property (nonatomic, readonly) CGRect REFL_screenBounds;

@end

@interface UIButton (REFLAdditions)

//Symeetrical to  -[UIButton titleForState:]
@property (nonatomic, strong) NSString *text;
@property (nonatomic, strong) NSString *highlightedText;
@property (nonatomic, strong) NSString *selectedText;
@property (nonatomic, strong) NSString *disabledText;

//Symeetrical to  -[UIButton titleColorForState:]
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *highlightedTextColor;
@property (nonatomic, strong) UIColor *selectedTextColor;
@property (nonatomic, strong) UIColor *disabledTextColor;

@property (nonatomic, strong) UIColor *backgroundColor;

//Symmetrical to -[UIButton backgroundImageForState:]
@property (nonatomic, strong) UIImage *backgroundImage;
@property (nonatomic, strong) UIImage *highlightedBackgroundImage;
@property (nonatomic, strong) UIImage *selectedBackgroundImage;
@property (nonatomic, strong) UIImage *disabledBackgroundImage;

//Symmetrical to -[UIButton imageForState:]
@property (nonatomic, strong) UIImage *image;
@property (nonatomic, strong) UIImage *highlightedImage;
@property (nonatomic, strong) UIImage *selectedImage;
@property (nonatomic, strong) UIImage *disabledImage;

@end

@interface UIImage (REFL)

+ (UIImage*)REFL_imageWithColor:(UIColor*)color;
+ (UIImage*)REFL_imageWithColor:(UIColor*)color size:(CGSize)size;

@end

@interface NSObject (REFLAutoRemovalNotification)

@property (nonatomic, assign) BOOL REFL_observationAdded;

- (void)REFL_addObserverForName:(NSString*)name object:(id)obj queue:(NSOperationQueue*)queue usingBlock:(void (^)(NSNotification*note))block;
- (void)REFL_addObserverForName:(NSString*)name usingBlock:(void (^)(NSNotification*note))block;

@end

@interface NSObject (REFLAspects)
- (NSString*)refl_className;
- (Class)refl_class;
@end

@interface UIColor (HTMLColors)

+ (UIColor*)gradientFromColor:(UIColor*)color1 toColor:(UIColor*)color2 withSize:(CGSize)frame;
+ (UIColor*)refl_colorWithCSSColor:(NSString *)cssColor;
+ (UIColor*)colorWithHexString:(NSString *)hexColor;
+ (UIColor*)colorWithRGBString:(NSString *)rgbColor;
+ (UIColor*)colorWithHSLString:(NSString *)hslColor;
- (NSString*)hexStringValue;
- (NSString*)rgbStringValue;
- (NSString*)hslStringValue;

@end

@interface NSScanner (HTMLColors)
- (BOOL)scanLESSColor:(UIColor **)color;
- (BOOL)scanRGBColor:(UIColor **)color;
- (BOOL)scanHSLColor:(UIColor **)color;
- (BOOL)scanHexColor:(UIColor **)color;

@end

@interface UIEGradientColor : NSObject

- (instancetype)initWithColor1:(UIColor*)color1 color2:(UIColor*)color2;
- (UIColor*)gradientWithSize:(CGSize)size;

@end

@interface UIImage (REFLAdditions)

+ (UIImage*)REFL_imageWithColor:(UIColor*)color;
+ (UIImage*)REFL_imageWithColor:(UIColor*)color size:(CGSize)size;

@end

