//
//  MPSettings.m
//  ArduinoControl
//
//  Created by iCracker on 21/10/12.
//  Copyright (c) 2012 mpow. All rights reserved.
//

#import "MPSettings.h"
#import "extern.h"
@interface MPSettings()


@end

@implementation MPSettings


- (void)viewDidLoad
{
    if (cont1==0) {
        [url1 setText:@"http://"];
        [url2 setText:@"http://"];
    }
    else{
    [url1 setText:firstUrl];
    [url2 setText:secondUrl];
    }
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(BOOL)textFieldShouldReturn:(UITextField *)textField{
    cont1++;
    firstUrl=[url1 text] ;
    
    secondUrl=[url2 text] ;
    
    [url1 setText:firstUrl];
    [url2 setText:secondUrl];

	[textField resignFirstResponder];
	return YES;
}


@end


