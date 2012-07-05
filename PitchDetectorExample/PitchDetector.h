/*
 Copyright (c) Kevin P Murphy June 2012
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#import <Foundation/Foundation.h>

@protocol PitchDetectorDelegate <NSObject>
- (void) updatedPitch: (float) frequency;
@end

@class AudioController;

@interface PitchDetector : NSObject
{
    float *hann, *result;
    SInt16 *sampleBuffer;
    int samplesInSampleBuffer;
    int bufferLength;
    int windowLength;
}

@property (nonatomic) BOOL running;
@property (nonatomic, assign) id<PitchDetectorDelegate> delegate;
@property int hiBoundFrequency, lowBoundFrequency;
@property float sampleRate;

//Optional Init Method (calls the second init method but sets the frequency bounds to default values)
-(id) initWithSampleRate: (float) rate andDelegate: (id<PitchDetectorDelegate>) initDelegate; 
-(id) initWithSampleRate: (float) rate lowBoundFreq: (int) low hiBoundFreq: (int) hi andDelegate: (id<PitchDetectorDelegate>) initDelegate;
- (void) addSamples: (SInt16*) samples inNumberFrames: (int) frames;


@end
