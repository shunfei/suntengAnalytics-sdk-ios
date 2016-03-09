
#import "SubViewController.h"
#import "SuntengAnalyticsSDK.h"

@interface SubViewController ()

@end

@implementation SubViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    self.navigationItem.title = @"第二页";
}

#pragma mark - 进入、退出页面统计

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    [[SuntengAnalyticsSDK sharedInstance] enterPage:@"第二页"];
}

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    [[SuntengAnalyticsSDK sharedInstance] exitPage:@"第二页"];
}

@end
