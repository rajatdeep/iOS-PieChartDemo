//
//  RJPieChart.h
//  RJPieChart
//
//  Created by Rajat Deep Singh on 3/13/15.
//  Copyright (c) 2015 Rajat Deep Singh. All rights reserved.
//

#import <UIKit/UIKit.h>

@class RJPieChart;
@protocol RJPieChartDataSource <NSObject>
@required
- (NSUInteger)numberOfSlicesInPieChart:(RJPieChart *)pieChart;
- (CGFloat)pieChart:(RJPieChart *)pieChart valueForSliceAtIndex:(NSUInteger)index;
@optional
- (UIColor *)pieChart:(RJPieChart *)pieChart colorForSliceAtIndex:(NSUInteger)index;
- (NSString *)pieChart:(RJPieChart *)pieChart textForSliceAtIndex:(NSUInteger)index;
@end

@protocol RJPieChartDelegate <NSObject>
@optional
- (void)pieChart:(RJPieChart *)pieChart willSelectSliceAtIndex:(NSUInteger)index;
- (void)pieChart:(RJPieChart *)pieChart didSelectSliceAtIndex:(NSUInteger)index;
- (void)pieChart:(RJPieChart *)pieChart willDeselectSliceAtIndex:(NSUInteger)index;
- (void)pieChart:(RJPieChart *)pieChart didDeselectSliceAtIndex:(NSUInteger)index;
@end

@interface RJPieChart : UIView <RJPieChartDelegate, RJPieChartDataSource>

@property(nonatomic, strong) id<RJPieChartDataSource> dataSource;
@property(nonatomic, strong) id<RJPieChartDelegate> delegate;
@property(nonatomic, assign) CGFloat startPieAngle;
@property(nonatomic, assign) CGFloat animationSpeed;
@property(nonatomic, assign) CGPoint pieCenter;
@property(nonatomic, assign) CGFloat pieRadius;
@property(nonatomic, assign) BOOL    showLabel;
@property(nonatomic, strong) UIFont  *labelFont;
@property(nonatomic, strong) UIColor *labelColor;
@property(nonatomic, strong) UIColor *labelShadowColor;
@property(nonatomic, assign) CGFloat labelRadius;
@property(nonatomic, assign) CGFloat selectedSliceStroke;
@property(nonatomic, assign) CGFloat selectedSliceOffsetRadius;
@property(nonatomic, assign) BOOL    showPercentage;
- (id)initWithFrame:(CGRect)frame Center:(CGPoint)center Radius:(CGFloat)radius;
- (void)reloadData;
- (void)setPieBackgroundColor:(UIColor *)color;

- (void)setSliceSelectedAtIndex:(NSInteger)index;
- (void)setSliceDeselectedAtIndex:(NSInteger)index;

//My methods
- (void)renderInLayer:(RJPieChart *)layerHostingView dataArray:(NSMutableArray*)dataArray;

- (void)customizeDraw:(RJPieChart*)pieChart
              pieCentre:(CGPoint)pieCentre
            animationSpeed:(CGFloat)speed
            labelRadius:(CGFloat)labelRadius;

-(void)drawLegends:(RJPieChart *)layerHostingView dataArray:(NSMutableArray*)dataArray;

@property (nonatomic ,retain) NSMutableArray *RJDataArray;
@property (nonatomic, retain) NSMutableArray *RJColorsArray;
@property (nonatomic, retain) RJPieChart *RJPieChartView;

@end;
