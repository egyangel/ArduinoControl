//
//  MPViewController.m
//  ArduinoControl
//
//  Created by iCracker on 21/10/12.
//  Copyright (c) 2012 mpow. All rights reserved.
//

#import "MPViewController.h"
#import "extern.h"

@interface MPViewController ()

@end

@implementation MPViewController
-(id)init {
	self = [super init];
	if (self) {
		// Set the title for this view controller
		// Note: In future we will copy over the title from any created UINavigationBar objects
		self.title = @"On Off";

        
	}
	return self;
}

- (void)viewDidLoad
{

    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


-(IBAction)goSettings{
    
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"MainStoryboard" bundle:nil];
    UIViewController *settings = [storyboard instantiateViewControllerWithIdentifier:@"settings"];
    [settings setModalPresentationStyle:UIModalPresentationFullScreen];
    
    [self presentViewController:settings animated:YES completion:NULL];
}

-(IBAction)url1{
    UIWebView *webView1 = [[UIWebView alloc] init];
    NSURL *webURL = [NSURL URLWithString:firstUrl];
    NSURLRequest *webURLRequest = [NSURLRequest requestWithURL:webURL];
    [webView1 loadRequest:webURLRequest];
    [webView1 setScalesPageToFit:NO];
    [webView1 setFrame:CGRectMake(0, 0, 0, 0)];
    [self.view addSubview:webView1];


}


-(IBAction)url2{
    UIWebView *webView1 = [[UIWebView alloc] init];
    NSURL *webURL = [NSURL URLWithString:secondUrl];
    NSURLRequest *webURLRequest = [NSURLRequest requestWithURL:webURL];
    [webView1 loadRequest:webURLRequest];
    [webView1 setScalesPageToFit:NO];
    [webView1 setFrame:CGRectMake(0, 0, 0, 0)];
    [self.view addSubview:webView1];
    
    
}
@end
