#import <UIKit/UIKit.h>


// Typedef's
typedef NS_ENUM(NSInteger, SettingsTextModes) {
    SettingsTextModesText,
    SettingsTextModesEmail,
    SettingsTextModesPassword
};

typedef void (^SettingsTextAction)(void);
typedef void (^SettingsTextChanged)(NSString * _Nonnull);

/// Reusable component that renders a UITextField + Hint onscreen. Useful for Text / Password / Email data entry.
///
@interface SettingsTextViewController : UITableViewController

/// Block to be executed on dismiss, if the value was effectively updated.
///
@property (nullable, nonatomic, copy) SettingsTextChanged onValueChanged;

/// Block to be executed whenever the Action, if visible, is pressed.
///
@property (nullable, nonatomic, copy) SettingsTextAction onActionPress;

/// Specifies the Notice Message that should be displayed on top of the table.
///
@property (nullable, nonatomic, copy) NSString *notice;

/// Specifies the Action Button Text. If visible.
///
@property (nullable, nonatomic, copy) NSString *actionText;

/// Indicates whether an action button should be displayed at the bottom, or not.
///
@property (nonatomic, assign) BOOL displaysActionButton;

/// Specifies whether we should display navigation buttons (Cancel / Done) or not.
///
@property (nonatomic, assign) BOOL displaysNavigationButtons;

/// Sets the Text Input Mode:
///
/// - SettingsTextModesText: Default mode
/// - SettingsTextModesEmail: Will perform Email validation before hitting the callback.
/// - SettingsTextModesPassword: Secure Text Entry is enabled.
///
@property (nonatomic, assign) SettingsTextModes mode;

/// Required initializer.
///
/// Parameters:
///  - text: The raw string (current value) to edit.
///  - placeholder: Placeholder string to be displayed, in case the text is empty.
///  - hint: String to be displayed at the bottom.
///
- (nonnull instancetype)initWithText:(NSString * __nullable)text
                         placeholder:(NSString * __nullable)placeholder
                                hint:(NSString * __nullable)hint;

@end
