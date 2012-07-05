Pitch-Detector xCode Example:

This is the pitch detection algorithm that I use in my free app: Musician's Kit (available on the iTunes App Store). I created this autocorrelation function and I wanted to help out beginners by pulblishing it online.

The AudioController object is a singleton (it's only created once everytime the app is opened) and has a delegate protocol that allows you to send the microphone input to any object in your program using - (void) receivedAudioSamples:(SInt16*) samples length:(int) len;

When your delegate receives the samples, it can analyze the frequency of that sound by calling the method addSamples:inNumberFrames: on the PitchDetector. The PitchDetector object also defines a delegate protocol which notifies the delegate when frequency content has been found.

If you have any questions, you can email me at musicianskit@kevmdev.com

Happy Coding!