
#import "ViewController.h"
#import "SuntengAnalyticsSDK.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    self.navigationItem.title = @"首页";
}

#pragma mark - 进入、退出页面统计

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    [[SuntengAnalyticsSDK sharedInstance] enterPage:@"首页"];
}

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    [[SuntengAnalyticsSDK sharedInstance] exitPage:@"首页"];
}

#pragma mark - 事件统计

- (IBAction)addEvent:(UIButton *)sender {
    [[SuntengAnalyticsSDK sharedInstance] eventWithCategory:@"分类"
                                                     action:@"事件"
                                                      label:@"标签"
                                                      value:8.88];
}

@end
