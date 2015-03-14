//
//  ViewController.m
//  PieChartTest
//
//  Created by Rajat Deep Singh on 3/13/15.
//  Copyright (c) 2015 Rajat Deep Singh. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

@synthesize pieChartView;

- (void)viewDidLoad
{
    [super viewDidLoad];
	
    NSMutableArray *dataArray = [NSMutableArray arrayWithCapacity:10];
    
    for(int i = 0; i < 8; i ++)
    {
        //Generate Random Number
        NSNumber *one = [NSNumber numberWithInt:rand()%60+20];
        [dataArray addObject:one];
    }
    
    // Pass View for Array with array to get a pie chart
    [self.pieChartView renderInLayer:self.pieChartView dataArray:dataArray];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
