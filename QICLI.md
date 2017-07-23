#Nao API - qicli Info

This is a small guide to the methods used by the qicli utility on the Nao Robot.

Methods are listed Alphabetically, rather than by their number in the API.

Usage: 

'$ qicli info <module_number>'

Returns a list of methods relating to the module.

'$ qicli call <module_number>.<method_number> <args>'

Calls a method.

# Getting information on specific methods 

'$ qicli call 27.106 'fadeRGB'
ALLeds.getMethodHelp: [ "fadeRGB", "Sets the color of an RGB led.", [ [ "name", "The name of the LED or Group." ], [ "red", "the intensity of red channel (0-1)." ], [ "green", "the intensity of green channel (0-1)." ], [ "blue", "the intensity of blue channel (0-1)." ], [ "duration", "Time used to fade in seconds." ] ], "", "" ] '
 
*62  [ALAnimatedSpeech]
*48  [ALAudioDevice]
*51  [ALAudioPlayer]
*50  [ALAudioRecorder]
*112 [ALAudioSourceLocalization]
*53  [ALAutomaticVolume]
*202 [ALAutonomousLife]
*120 [ALAutonomousMoves]
*36  [ALBacklightingDetection]
*89  [ALBarcodeReader]
*116 [ALBasicAwareness]
*55  [ALBattery]
*61  [ALBehaviorManager]
*20  [ALBodyTemperature]
*65  [ALBonjour]
*56  [ALChestButton]
*30  [ALColorBlobDetection]
*44  [ALConnectionManager]
*35  [ALDarknessDetection]
*10  [ALDebug]
*16  [ALDiagnosis]
*221 [ALDialog]
*92  [ALEngagementZones]
*100 [ALFaceCharacteristics]
*32  [ALFaceDetection]
*25  [ALFaceTracker]
*104 [ALFastPersonTracking]
*3   [ALFileManager]
*106 [ALFindPersonHead]
*8   [ALFrameManager]
*18  [ALFsr]
*95  [ALGazeAnalysis]
*66  [ALInfrared]
*34  [ALLandMarkDetection]
*60  [ALLaser]
*59  [ALLauncher]
*27  [ALLeds]
*84  [ALLocalization]
*5   [ALLogger]
*57  [ALMecaLogger]
*4   [ALMemory]
*63  [ALMemoryWatcher]
*46  [ALModularity]
*21  [ALMotion]
*26  [ALMotionRecorder]
*90  [ALMovementDetection]
*64  [ALNavigation]
*11  [ALNotificationManager]
*85  [ALPanoramaCompass]
*91  [ALPeoplePerception]
*37  [ALPhotoCapture]
*7   [ALPreferenceManager]
*6   [ALPreferences]
*58  [ALPythonBridge]
*31  [ALRedBallDetection]
*24  [ALRedBallTracker]
*14  [ALResourceManager]
*86  [ALRobotHealthMonitor]
*15  [ALRobotModel]
*23  [ALRobotPosture]
*19  [ALSensors]
*9   [ALServiceManager]
*93  [ALSittingPeopleDetection]
*17  [ALSonar]
*108 [ALSoundDetection]
*111 [ALSoundLocalization]
*54  [ALSpeechRecognition]
*49  [ALStore]
*41  [ALSystem]
*67  [ALTelepathe]
*52  [ALTextToSpeech]
*22  [ALTouch]
*83  [ALTracker]
*43  [ALUserSession]
*29  [ALVideoDevice]
*38  [ALVideoRecorder]
*33  [ALVisionRecognition]
*39  [ALVisualCompass]
*40  [ALVisualSpaceHistory]
*45  [ALVolumeSlider]
*28  [ALWorldRepresentation]
*47  [AudioFilterLoader]
*12  [DCM]
*2   [LogManager]
*42  [PackageManager]
*1   [ServiceDirectory]