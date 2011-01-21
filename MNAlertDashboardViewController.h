#import "MNAlertData.h"

#define kPendingActive 0
#define kSentActive 1
#define kDismissActive 2

@class MNAlertDashboardViewController;
@protocol MNAlertDashboardViewControllerProtocol
- (void)actionOnAlertAtIndex:(int)index inArray:(int)array;
- (NSMutableArray *)getPendingAlerts;
- (NSMutableArray *)getSentAwayAlerts;
- (NSMutableArray *)getDismissedAlerts;
@end

@interface MNAlertDashboardViewController : NSObject <UITableViewDelegate, UITableViewDataSource>
{
	UISegmentedControl *picker;
	UITableView *tableView;
	UIWindow *window;
	NSMutableArray *activeArrayReference;
	
	int activeArray;
	
	id <MNAlertDashboardViewControllerProtocol> _delegate;
}

-(void)toggleDashboard;
-(void)hideDashboard;
-(void)showDashboard;
-(void)activeArrayChanged:(id)sender;

@property (nonatomic, retain) UISegmentedControl *picker;
@property (nonatomic, retain) UITableView *tableView;
@property (nonatomic, retain) UIWindow *window;

@property (nonatomic, retain) id <MNAlertDashboardViewControllerProtocol> delegate;

@end